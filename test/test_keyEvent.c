#include "eventInternal.h"

#include "unity_wrapper.h"

void setUp() {
	if (!SDL_WasInit(SDL_INIT_EVENTS))
		SDL_InitSubSystem(SDL_INIT_EVENTS);
	initKeyEvents();
}

void tearDown() {
	destroyKeyEvents();
	if (SDL_WasInit(SDL_INIT_EVENTS))
		SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

void pushKeyDownEvent(SDL_KeyCode keyCode, SDL_Scancode scanCode, SDL_Keymod modifiers) {
	SDL_Event downEvent;
	downEvent.type = SDL_KEYDOWN;
	downEvent.key.keysym.sym = keyCode;
	downEvent.key.keysym.scancode = scanCode;
	downEvent.key.keysym.mod = modifiers;

	SDL_PushEvent(&downEvent);
}

void pushKeyUpEvent(SDL_KeyCode keyCode, SDL_Scancode scanCode, SDL_Keymod modifiers) {
	SDL_Event upEvent;
	upEvent.type = SDL_KEYUP;
	upEvent.key.keysym.sym = keyCode;
	upEvent.key.keysym.scancode = scanCode;
	upEvent.key.keysym.mod = modifiers;

	SDL_PushEvent(&upEvent);
}

bool singleKeyTakesIntReturnsTrue(SDL_Keymod modifiers, void* param) {
	(*(int*) param)++;
	(*(int*) param) += (modifiers & KMOD_SHIFT) ? 10 : 0;
	(*(int*) param) += (modifiers & KMOD_CTRL) ? 100 : 0;
	return true;
}
bool globalKeyTakesIntReturnsTrue(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param) {
	(*(int*) param)++;
	(*(int*) param) += (modifiers & KMOD_SHIFT) ? 10 : 0;
	(*(int*) param) += (modifiers & KMOD_CTRL) ? 100 : 0;
	return true;
}
bool singleKeyTakesIntReturnsFalse(SDL_Keymod modifiers, void* param) {
	(*(int*) param)++;
	(*(int*) param) += (modifiers & KMOD_SHIFT) ? 10 : 0;
	(*(int*) param) += (modifiers & KMOD_CTRL) ? 100 : 0;
	return false;
}
bool globalKeyTakesIntReturnsFalse(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param) {
	(*(int*) param)++;
	(*(int*) param) += (modifiers & KMOD_SHIFT) ? 10 : 0;
	(*(int*) param) += (modifiers & KMOD_CTRL) ? 100 : 0;
	return false;
}
bool singleKeyTakesNullReturnsTrue(SDL_Keymod modifiers, void* param) { return true; }
bool globalKeyTakesNullReturnsTrue(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param) { return true; }
bool singleKeyTakesNullReturnsFalse(SDL_Keymod modifiers, void* param) { return false; }
bool globalKeyTakesNullReturnsFalse(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param) { return false; }

void test_canHandleNoEventAttached() {
	handleAllEvents();
	TEST_PASS();
}

void test_registeredSingleKeyEventCanBeCalled() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesNullReturnsTrue, NULL), "registerEvent");
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_PASS();
}

void test_registeredGlobalKeyEventCanBeCalled() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(globalKeyTakesNullReturnsTrue, NULL), "registerEvent");
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_PASS();
}

void test_unregisteredSingleKeyEventCantBeCalled() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesIntReturnsTrue, &i), "registerEvent");
	unregisterSingleKeyEvent(SDLK_a);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(0, i);
}

void test_unregisteredGlobalKeyEventCantBeCalled() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(globalKeyTakesIntReturnsTrue, &i), "registerEvent");
	unregisterGlobalKeyEvents();
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(0, i);
}

void test_keyEventCantBeCalledWithoutEventsEnabled() {
	if (SDL_WasInit(SDL_INIT_EVENTS))
		SDL_QuitSubSystem(SDL_INIT_EVENTS);

	TEST_ASSERT_EQUAL(EVENT_NOT_INITIALIZED, registerSingleKeyEvent(SDLK_a, singleKeyTakesNullReturnsTrue, NULL));
	TEST_ASSERT_EQUAL(EVENT_NOT_INITIALIZED, registerGlobalKeyEvents(globalKeyTakesNullReturnsTrue, NULL));
}

void test_keyEventInitWillClearStoredData() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesNullReturnsTrue, NULL), "single 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(globalKeyTakesNullReturnsTrue, NULL), "global 1");
	initKeyEvents();

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesNullReturnsTrue, NULL), "single 2");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(globalKeyTakesNullReturnsTrue, NULL), "global 2");
}

void test_keyEventsCannotBeAddedWhenDestroyed() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesNullReturnsTrue, NULL), "single 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(globalKeyTakesNullReturnsTrue, NULL), "global 1");
	destroyKeyEvents();

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerSingleKeyEvent(SDLK_a, singleKeyTakesNullReturnsTrue, NULL), "single 2");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerGlobalKeyEvents(globalKeyTakesNullReturnsTrue, NULL), "global 2");
}

void test_singleKeyEventParameterHasInfluenceOutsideCallback() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesIntReturnsFalse, &i), "registerEvent");

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(1, i);

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(2, i);
}

