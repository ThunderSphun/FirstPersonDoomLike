#ifndef SCREEN_INTERNAL_H
#define SCREEN_INTERNAL_H

#include <stdbool.h>
#include "screen.h"

#pragma region EVENT
#pragma region KEY_EVENT
bool keyEventsInitialized();
void initKeyEvents();
void destroyKeyEvents();
void handleKeyEvent(SDL_Event);
#pragma endregion KEY_EVENT
#pragma endregion EVENT

#endif // SCREEN_INTERNAL_H