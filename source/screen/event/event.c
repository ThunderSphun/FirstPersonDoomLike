#include "eventInternal.h"

static struct {
	quitEvent event;
	void* params;
} quitEventStorage;

void handleAllEvents() {
	static SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT: {
				if (quitEventStorage.event)
					quitEventStorage.event(quitEventStorage.params);
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

eventRegisterResponse_t registerQuitEvent(quitEvent event, void* param) {
	if (!mouseEventsInitialized())
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