#include "eventInternal.h"

#define MAX_MOUSE_COUNT 5

static struct {
	mouseButtonEvent event;
	void* params;
	struct {
		bool wasPressed : 1;
	};
} globalEventStorage;

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
}

void destroyMouseEvents() {
	free(mouseEvents);
	mouseEvents = NULL;
}

bool mouseEventsInitialized() {
	return mouseEvents != NULL;
}

bool registerSingleMouseClickEvent(int mouseButton, singleMouseButtonEvent event, void* param) {
	if (!keyEventsInitialized() || mouseButton >= MAX_MOUSE_COUNT)
		return false;

	struct mouseEvent* mouseEvent = &mouseEvents[mouseButton];
	bool returnValue = mouseEvent->event;

	mouseEvent->event = event;
	mouseEvent->params = param;
	mouseEvent->wasPressed = false;

	return returnValue;
}

bool registerGlobalMouseClickEvents(mouseButtonEvent event, void* param) {
	if (!keyEventsInitialized())
		return false;

	bool returnValue = globalEventStorage.event;
	globalEventStorage.event = event;
	globalEventStorage.params = param;
	return returnValue;
}

void unregisterSingleMouseClickEvent(int mouseButton) {
	if (keyEventsInitialized() && mouseButton < MAX_MOUSE_COUNT) {
		struct mouseEvent* mouseEvent = &mouseEvents[mouseButton];

		mouseEvent->event = NULL;
		mouseEvent->params = NULL;
		mouseEvent->wasPressed = false;
	}
}

void unregisterGlobalMouseClickEvents() {
	globalEventStorage.event = NULL;
	globalEventStorage.params = NULL;
}


void handleMouseEvent(SDL_Event event) {
	if (!mouseEventsInitialized())
		return;

	int button = event.button.button;
	struct mouseEvent* currentEvent = &mouseEvents[button];

	if (event.button.type == SDL_MOUSEBUTTONDOWN) {
		if (globalEventStorage.event) {
			if (!globalEventStorage.wasPressed) {
				globalEventStorage.wasPressed = globalEventStorage.event(button, globalEventStorage.params);
			}
		} else if (currentEvent->event) {
			if (!currentEvent->wasPressed) {
				currentEvent->wasPressed = currentEvent->event(currentEvent->params);
			}
		}
	} else if (event.button.type == SDL_MOUSEBUTTONUP) {
		if (globalEventStorage.wasPressed) {
			globalEventStorage.wasPressed = false;
		} else if (currentEvent->event) {
			currentEvent->wasPressed = false;
		}
	}
}

pointI2_t getCurrentMousePos() {
	pointI2_t mousePos = int2(0, 0);

	SDL_GetMouseState(&mousePos.x, &mousePos.y);

	return mousePos;
}
