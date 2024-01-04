#include "eventInternal.h"

#define MAX_KEY_COUNT 0x200

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
	keyEvents = calloc(MAX_KEY_COUNT, sizeof(struct keyEvent));

	globalEventStorage.event = NULL;
	globalEventStorage.params = NULL;
	globalEventStorage.wasPressed = false;
}

void destroyKeyEvents() {
	free(keyEvents);
	keyEvents = NULL;

	globalEventStorage.event = NULL;
	globalEventStorage.params = NULL;
	globalEventStorage.wasPressed = false;
}

bool keyEventsInitialized() {
	return keyEvents != NULL && SDL_WasInit(SDL_INIT_EVENTS);
}

eventRegisterResponse_t registerSingleKeyEvent(SDL_KeyCode keyCode, singleKeyEvent event, void* param) {
	if (!keyEventsInitialized())
		return EVENT_NOT_INITIALIZED;

	struct keyEvent* keyEvent = &keyEvents[keyCode & (MAX_KEY_COUNT - 1)];
	bool hadEvent = keyEvent->event;

	keyEvent->event = event;
	keyEvent->params = param;
	keyEvent->wasPressed = false;

	return hadEvent ? EVENT_OVERWRITTEN : EVENT_SUCCESS;
}

eventRegisterResponse_t registerGlobalKeyEvents(keyEvent event, void* param) {
	if (!keyEventsInitialized())
		return EVENT_NOT_INITIALIZED;

	bool hadEvent = globalEventStorage.event;
	globalEventStorage.event = event;
	globalEventStorage.params = param;
	return hadEvent ? EVENT_OVERWRITTEN : EVENT_SUCCESS;
}

void unregisterSingleKeyEvent(SDL_KeyCode keyCode) {
	if (keyEventsInitialized()) {
		struct keyEvent* keyEvent = &keyEvents[keyCode & (MAX_KEY_COUNT - 1)];

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

	SDL_Keymod modifier = event.key.keysym.mod;

	SDL_KeyCode keyCode = event.key.keysym.sym;
	SDL_KeyCode mappedKeyCode = keyCode & (MAX_KEY_COUNT - 1);
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