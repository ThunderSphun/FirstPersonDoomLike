#include "eventInternal.h"

#include "unity_wrapper.h"

void setUp() {
	if (!SDL_WasInit(SDL_INIT_EVENTS))
		SDL_InitSubSystem(SDL_INIT_EVENTS);
	initQuitEvent();
}

void tearDown() {
	destroyQuitEvent();
	if (SDL_WasInit(SDL_INIT_EVENTS))
		SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

void pushQuitEvent() {
	SDL_Event quitEvent;
	quitEvent.type = SDL_QUIT;

	SDL_PushEvent(&quitEvent);
}

void quitTakesInt(void* param) { (*(int*) param)++; }
void quitTakesNull(void* param) { /* do nothing */ }

void test_canHandleNoEventAttached() {
	handleAllEvents();
	TEST_PASS();
}

void test_registeredQuitEventCanBeCalled() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerQuitEvent(quitTakesNull, NULL), "registerEvent");
	handleAllEvents();
	TEST_PASS();
}

void test_unregisteredQuitEventCantBeCalled() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerQuitEvent(quitTakesInt, &i), "registerEvent");
	unregisterQuitEvent();
	handleAllEvents();
	TEST_ASSERT_EQUAL(0, i);
}

void test_registeredQuitEventCantBeCalledWithoutEventsEnabled() {
	if (SDL_WasInit(SDL_INIT_EVENTS))
		SDL_QuitSubSystem(SDL_INIT_EVENTS);

	TEST_ASSERT_EQUAL(EVENT_NOT_INITIALIZED, registerQuitEvent(quitTakesNull, NULL));
}

void test_quitEventInitWillClearStoredData() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerQuitEvent(quitTakesNull, NULL), "register 1");
	initQuitEvent();

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerQuitEvent(quitTakesNull, NULL), "register 2");
}

void test_quitCannotBeAddedWhenDestroyed() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerQuitEvent(quitTakesNull, NULL), "register 1");
	destroyQuitEvent();

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerQuitEvent(quitTakesNull, NULL), "register 2");
}

void test_quitEventParameterHasInfluenceOutsideCallback() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerQuitEvent(quitTakesInt, &i), "registerEvent");

	pushQuitEvent();
	handleAllEvents();
	TEST_ASSERT_EQUAL(1, i);

	pushQuitEvent();
	handleAllEvents();
	TEST_ASSERT_EQUAL(2, i);
}

void test_quitEventCanBeCalledMultipleTimes() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerQuitEvent(quitTakesInt, &i), "registerEvent");
	pushQuitEvent();
	pushQuitEvent();
	pushQuitEvent();
	pushQuitEvent();
	handleAllEvents();
	TEST_ASSERT_EQUAL(4, i);
}

int main() {
	UNITY_BEGIN();

	RUN_TEST(test_canHandleNoEventAttached);
	RUN_TEST(test_registeredQuitEventCanBeCalled);
	RUN_TEST(test_unregisteredQuitEventCantBeCalled);
	RUN_TEST(test_registeredQuitEventCantBeCalledWithoutEventsEnabled);
	RUN_TEST(test_quitEventInitWillClearStoredData);
	RUN_TEST(test_quitCannotBeAddedWhenDestroyed);
	RUN_TEST(test_quitEventParameterHasInfluenceOutsideCallback);
	RUN_TEST(test_quitEventCanBeCalledMultipleTimes);

	return UNITY_END();
}