#ifndef EVENT_INTERNAL_H
#define EVENT_INTERNAL_H

#include "event.h"

#pragma region EVENT
#pragma region KEY_EVENT
bool keyEventsInitialized();
void initKeyEvents();
void destroyKeyEvents();
void handleKeyEvent(SDL_Event event);
#pragma endregion KEY_EVENT

#pragma region MOUSE_EVENT
bool mouseEventsInitialized();
void initMouseEvents();
void destroyMouseEvents();
void handleMouseEvent(SDL_Event event);
#pragma endregion MOUSE_EVENT
#pragma endregion EVENT

#endif // EVENT_INTERNAL_H