#include "screenInternal.h"

#define printf(...) SDL_Log(__VA_ARGS__)

// seems to be slow to respond
//#define HANDLE_VIA_POLL_EVENT

int MAX_KEY_COUNT;

static struct {
	keyEvent event;
	void* params;
} globalEventStorage;

struct keyEvent {
	singleKeyEvent event;
	void* params;
#ifdef HANDLE_VIA_POLL_EVENT
	bool pressed;
#endif // HANDLE_VIA_POLL_EVENT
};

struct keyEvent* keyEvents = NULL;

void initKeyEvents() {
#ifdef HANDLE_VIA_POLL_EVENT
	MAX_KEY_COUNT = 0x200;
#else
	SDL_GetKeyboardState(&MAX_KEY_COUNT);
#endif // HANDLE_VIA_POLL_EVENT
	keyEvents = calloc(MAX_KEY_COUNT, sizeof(struct keyEvent));
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

	struct keyEvent* keyEvent = &keyEvents[keyCode & (MAX_KEY_COUNT - 1)];
	bool returnValue = keyEvent->event;

	keyEvent->event = event;
	keyEvent->params = param;
#ifdef HANDLE_VIA_POLL_EVENT
	keyEvent->pressed = false;
#endif // HANDLE_VIA_POLL_EVENT

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
		struct keyEvent* event = &keyEvents[keyCode & (MAX_KEY_COUNT - 1)];

		event->event = NULL;
		event->params = NULL;
#ifdef HANDLE_VIA_POLL_EVENT
		event->pressed = false;
#endif // HANDLE_VIA_POLL_EVENT
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

#ifdef HANDLE_VIA_POLL_EVENT
	SDL_KeyCode keyCode = event.key.keysym.sym;
	SDL_KeyCode mappedKeyCode = keyCode & (MAX_KEY_COUNT - 1);

	if (event.type == SDL_KEYDOWN) {
		if (globalEventStorage.event)
			globalEventStorage.event(keyCode, modifier, globalEventStorage.params);
		else if (keyEvents[mappedKeyCode].event)
			keyEvents[mappedKeyCode].pressed = true;
	} else if (event.type == SDL_KEYUP && keyEvents[mappedKeyCode].event)
		keyEvents[mappedKeyCode].pressed = false;
#else
	int count;
	const Uint8* keys = SDL_GetKeyboardState(&count);

	for (int i = 0; i < MAX_KEY_COUNT; i++) {
		if (keys[i]) {
			SDL_KeyCode key = SDL_GetKeyFromScancode(i);
			if (globalEventStorage.event) {
				globalEventStorage.event(key, modifier, globalEventStorage.params);
			} else if (keyEvents[key].event) {
				keyEvents[key].event(modifier, keyEvents[key].params);
			}
		}
	}
#endif // HANDLE_VIA_POLL_EVENT
}