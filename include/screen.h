#ifndef SCREEN_H
#define SCREEN_H

#include "sdl2_wrapper.h"

SDL_Window* createWindow(const char* title, int width, int height, SDL_WindowFlags flags);

void destroyWindow(SDL_Window* window);

#endif // SCREEN_H