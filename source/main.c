#include <stdbool.h>
#include <stdio.h>

#include "screen.h"
#include "event.h"
#include "point.h"
#include "cast.h"

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
	if (button == SDL_BUTTON_NONE) mouseButton = "no mouse button";

	pointI2_t pos = getCurrentMousePos();

	printf("pressed %s at %s\n", mouseButton, toString(pos));

	if (button == SDL_BUTTON_LEFT) *(bool*) param = true;
	if (button == SDL_BUTTON_NONE) *(bool*) param = false;

	if (button == SDL_BUTTON_X1) {
		printf("swapping to individual keypresses\n");
		unregisterGlobalMouseClickEvents();
	}

	return true;
}

void mouseMoved(pointI2_t from, pointI2_t to, void* param) {
	if (*(bool*) param)
		printf("moved to %s\n", toString(from));
}

void printScroll(float amount, void* param) {
	printf("scrolled %f units\n", amount);
}

int main() {
	window_t window = createWindow("New Screen", 720, 480, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderTarget(window.renderer, NULL);

	bool running = true;

	registerSingleKeyEvent(SDLK_ESCAPE, shutdownFromESC, &running);
	registerSingleKeyEvent(SDLK_RIGHT, shutdownFromRIGHT, &running);
	registerGlobalKeyEvents(printKey, NULL);

	bool logging = false;
	registerSingleMouseClickEvent(SDL_BUTTON_LEFT, printLeftClick, NULL);
	registerGlobalMouseClickEvents(printMouseButton, &logging);
	registerMouseMoveEvent(mouseMoved, &logging);
	registerMouseScrollEvent(printScroll, NULL);

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
