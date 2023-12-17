#include "screen.h"

SDL_Window* createWindow(const char* title, int width, int height, SDL_WindowFlags flags) {
	if (!SDL_WasInit(SDL_INIT_EVERYTHING))
		SDL_Init(SDL_INIT_EVERYTHING);

	return SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
}

void destroyWindow(SDL_Window* window) {
	SDL_DestroyWindow(window);
	SDL_Quit();
}