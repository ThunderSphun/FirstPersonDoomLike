#include "eventInternal.h"

#define MAX_MOUSE_COUNT 0x200

static struct {
	keyEvent event;
	void* params;
	struct {
		bool wasPressed : 1;
	};
} globalEventStorage;

struct keyEvent {
	singleKeyEvent event;
	void* params;
	struct {
		bool wasPressed : 1;
	};
};

struct keyEvent* keyEvents = NULL;

void initKeyEvents() {
	keyEvents = calloc(MAX_MOUSE_COUNT, sizeof(struct keyEvent));
}

void destroyKeyEvents() {
	free(keyEvents);
	keyEvents = NULL;
}

bool keyEventsInitialized() {
	return keyEvents != NULL;
}

bool registerSingleKeyEvent(SDL_KeyCode keyCode, singleKeyEvent event, void* param) {
	if (!keyEventsInitialized())
		return false;

	struct keyEvent* keyEvent = &keyEvents[keyCode & (MAX_MOUSE_COUNT - 1)];
	bool returnValue = keyEvent->event;

	keyEvent->event = event;
	keyEvent->params = param;
	keyEvent->wasPressed = false;

	return returnValue;
}

bool registerGlobalKeyEvents(keyEvent event, void* param) {
	if (!keyEventsInitialized())
		return false;

	bool returnValue = globalEventStorage.event;
	globalEventStorage.event = event;
	globalEventStorage.params = param;
	return returnValue;
}

void unregisterSingleKeyEvent(SDL_KeyCode keyCode) {
	if (keyEventsInitialized()) {
		struct keyEvent* keyEvent = &keyEvents[keyCode & (MAX_MOUSE_COUNT - 1)];

		keyEvent->event = NULL;
		keyEvent->params = NULL;
		keyEvent->wasPressed = false;
	}
}

void unregisterGlobalKeyEvents() {
	globalEventStorage.event = NULL;
	globalEventStorage.params = NULL;
}

void handleKeyEvent(SDL_Event event) {
	if (!keyEventsInitialized())
		return;

	SDL_Keymod modifier = SDL_GetModState();

	SDL_KeyCode keyCode = event.key.keysym.sym;
	SDL_KeyCode mappedKeyCode = keyCode & (MAX_MOUSE_COUNT - 1);
	struct keyEvent* currentEvent = &keyEvents[mappedKeyCode];

	if (event.type == SDL_KEYDOWN) {
		if (globalEventStorage.event) {
			if (!globalEventStorage.wasPressed) {
				globalEventStorage.wasPressed = globalEventStorage.event(keyCode, modifier, globalEventStorage.params);
			}
		} else if (currentEvent->event) {
			if (!currentEvent->wasPressed) {
				currentEvent->wasPressed = currentEvent->event(modifier, currentEvent->params);
			}
		}
	} else if (event.type == SDL_KEYUP) {
		if (globalEventStorage.wasPressed) {
			globalEventStorage.wasPressed = false;
		} else if (currentEvent->event) {
			currentEvent->wasPressed = false;
		}
	}
}