void test_globalKeyEventParameterHasInfluenceOutsideCallback() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(globalKeyTakesIntReturnsFalse, &i), "registerEvent");

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(1, i);

	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_B, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(2, i);

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(3, i);
}

void test_globalKeyEventTakesPriorityOverSingleKeyEvent() {
	int i = 0;
	int j = 0;

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesIntReturnsTrue, &i), "single");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(globalKeyTakesIntReturnsTrue, &j), "global");

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(0, i);
	TEST_ASSERT_EQUAL(1, j);
}

void test_singleKeyEventOnlyWorksOnThatKey() {
	int i = 0;

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesIntReturnsTrue, &i), "registerEvent");

	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_B, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(0, i);

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(1, i);

	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_B, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(1, i);
}

void test_singleKeyEventCanHaveMultipleKeysRegistered() {
	int i = 0;
	int j = 0;

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesIntReturnsFalse, &i), "registerEvent");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_b, singleKeyTakesIntReturnsFalse, &j), "registerEvent");

	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_B, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(0, i);
	TEST_ASSERT_EQUAL(1, j);

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(1, i);
	TEST_ASSERT_EQUAL(1, j);

	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_B, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(1, i);
	TEST_ASSERT_EQUAL(2, j);
}

void test_singleKeyEventCanHaveSomeKeysUnregistered() {
	int i = 0;
	int j = 0;

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesIntReturnsFalse, &i), "registerEvent");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_b, singleKeyTakesIntReturnsFalse, &j), "registerEvent");

	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_B, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(0, i);
	TEST_ASSERT_EQUAL(1, j);

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(1, i);
	TEST_ASSERT_EQUAL(1, j);

	unregisterSingleKeyEvent(SDLK_b);

	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_B, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(1, i);
	TEST_ASSERT_EQUAL(1, j);

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(2, i);
	TEST_ASSERT_EQUAL(1, j);
}

void test_singleKeyEventCanBeCalledMultipleTimes() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesIntReturnsFalse, &i), "registerEvent");
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(4, i);
}

void test_globalKeyEventCanBeCalledMultipleTimes() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(globalKeyTakesIntReturnsFalse, &i), "registerEvent");
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(4, i);
}

void test_singleKeyEventCanBeCancelled() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesIntReturnsTrue, &i), "registerEvent");
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(1, i);
}

void test_globalKeyEventCanBeCancelled() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(globalKeyTakesIntReturnsTrue, &i), "registerEvent");
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(1, i);
}

void test_cancelledSingleKeyEventCanBeRestarted() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesIntReturnsTrue, &i), "registerEvent");
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyUpEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(2, i);
}

void test_cancelledGlobalKeyEventCanBeRestarted() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(globalKeyTakesIntReturnsTrue, &i), "registerEvent");
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyUpEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(2, i);
}

void test_singleKeyEventWorksWithKeyModifiers() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesIntReturnsFalse, &i), "registerEvent");

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_SHIFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL(11, i);

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(12, i);

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_CTRL);
	handleAllEvents();
	TEST_ASSERT_EQUAL(113, i);

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_RCTRL | KMOD_LSHIFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL(224, i);
}

void test_globalKeyEventWorksWithKeyModifiers() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(globalKeyTakesIntReturnsFalse, &i), "registerEvent");

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_SHIFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL(11, i);

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(12, i);

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_CTRL);
	handleAllEvents();
	TEST_ASSERT_EQUAL(113, i);

	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_RCTRL | KMOD_LSHIFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL(224, i);
}

int main() {
	UNITY_BEGIN();

	RUN_TEST(test_canHandleNoEventAttached);
	RUN_TEST(test_registeredSingleKeyEventCanBeCalled);
	RUN_TEST(test_registeredGlobalKeyEventCanBeCalled);
	RUN_TEST(test_unregisteredSingleKeyEventCantBeCalled);
	RUN_TEST(test_unregisteredGlobalKeyEventCantBeCalled);
	RUN_TEST(test_keyEventCantBeCalledWithoutEventsEnabled);
	RUN_TEST(test_keyEventInitWillClearStoredData);
	RUN_TEST(test_keyEventsCannotBeAddedWhenDestroyed);
	RUN_TEST(test_singleKeyEventParameterHasInfluenceOutsideCallback);
	RUN_TEST(test_globalKeyEventParameterHasInfluenceOutsideCallback);
	RUN_TEST(test_globalKeyEventTakesPriorityOverSingleKeyEvent);
	RUN_TEST(test_singleKeyEventOnlyWorksOnThatKey);
	RUN_TEST(test_singleKeyEventCanHaveMultipleKeysRegistered);
	RUN_TEST(test_singleKeyEventCanHaveSomeKeysUnregistered);
	RUN_TEST(test_singleKeyEventCanBeCalledMultipleTimes);
	RUN_TEST(test_globalKeyEventCanBeCalledMultipleTimes);
	RUN_TEST(test_singleKeyEventCanBeCancelled);
	RUN_TEST(test_globalKeyEventCanBeCancelled);
	RUN_TEST(test_cancelledSingleKeyEventCanBeRestarted);
	RUN_TEST(test_cancelledGlobalKeyEventCanBeRestarted);
	RUN_TEST(test_singleKeyEventWorksWithKeyModifiers);
	RUN_TEST(test_globalKeyEventWorksWithKeyModifiers);

	return UNITY_END();
}