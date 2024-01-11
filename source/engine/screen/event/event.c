#include "eventInternal.h"

static struct {
	quitEvent event;
	void* params;
} quitEventStorage;

bool initialized = false;

void handleAllEvents() {
	static SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT: {
				handleQuitEvent(event);
				break;
			}
			case SDL_KEYDOWN:
			case SDL_KEYUP: {
				handleKeyEvent(event);
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEMOTION:
			case SDL_MOUSEWHEEL: {
				handleMouseEvent(event);
				break;
			}
		}
	}
}

bool quitEventInitialized() {
	return initialized && SDL_WasInit(SDL_INIT_EVENTS);
}

void initQuitEvent() {
	quitEventStorage.event = NULL;
	quitEventStorage.params = NULL;
	initialized = true;
}

void destroyQuitEvent() {
	quitEventStorage.event = NULL;
	quitEventStorage.params = NULL;
	initialized = false;
}

void handleQuitEvent(SDL_Event event) {
	if (quitEventStorage.event)
		quitEventStorage.event(quitEventStorage.params);
}

eventRegisterResponse_t registerQuitEvent(quitEvent event, void* param) {
	if (!quitEventInitialized())
		return EVENT_NOT_INITIALIZED;

	bool hadEvent = quitEventStorage.event;
	quitEventStorage.event = event;
	quitEventStorage.params = param;
	return hadEvent ? EVENT_OVERWRITTEN : EVENT_SUCCESS;
}

void unregisterQuitEvent() {
	quitEventStorage.event = NULL;
	quitEventStorage.params = NULL;
}