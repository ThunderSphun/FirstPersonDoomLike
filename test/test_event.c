#include "eventInternal.h"

#include "unity_wrapper.h"

void setUp() {
	if (!SDL_WasInit(SDL_INIT_EVENTS))
		SDL_InitSubSystem(SDL_INIT_EVENTS);
	initKeyEvents();
	initMouseEvents();
}

void tearDown() {
	destroyMouseEvents();
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
bool anyKeyTakesIntReturnsTrue(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param) {
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
bool anyKeyTakesIntReturnsFalse(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param) {
	(*(int*) param)++;
	(*(int*) param) += (modifiers & KMOD_SHIFT) ? 10 : 0;
	(*(int*) param) += (modifiers & KMOD_CTRL) ? 100 : 0;
	return false;
}
bool singleKeyTakesNullReturnsTrue(SDL_Keymod modifiers, void* param) { return true; }
bool anyKeyTakesNullReturnsTrue(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param) { return true; }
bool singleKeyTakesNullReturnsFalse(SDL_Keymod modifiers, void* param) { return false; }
bool anyKeyTakesNullReturnsFalse(SDL_KeyCode keyCode, SDL_Keymod modifiers, void* param) { return false; }

void test_registeredSingleKeyEventCanBeCalled() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesNullReturnsTrue, NULL), "registerEvent");
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
}

void test_registeredAnyKeyEventCanBeCalled() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(anyKeyTakesNullReturnsTrue, NULL), "registerEvent");
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_b, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
}

void test_registeredSingleKeyEventCantBeCalledWithoutEventsEnabled() {
	if (SDL_WasInit(SDL_INIT_EVENTS))
		SDL_QuitSubSystem(SDL_INIT_EVENTS);

	TEST_ASSERT_EQUAL(EVENT_NOT_INITIALIZED, registerSingleKeyEvent(SDLK_a, singleKeyTakesNullReturnsTrue, NULL));
}

void test_registeredAnyKeyEventCantBeCalledWithoutEventsEnabled() {
	if (SDL_WasInit(SDL_INIT_EVENTS))
		SDL_QuitSubSystem(SDL_INIT_EVENTS);

	TEST_ASSERT_EQUAL(EVENT_NOT_INITIALIZED, registerGlobalKeyEvents(anyKeyTakesNullReturnsTrue, NULL));
}

void test_keyEventInitWillClearStoredData() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesNullReturnsTrue, NULL), "single 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(anyKeyTakesNullReturnsTrue, NULL), "global 1");
	initKeyEvents();

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesNullReturnsTrue, NULL), "single 2");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(anyKeyTakesNullReturnsTrue, NULL), "global 2");
}

void test_keyEventsCannotBeAddedWhenDestroyed() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesNullReturnsTrue, NULL), "single 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(anyKeyTakesNullReturnsTrue, NULL), "global 1");
	destroyKeyEvents();

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerSingleKeyEvent(SDLK_a, singleKeyTakesNullReturnsTrue, NULL), "single 2");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerGlobalKeyEvents(anyKeyTakesNullReturnsTrue, NULL), "global 2");
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

void test_anyKeyEventParameterHasInfluenceOutsideCallback() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(anyKeyTakesIntReturnsFalse, &i), "registerEvent");

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

void test_anyKeyEventTakesPriorityOverSingleKeyEvent() {
	int i = 0;
	int j = 0;

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleKeyEvent(SDLK_a, singleKeyTakesIntReturnsTrue, &i), "single");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(anyKeyTakesIntReturnsTrue, &j), "global");

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

void test_anyKeyEventCanBeCalledMultipleTimes() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(anyKeyTakesIntReturnsFalse, &i), "registerEvent");
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

void test_anyKeyEventCanBeCancelled() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(anyKeyTakesIntReturnsTrue, &i), "registerEvent");
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

void test_cancelledAnyKeyEventCanBeRestarted() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalKeyEvents(anyKeyTakesIntReturnsTrue, &i), "registerEvent");
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyUpEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	pushKeyDownEvent(SDLK_a, SDL_SCANCODE_A, KMOD_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL(2, i);
}

int main() {
	UNITY_BEGIN();

	RUN_TEST(test_registeredSingleKeyEventCanBeCalled);
	RUN_TEST(test_registeredAnyKeyEventCanBeCalled);
	RUN_TEST(test_registeredSingleKeyEventCantBeCalledWithoutEventsEnabled);
	RUN_TEST(test_registeredAnyKeyEventCantBeCalledWithoutEventsEnabled);
	RUN_TEST(test_keyEventInitWillClearStoredData);
	RUN_TEST(test_keyEventsCannotBeAddedWhenDestroyed);
	RUN_TEST(test_singleKeyEventParameterHasInfluenceOutsideCallback);
	RUN_TEST(test_anyKeyEventParameterHasInfluenceOutsideCallback);
	RUN_TEST(test_anyKeyEventTakesPriorityOverSingleKeyEvent);
	RUN_TEST(test_singleKeyEventOnlyWorksOnThatKey);
	RUN_TEST(test_singleKeyEventCanBeCalledMultipleTimes);
	RUN_TEST(test_anyKeyEventCanBeCalledMultipleTimes);
	RUN_TEST(test_singleKeyEventCanBeCancelled);
	RUN_TEST(test_anyKeyEventCanBeCancelled);
	RUN_TEST(test_cancelledSingleKeyEventCanBeRestarted);
	RUN_TEST(test_cancelledAnyKeyEventCanBeRestarted);

	return UNITY_END();
}