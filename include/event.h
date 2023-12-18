#ifndef EVENT_H
#define EVENT_H

#include <stdbool.h>

#include "sdl2_wrapper.h"
#include "screen.h"
#include "point.h"

#pragma region EVENT
/**
 * An event callback for the event `SDL_QUIT`
 * @retval whether it should repeat
 */
typedef bool (*quitEvent)(void* param);

void handleAllEvents();

bool registerQuitEvent(quitEvent event, void* param);
void unregisterQuitEvent();

#pragma region KEY_EVENT
/**
 * An event callback for the event `SDL_KEYDOWN` or `SDL_KEYUP`
 * @param modifiers the modifiers pressed i.e. shift
 * @retval whether it should repeat
 */
typedef bool (*singleKeyEvent)(SDL_Keymod modifiers, void* param);
/**
 * An event callback for the event `SDL_KEYDOWN` or `SDL_KEYUP`
 * This event can fire multiple times per frame if more than one key is pressed
 * This event can ignore multiple keypresses at the same time when set to not repeat
 * @param keyCode the key pressed for this event
 * @param modifiers the modifiers pressed i.e. shift
 * @retval whether it should repeat
 */
typedef bool (*keyEvent)(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param);

bool registerSingleKeyEvent(SDL_KeyCode keyCode, singleKeyEvent event, void* param);
bool registerGlobalKeyEvents(keyEvent event, void* param);

void unregisterSingleKeyEvent(SDL_KeyCode keyCode);
void unregisterGlobalKeyEvents();
#pragma endregion KEY_EVENT
#pragma region MOUSE_EVENT
/**
 * An event callback for the event `SDL_MOUSEBUTTONDOWN` or `SDL_MOUSEBUTTONUP`
 * @retval whether it should repeat
 */
typedef bool (*singleMouseButtonEvent)(void* param);
typedef bool (*mouseButtonEvent)(int button, void* param);

bool registerSingleMouseClickEvent(int mouseButton, singleMouseButtonEvent event, void* param);
bool registerGlobalMouseClickEvents(mouseButtonEvent event, void* param);

void unregisterSingleMouseClickEvent(int mouseButton);
void unregisterGlobalMouseClickEvents();

pointI2_t getCurrentMousePos(window_t window);

#pragma endregion MOUSE_EVENT
#pragma endregion EVENT

#endif // EVENT_H