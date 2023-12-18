#include "screenInternal.h"

window_t createWindow(const char* title, int width, int height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags) {
	if (!SDL_WasInit(SDL_INIT_VIDEO))
		SDL_InitSubSystem(SDL_INIT_VIDEO);
	if (!SDL_WasInit(SDL_INIT_EVENTS))
		SDL_InitSubSystem(SDL_INIT_EVENTS);

	if (!keyEventsInitialized())
		initKeyEvents();
	if (!mouseEventsInitialized())
		initMouseEvents();

	SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, windowFlags);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, rendererFlags);
	return (window_t) {.window = window, .renderer = renderer};
}

void destroyWindow(window_t window) {
	destroyKeyEvents();
	destroyMouseEvents();

	SDL_DestroyRenderer(window.renderer);
	SDL_DestroyWindow(window.window);

	SDL_Quit();
}