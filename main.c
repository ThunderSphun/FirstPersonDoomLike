#include <stdio.h>
#include <stdbool.h>

#define SDL_MAIN_HANDLED

#include <SDL.h>

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("New Screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 480,
										  SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALWAYS_ON_TOP);

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

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
