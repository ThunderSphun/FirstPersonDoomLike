#include <stdbool.h>
#include <stdio.h>

#include "screen.h"
#include "event.h"
#include "point.h"

bool shutdownFromRIGHT(SDL_Keymod modifiers, void* param) {
	if (modifiers & KMOD_SHIFT)
		*(bool*)param = false;

	return true;
}

bool shutdownFromESC(SDL_Keymod modifiers, void* param) {
	*(bool*)param = false;

	return false;
}

bool shutdownFromQuit(void* param) {
	*(bool*)param = false;

	return true;
}

bool printKey(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param) {
	printf("pressed %s\n", SDL_GetKeyName(keyCode));

	if (keyCode == SDLK_F12) {
		printf("swapping to individual keypresses\n");
		unregisterGlobalKeyEvents();
	}

	return true;
}

bool printLeftClick(void* param) {
	printf("left mouse was pressed\n");
}

bool printMouseButton(int button, void* param) {
	char* mouseButton = "";
	if (button == SDL_BUTTON_LEFT) mouseButton = "left mouse button";
	if (button == SDL_BUTTON_RIGHT) mouseButton = "right mouse button";
	if (button == SDL_BUTTON_MIDDLE) mouseButton = "middle mouse button";
	if (button == SDL_BUTTON_X1) mouseButton = "backward mouse button";
	if (button == SDL_BUTTON_X2) mouseButton = "forward mouse button";

	pointI2_t pos = getCurrentMousePos(*(window_t *)param);

	printf("pressed %s at (%i, %i)\n", mouseButton, pos.x, pos.y);

	if (button == SDL_BUTTON_X1) {
		printf("swapping to individual keypresses\n");
		unregisterGlobalMouseClickEvents();
	}

	return true;
}

int main() {
	window_t window = createWindow("New Screen", 720, 480, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderTarget(window.renderer, NULL);

	bool running = true;

	registerSingleKeyEvent(SDLK_ESCAPE, shutdownFromESC, &running);
	registerSingleKeyEvent(SDLK_RIGHT, shutdownFromRIGHT, &running);
	registerGlobalKeyEvents(printKey, NULL);

	registerSingleMouseClickEvent(SDL_BUTTON_LEFT, printLeftClick, NULL);
	registerGlobalMouseClickEvents(printMouseButton, &window);

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
