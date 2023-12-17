#include <stdbool.h>
#include <stdio.h>

#include "screen.h"

void shutdownFromRIGHT(SDL_Keymod modifiers, void* param) {
	if (modifiers & KMOD_SHIFT)
		*(bool*)param = false;
}

void shutdownFromESC(SDL_Keymod modifiers, void* param) {
	*(bool*)param = false;
}

void shutdownFromQuit(void* param) {
	*(bool*)param = false;
}

void printKey(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param) {
	printf("pressed %s\n", SDL_GetKeyName(keyCode));

	if (keyCode == SDLK_F12) {
		printf("swapping to individual keypresses");
		unregisterGlobalKeyEvents();
	}
}

int main() {
	window_t window = createWindow("New Screen", 720, 480, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderTarget(window.renderer, NULL);

	bool running = true;

	registerSingleKeyEvent(SDLK_ESCAPE, shutdownFromESC, &running);
	registerSingleKeyEvent(SDLK_RIGHT, shutdownFromRIGHT, &running);
//	registerGlobalKeyEvents(printKey, NULL);

	registerQuitEvent(shutdownFromQuit, &running);

	while (running) {
		handleAllEvents();
		SDL_UpdateWindowSurface(window.window);

		SDL_RenderClear(window.renderer);
		SDL_RenderPresent(window.renderer);
	}

	destroyWindow(window);

	return 0;
}
