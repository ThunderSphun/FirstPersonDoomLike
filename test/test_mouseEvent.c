#include "eventInternal.h"

#include "unity_wrapper.h"

void setUp() {
	if (!SDL_WasInit(SDL_INIT_EVENTS))
		SDL_InitSubSystem(SDL_INIT_EVENTS);
	initMouseEvents();
}

void tearDown() {
	destroyMouseEvents();
	if (SDL_WasInit(SDL_INIT_EVENTS))
		SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

int main() {
	UNITY_BEGIN();



	return UNITY_END();
}