#include "screenInternal.h"

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
		}
	}
}

bool registerQuitEvent(quitEvent event, void* param) {
	quitEventStorage.event = event;
	quitEventStorage.params = param;
}

void unregisterQuitEvent() {
	quitEventStorage.event = NULL;
	quitEventStorage.params = NULL;
}