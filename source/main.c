#include <stdbool.h>

#include "screen.h"

int main() {
	SDL_Window* window = createWindow("New Screen", 720, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALWAYS_ON_TOP);

	SDL_Event event;
	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: {
					running = false;
					break;
				}
				case SDL_KEYDOWN: {
					if (event.key.keysym.sym == SDLK_ESCAPE) running = false;
					if (event.key.keysym.sym == SDLK_RIGHT) running = false;
					break;
				}
			}
		}
	}

	destroyWindow(window);

	return 0;
}
