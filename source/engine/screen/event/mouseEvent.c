#include "eventInternal.h"

#define MAX_MOUSE_COUNT 6

static struct {
	mouseButtonEvent event;
	void* params;
	struct {
		bool wasPressed : 1;
	};
} globalMousePressedEventStorage;

static struct {
	mouseMoveEvent event;
	pointI2_t prevPos;
	void* params;
} globalMouseMovedEventStorage;

static struct {
	mouseScrollEvent event;
	void* params;
} globalMouseScrolledEventStorage;

struct mouseEvent {
	singleMouseButtonEvent event;
	void* params;
	struct {
		bool wasPressed : 1;
	};
};

struct mouseEvent* mouseEvents = NULL;

void initMouseEvents() {
	mouseEvents = calloc(MAX_MOUSE_COUNT, sizeof(struct mouseEvent));

	globalMousePressedEventStorage.event = NULL;
	globalMousePressedEventStorage.params = NULL;
	globalMousePressedEventStorage.wasPressed = false;

	globalMouseMovedEventStorage.event = NULL;
	globalMouseMovedEventStorage.prevPos = int2(0, 0);
	globalMouseMovedEventStorage.params = NULL;

	globalMouseScrolledEventStorage.event = NULL;
	globalMouseScrolledEventStorage.params = NULL;
}

void destroyMouseEvents() {
	free(mouseEvents);
	mouseEvents = NULL;

	globalMousePressedEventStorage.event = NULL;
	globalMousePressedEventStorage.params = NULL;
	globalMousePressedEventStorage.wasPressed = false;

	globalMouseMovedEventStorage.event = NULL;
	globalMouseMovedEventStorage.params = NULL;

	globalMouseScrolledEventStorage.event = NULL;
	globalMouseScrolledEventStorage.params = NULL;
}

bool mouseEventsInitialized() {
	return mouseEvents != NULL && SDL_WasInit(SDL_INIT_EVENTS);
}

eventRegisterResponse_t
registerSingleMouseClickEvent(unsigned char mouseButton, singleMouseButtonEvent event, void* param) {
	if (!mouseEventsInitialized())
		return EVENT_NOT_INITIALIZED;
	mouseButton--; // SDL_BUTTON variables are 1-6, needs to be zero based
	if (mouseButton >= MAX_MOUSE_COUNT)
		return EVENT_INVALID_PARAMETER;

	struct mouseEvent* mouseEvent = &mouseEvents[mouseButton];
	bool hadEvent = mouseEvent->event;

	mouseEvent->event = event;
	mouseEvent->params = param;
	mouseEvent->wasPressed = false;

	return hadEvent ? EVENT_OVERWRITTEN : EVENT_SUCCESS;
}

eventRegisterResponse_t registerGlobalMouseClickEvents(mouseButtonEvent event, void* param) {
	if (!mouseEventsInitialized())
		return EVENT_NOT_INITIALIZED;

	bool hadEvent = globalMousePressedEventStorage.event;
	globalMousePressedEventStorage.event = event;
	globalMousePressedEventStorage.params = param;
	return hadEvent ? EVENT_OVERWRITTEN : EVENT_SUCCESS;
}

eventRegisterResponse_t registerMouseMoveEvent(mouseMoveEvent event, void* param) {
	if (!mouseEventsInitialized())
		return EVENT_NOT_INITIALIZED;

	bool hadEvent = globalMouseMovedEventStorage.event;
	globalMouseMovedEventStorage.event = event;
	globalMouseMovedEventStorage.params = param;
	return hadEvent ? EVENT_OVERWRITTEN : EVENT_SUCCESS;
}

eventRegisterResponse_t registerMouseScrollEvent(mouseScrollEvent event, void* param) {
	if (!mouseEventsInitialized())
		return EVENT_NOT_INITIALIZED;

	bool hadEvent = globalMouseScrolledEventStorage.event;
	globalMouseScrolledEventStorage.event = event;
	globalMouseScrolledEventStorage.params = param;
	globalMouseMovedEventStorage.prevPos = getCurrentMousePos();
	return hadEvent ? EVENT_OVERWRITTEN : EVENT_SUCCESS;
}

void unregisterSingleMouseClickEvent(int mouseButton) {
	mouseButton--; // SDL_BUTTON variables are 1-6, needs to be zero based
	if (mouseEventsInitialized() && mouseButton < MAX_MOUSE_COUNT) {
		struct mouseEvent* mouseEvent = &mouseEvents[mouseButton];

		mouseEvent->event = NULL;
		mouseEvent->params = NULL;
		mouseEvent->wasPressed = false;
	}
}

void unregisterGlobalMouseClickEvents() {
	globalMousePressedEventStorage.event = NULL;
	globalMousePressedEventStorage.params = NULL;
	globalMousePressedEventStorage.wasPressed = false;
}

void unregisterMouseMoveEvent() {
	globalMouseMovedEventStorage.event = NULL;
	globalMouseMovedEventStorage.params = NULL;
	globalMouseMovedEventStorage.prevPos = int2(0, 0);
}

void unregisterMouseScrollEvent() {
	globalMouseScrolledEventStorage.event = NULL;
	globalMouseScrolledEventStorage.params = NULL;
}

void handleMouseEvent(SDL_Event event) {
	if (!mouseEventsInitialized())
		return;

	int button = event.button.button;
	struct mouseEvent* currentEvent = &mouseEvents[button - 1];

	switch (event.type) {
		case SDL_MOUSEBUTTONDOWN: {
			if (globalMousePressedEventStorage.event) {
				if (!globalMousePressedEventStorage.wasPressed)
					globalMousePressedEventStorage.wasPressed = globalMousePressedEventStorage.event(button,
																									 globalMousePressedEventStorage.params);
			} else if (currentEvent->event) {
				if (!currentEvent->wasPressed)
					currentEvent->wasPressed = currentEvent->event(currentEvent->params);
			}
			break;
		}
		case SDL_MOUSEBUTTONUP: {
			if (globalMousePressedEventStorage.event) {
				globalMousePressedEventStorage.event(SDL_BUTTON_NONE, globalMousePressedEventStorage.params);
				globalMousePressedEventStorage.wasPressed = false;
			} else {
				if (currentEvent->event) {
					currentEvent->wasPressed = false;
				} else if (button != SDL_BUTTON_NONE) {
					// SDL_BUTTON_NONE is a custom button and is not naturally supported by SDL
					// Mimicking release behaviour as a press of button SDL_BUTTON_NONE
					handleMouseEvent((SDL_Event) {
						.button.type = SDL_MOUSEBUTTONDOWN,
						.button.button = SDL_BUTTON_NONE});
				}
			}
			break;
		}
		case SDL_MOUSEMOTION: {
			pointI2_t currentPos = getCurrentMousePos();
			if (globalMouseMovedEventStorage.event)
				globalMouseMovedEventStorage.event(globalMouseMovedEventStorage.prevPos, currentPos,
												   globalMouseMovedEventStorage.params);
			globalMouseMovedEventStorage.prevPos = currentPos;
			break;
		}
		case SDL_MOUSEWHEEL: {
			if (globalMouseScrolledEventStorage.event)
				globalMouseScrolledEventStorage.event(event.wheel.preciseY, globalMouseScrolledEventStorage.params);
			break;
		}
	}
}

pointI2_t getCurrentMousePos() {
	pointI2_t mousePos = int2(0, 0);

	SDL_GetMouseState(&mousePos.x, &mousePos.y);

	return mousePos;
}
