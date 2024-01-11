#include "screenInternal.h"

#include "unity_wrapper.h"

window_t window;

void setUp() {}

void tearDown() {
	if (window.window)
		destroyWindow(&window);
}

void createTestWindow(int width, int height) {
	window = createWindow("test program ! DO NOT CLOSE !", width, height, SDL_WINDOW_BORDERLESS | SDL_WINDOW_MINIMIZED, 0);
}

void test_createWindowInitializesSDLSubSystems() {
	createTestWindow(5, 5);

	TEST_ASSERT_TRUE_MESSAGE(SDL_WasInit(SDL_INIT_VIDEO), "video");
	TEST_ASSERT_TRUE_MESSAGE(SDL_WasInit(SDL_INIT_EVENTS), "events");
}

void test_createWindowInitializesEvents() {
	createTestWindow(5, 5);

	TEST_ASSERT_TRUE_MESSAGE(keyEventsInitialized(), "key");
	TEST_ASSERT_TRUE_MESSAGE(mouseEventsInitialized(), "mouse");
	TEST_ASSERT_TRUE_MESSAGE(quitEventInitialized(), "quit");
}

void test_destroyWindowUninitializesSDLSubSystems() {
	createTestWindow(5, 5);
	destroyWindow(&window);

	TEST_ASSERT_FALSE_MESSAGE(SDL_WasInit(SDL_INIT_VIDEO), "video");
	TEST_ASSERT_FALSE_MESSAGE(SDL_WasInit(SDL_INIT_EVENTS), "events");
}

void test_destroyWindowUninitializesEvents() {
	createTestWindow(5, 5);
	destroyWindow(&window);

	TEST_ASSERT_FALSE_MESSAGE(keyEventsInitialized(), "key");
	TEST_ASSERT_FALSE_MESSAGE(mouseEventsInitialized(), "mouse");
	TEST_ASSERT_FALSE_MESSAGE(quitEventInitialized(), "quit");
}

void test_createWindowInitializedStructMembers() {
	createTestWindow(5, 5);

	TEST_ASSERT_NOT_NULL_MESSAGE(window.window, "window");
	TEST_ASSERT_NOT_NULL_MESSAGE(window.gameRenderer, "window");
}

void test_destroyWindowDereferencesWindowStruct() {
	createTestWindow(5, 5);
	destroyWindow(&window);

	TEST_ASSERT_NULL_MESSAGE(window.window, "window");
	TEST_ASSERT_NULL_MESSAGE(window.gameRenderer, "window");
}

int main() {
	UNITY_BEGIN();

	RUN_TEST(test_createWindowInitializesSDLSubSystems);
	RUN_TEST(test_createWindowInitializesEvents);
	RUN_TEST(test_destroyWindowUninitializesSDLSubSystems);
	RUN_TEST(test_destroyWindowUninitializesEvents);
	RUN_TEST(test_createWindowInitializedStructMembers);
	RUN_TEST(test_destroyWindowDereferencesWindowStruct);

	return UNITY_END();
}