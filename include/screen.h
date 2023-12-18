#ifndef SCREEN_H
#define SCREEN_H

#include <stdbool.h>
#include "sdl2_wrapper.h"

#pragma region WINDOW
typedef struct {
	SDL_Window* window;
	SDL_Renderer* renderer;
} window_t;

window_t createWindow(const char* title, int width, int height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags);
void destroyWindow(window_t window);
#pragma endregion WINDOW

#endif // SCREEN_H