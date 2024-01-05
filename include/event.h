#ifndef EVENT_H
#define EVENT_H

#include <stdbool.h>

#include "sdl2_wrapper.h"
#include "point.h"

#pragma region EVENT
typedef enum {
	EVENT_NOT_INITIALIZED = -1,
	EVENT_INVALID_PARAMETER = 0,
	EVENT_OVERWRITTEN = 1,
	EVENT_SUCCESS = 2
} eventRegisterResponse_t;

/**
 * An event callback for the event `SDL_QUIT`
 */
typedef void (*quitEvent)(void* param);

void handleAllEvents();

eventRegisterResponse_t registerQuitEvent(quitEvent event, void* param);
void unregisterQuitEvent();

#pragma region KEY_EVENT
/**
 * An event callback for the event `SDL_KEYDOWN` or `SDL_KEYUP`
 * @param modifiers the modifiers pressed i.e. shift
 * @return true when listening for this key should stop until key release
 */
typedef bool (*singleKeyEvent)(SDL_Keymod modifiers, void* param);
/**
 * An event callback for the event `SDL_KEYDOWN` or `SDL_KEYUP`
 * This event can fire multiple times per frame if more than one key is pressed
 * This event can ignore multiple keypresses at the same time when set to not repeat
 * @param keyCode the key pressed for this event
 * @param modifiers the modifiers pressed i.e. shift
 * @return true when listening for this key should stop until key release
 */
typedef bool (*keyEvent)(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param);

/**
 * registers a key to call a callback
 * it has less priority than the global key event
 * if the global key event is set, the individual callback will not be run
 * @param keyCode the key to check
 * @param event the callback to perform
 * @param param parameters for the callback (optional)
 * @return eventRegisterResponse_t
 */
eventRegisterResponse_t registerSingleKeyEvent(SDL_KeyCode keyCode, singleKeyEvent event, void* param);
/**
 * registers a callback to run on the event `SDL_KEYDOWN` or `SDL_KEYUP`
 * it has higher priority than the single key event
 * if the global key event is set, the individual callback will not be run
 * @param event the callback to perform
 * @param param parameters for the callback (optional)
 * @return eventRegisterResponse_t
 */
eventRegisterResponse_t registerGlobalKeyEvents(keyEvent event, void* param);

void unregisterSingleKeyEvent(SDL_KeyCode keyCode);
void unregisterGlobalKeyEvents();
#pragma endregion KEY_EVENT
#pragma region MOUSE_EVENT
#define SDL_BUTTON_NONE 6
#define SDL_BUTTON_NMASK SDL_BUTTON(SDL_BUTTON_NONE)

/**
 * An event callback for the event `SDL_MOUSEBUTTONDOWN` or `SDL_MOUSEBUTTONUP`
 * @return whether it should repeat
 */
typedef bool (*singleMouseButtonEvent)(void* param);
/**
 * An event callback for the event `SDL_MOUSEBUTTONDOWN` or `SDL_MOUSEBUTTONUP`
 * @param button the mouse button pressed for this event
 * @return whether it should repeat
 */
typedef bool (*mouseButtonEvent)(int button, void* param);
/**
 * An event callback for the event `SDL_MOUSEMOTION`
 * @param from the previous location of the mouse
 * @param to the current location of the mouse
 */
typedef void (*mouseMoveEvent)(pointI2_t from, pointI2_t to, void* param);
/**
 * An event callback for the event `SDL_MOUSEWHEEL`
 * @param amount the amount of movement
 */
typedef void (*mouseScrollEvent)(float amount, void * param);

eventRegisterResponse_t registerSingleMouseClickEvent(unsigned char mouseButton, singleMouseButtonEvent event, void* param);
eventRegisterResponse_t registerGlobalMouseClickEvents(mouseButtonEvent event, void* param);
eventRegisterResponse_t registerMouseMoveEvent(mouseMoveEvent event, void* param);
eventRegisterResponse_t registerMouseScrollEvent(mouseScrollEvent event, void* param);

void unregisterSingleMouseClickEvent(int mouseButton);
void unregisterGlobalMouseClickEvents();
void unregisterMouseMoveEvent();
void unregisterMouseScrollEvent();

pointI2_t getCurrentMousePos();

#pragma endregion MOUSE_EVENT
#pragma endregion EVENT

#endif // EVENT_H