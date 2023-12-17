#ifndef SCREEN_H
#define SCREEN_H

#include "sdl2_wrapper.h"

#pragma region WINDOW
typedef struct {
	SDL_Window* window;
	SDL_Renderer* renderer;
} window_t;

window_t createWindow(const char* title, int width, int height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags);
void destroyWindow(window_t window);
#pragma endregion WINDOW

#pragma region EVENT
typedef void (*quitEvent)(void* param);

void handleAllEvents();

bool registerQuitEvent(quitEvent event, void* param);
void unregisterQuitEvent();

#pragma region KEY_EVENT
typedef void (*singleKeyEvent)(SDL_Keymod modifiers, void* param);
typedef void (*keyEvent)(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param);

bool registerSingleKeyEvent(SDL_KeyCode keyCode, singleKeyEvent event, void* param);
bool registerGlobalKeyEvents(keyEvent event, void* param);

void unregisterSingleKeyEvent(SDL_KeyCode keyCode);
void unregisterGlobalKeyEvents();
#pragma endregion KEY_EVENT
#pragma endregion EVENT

#endif // SCREEN_H