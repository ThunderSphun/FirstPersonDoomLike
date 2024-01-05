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

void pushMouseDownEvent(int button) {
	SDL_Event downEvent;
	downEvent.type = SDL_MOUSEBUTTONDOWN;
	downEvent.button.button = button;

	SDL_PushEvent(&downEvent);
}

void pushMouseUpEvent(int button) {
	SDL_Event upEvent;
	upEvent.type = SDL_MOUSEBUTTONUP;
	upEvent.button.button = button;

	SDL_PushEvent(&upEvent);
}

void pushMoveMouseEvent(pointI2_t moveTo) {
	SDL_Event moveEvent;
	moveEvent.type = SDL_MOUSEMOTION;
	moveEvent.motion.x = moveTo.x;
	moveEvent.motion.y = moveTo.y;

	SDL_PushEvent(&moveEvent);
}

void pushScrollMouseEvent(float amount) {
	SDL_Event scrollEvent;
	scrollEvent.type = SDL_MOUSEWHEEL;
	scrollEvent.wheel.preciseY = amount;

	SDL_PushEvent(&scrollEvent);
}

bool singlePressTakesIntReturnsTrue(void* param) { (*(int*) param)++; return true; }
bool globalPressTakesIntReturnsTrue(int button, void* param) { (*(int*) param)++; return true; }
bool singlePressTakesIntReturnsFalse(void* param) { (*(int*) param)++; return false; }
bool globalPressTakesIntReturnsFalse(int button, void* param) { (*(int*) param)++; return false; }
void moveTakesInt(pointI2_t from, pointI2_t to, void* param) { (*(int*) param)++; }
void scrollTakesInt(float amount, void * param) { (*(int*) param)++; }

bool singlePressTakesNullReturnsTrue(void* param) { return true; }
bool globalPressTakesNullReturnsTrue(int button, void* param) { return true; }
bool singlePressTakesNullReturnsFalse(void* param) { return false; }
bool globalPressTakesNullReturnsFalse(int button, void* param) { return false; }
void moveTakesNull(pointI2_t from, pointI2_t to, void* param) {}
void scrollTakesNull(float amount, void * param) {}

void moveTakesInt2Arr(pointI2_t from, pointI2_t to, void* param) {
	((pointI2_t*) param)[0] = from;
	((pointI2_t*) param)[1] = to;
}

void test_canHandleNoEventAttached() {
	handleAllEvents();
	TEST_PASS();
}

void test_registeredSinglePressEventCanBeCalled() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesNullReturnsTrue, NULL), "registerEvent");
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_RIGHT);
	handleAllEvents();
	TEST_PASS();
}

void test_registeredGlobalPressEventCanBeCalled() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalMouseClickEvents(globalPressTakesNullReturnsTrue, NULL), "registerEvent");
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_RIGHT);
	handleAllEvents();
	TEST_PASS();
}

void test_registeredMoveMouseEventCanBeCalled() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseMoveEvent(moveTakesNull, NULL), "registerEvent");
	pushMoveMouseEvent(int2(1, 1));
	handleAllEvents();
	TEST_PASS();
}

void test_registeredScrollMouseEventCanBeCalled() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseScrollEvent(scrollTakesNull, NULL), "registerEvent");
	pushScrollMouseEvent(1.0f);
	handleAllEvents();
	TEST_PASS();
}

void test_unregisteredSinglePressEventCantBeCalled() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesIntReturnsTrue, &i), "registerEvent");
	unregisterSingleMouseClickEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_RIGHT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(0, i);
}

void test_unregisteredGlobalPressEventCantBeCalled() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalMouseClickEvents(globalPressTakesIntReturnsTrue, &i), "registerEvent");
	unregisterGlobalMouseClickEvents();
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_RIGHT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(0, i);
}

void test_unregisteredMoveMouseEventCantBeCalled() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseMoveEvent(moveTakesInt, &i), "registerEvent");
	unregisterMouseMoveEvent();
	pushMoveMouseEvent(int2(1, 1));
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(0, i);
}

void test_unregisteredScrollMouseEventCantBeCalled() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseScrollEvent(scrollTakesInt, &i), "registerEvent");
	unregisterMouseScrollEvent();
	pushScrollMouseEvent(1.0f);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(0, i);
}

void test_mouseEventCantBeCalledWithoutEventsEnabled() {
	if (SDL_WasInit(SDL_INIT_EVENTS))
		SDL_QuitSubSystem(SDL_INIT_EVENTS);

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesNullReturnsTrue, NULL), "single click 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerGlobalMouseClickEvents(globalPressTakesNullReturnsTrue, NULL), "global click 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerMouseMoveEvent(moveTakesNull, NULL), "move 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerMouseScrollEvent(scrollTakesNull, NULL), "scroll 1");
}

void test_mouseEventInitWillClearStoredData() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesNullReturnsTrue, NULL), "single click 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalMouseClickEvents(globalPressTakesNullReturnsTrue, NULL), "global click 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseMoveEvent(moveTakesNull, NULL), "move 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseScrollEvent(scrollTakesNull, NULL), "scroll 1");
	initMouseEvents();

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesNullReturnsTrue, NULL), "single click 2");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalMouseClickEvents(globalPressTakesNullReturnsTrue, NULL), "global click 2");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseMoveEvent(moveTakesNull, NULL), "move 2");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseScrollEvent(scrollTakesNull, NULL), "scroll 2");
}

void test_mouseEventsCannotBeAddedWhenDestroyed() {
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesNullReturnsTrue, NULL), "single click 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalMouseClickEvents(globalPressTakesNullReturnsTrue, NULL), "global click 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseMoveEvent(moveTakesNull, NULL), "move 1");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseScrollEvent(scrollTakesNull, NULL), "scroll 1");
	destroyMouseEvents();

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesNullReturnsTrue, NULL), "single click 2");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerGlobalMouseClickEvents(globalPressTakesNullReturnsTrue, NULL), "global click 2");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerMouseMoveEvent(moveTakesNull, NULL), "move 2");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_NOT_INITIALIZED, registerMouseScrollEvent(scrollTakesNull, NULL), "scroll 2");
}

void test_singlePressEventParameterHasInfluenceOutsideCallback() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesIntReturnsFalse, &i), "registerEvent");

	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);

	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(2, i);
}

void test_globalPressEventParameterHasInfluenceOutsideCallback() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalMouseClickEvents(globalPressTakesIntReturnsFalse, &i), "registerEvent");

	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);

	pushMouseDownEvent(SDL_BUTTON_RIGHT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(2, i);

	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(3, i);
}

void test_moveEventParameterHasInfluenceOutsideCallback() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseMoveEvent(moveTakesInt, &i), "registerEvent");

	pushMoveMouseEvent(int2(1, 1));
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);

	pushMoveMouseEvent(int2(2, 2));
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(2, i);

	pushMoveMouseEvent(int2(3, 3));
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(3, i);
}

void test_ScrollEventParameterHasInfluenceOutsideCallback() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseScrollEvent(scrollTakesInt, &i), "registerEvent");

	pushScrollMouseEvent(1.0f);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);

	pushScrollMouseEvent(-1.0f);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(2, i);
}

void test_globalMouseEventTakesPriorityOverSingleMouseEvent() {
	int i = 0;
	int j = 0;

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesIntReturnsTrue, &i), "single");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalMouseClickEvents(globalPressTakesIntReturnsTrue, &j), "global");

	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(0, i);
	TEST_ASSERT_EQUAL_INT(1, j);
}

void test_singlePressEventOnlyWorksOnThatButton() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesIntReturnsFalse, &i), "registerEvent");

	pushMouseDownEvent(SDL_BUTTON_RIGHT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(0, i);

	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);

	pushMouseDownEvent(SDL_BUTTON_RIGHT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);
}

void test_singlePressEventCanHaveMultipleButtonsRegistered() {
	int i = 0;
	int j = 0;

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesIntReturnsFalse, &i), "registerEvent");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_RIGHT, singlePressTakesIntReturnsFalse, &j), "registerEvent");

	pushMouseDownEvent(SDL_BUTTON_RIGHT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(0, i);
	TEST_ASSERT_EQUAL_INT(1, j);

	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);
	TEST_ASSERT_EQUAL_INT(1, j);

	pushMouseDownEvent(SDL_BUTTON_RIGHT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);
	TEST_ASSERT_EQUAL_INT(2, j);
}

void test_singlePressEventCanHaveSomeButtonsUnregistered() {
	int i = 0;
	int j = 0;

	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesIntReturnsFalse, &i), "registerEvent");
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_RIGHT, singlePressTakesIntReturnsFalse, &j), "registerEvent");

	pushMouseDownEvent(SDL_BUTTON_RIGHT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(0, i);
	TEST_ASSERT_EQUAL_INT(1, j);

	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);
	TEST_ASSERT_EQUAL_INT(1, j);

	unregisterSingleMouseClickEvent(SDL_BUTTON_RIGHT);

	pushMouseDownEvent(SDL_BUTTON_RIGHT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);
	TEST_ASSERT_EQUAL_INT(1, j);

	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(2, i);
	TEST_ASSERT_EQUAL_INT(1, j);
}

void test_singlePressEventCanBeCalledMultipleTimes() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesIntReturnsFalse, &i), "registerEvent");
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(4, i);
}

void test_globalPressEventCanBeCalledMultipleTimes() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalMouseClickEvents(globalPressTakesIntReturnsFalse, &i), "registerEvent");
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(4, i);
}

void test_moveEventCanBeCalledMultipleTimes() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseMoveEvent(moveTakesInt, &i), "registerEvent");
	pushMoveMouseEvent(int2(1, 1));
	pushMoveMouseEvent(int2(2, 2));
	pushMoveMouseEvent(int2(3, 3));
	pushMoveMouseEvent(int2(4, 4));
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(4, i);
}

void test_scrollEventCanBeCalledMultipleTimes() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseScrollEvent(scrollTakesInt, &i), "registerEvent");
	pushScrollMouseEvent(+1.0f);
	pushScrollMouseEvent(-1.0f);
	pushScrollMouseEvent(+1.0f);
	pushScrollMouseEvent(-1.0f);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(4, i);
}

void test_singlePressEventCanBeCancelled() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesIntReturnsTrue, &i), "registerEvent");
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);
}

void test_globalPressEventCanBeCancelled() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalMouseClickEvents(globalPressTakesIntReturnsTrue, &i), "registerEvent");
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);
}

void test_cancelledSinglePressEventCanBeRestarted() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesIntReturnsTrue, &i), "registerEvent");
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseUpEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(2, i);
}

void test_cancelledGlobalPressEventCanBeRestarted() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalMouseClickEvents(globalPressTakesIntReturnsTrue, &i), "registerEvent");
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseUpEvent(SDL_BUTTON_LEFT);
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(3, i);
}

void test_moveToSamePositionCausesCallback() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseMoveEvent(moveTakesInt, &i), "registerEvent");

	pushMoveMouseEvent(int2(1, 1));
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);

	pushMoveMouseEvent(int2(1, 1));
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(2, i);
}

void test_singlePressReleaseCausesNoCallback() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_LEFT, singlePressTakesIntReturnsFalse, &i), "registerEvent");
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseUpEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);
}

void test_globalPressReleaseCausesCallback() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerGlobalMouseClickEvents(globalPressTakesIntReturnsFalse, &i), "registerEvent");
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseUpEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(2, i);
}

void test_singlePressOnNoneCanListenToButtonRelease() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_NONE, singlePressTakesIntReturnsFalse, &i), "registerEvent");
	pushMouseDownEvent(SDL_BUTTON_NONE);
	pushMouseUpEvent(SDL_BUTTON_NONE);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);
}

void test_singlePressOnNoneCanListenToOtherButtonRelease() {
	int i = 0;
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerSingleMouseClickEvent(SDL_BUTTON_NONE, singlePressTakesIntReturnsFalse, &i), "registerEvent");
	pushMouseDownEvent(SDL_BUTTON_LEFT);
	pushMouseUpEvent(SDL_BUTTON_LEFT);
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT(1, i);
}

void test_moveEventGetsMoveFromPassedIn() {
	TEST_IGNORE_MESSAGE("Need a way to mock mouse position");

	pointI2_t points[2];
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseMoveEvent(moveTakesInt2Arr, points), "registerEvent");

	pushMoveMouseEvent(int2(1, 1));
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT2(int2(0, 0), points[0]);

	pushMoveMouseEvent(int2(1, 1));
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT2(int2(1, 1), points[0]);
}

void test_moveEventGetsMoveToPassedIn() {
	TEST_IGNORE_MESSAGE("Need a way to mock mouse position");

	pointI2_t points[2];
	TEST_ASSERT_EQUAL_MESSAGE(EVENT_SUCCESS, registerMouseMoveEvent(moveTakesInt2Arr, points), "registerEvent");

	pushMoveMouseEvent(int2(1, 1));
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT2(int2(1, 1), points[1]);

	pushMoveMouseEvent(int2(1, 1));
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT2(int2(1, 1), points[1]);

	pushMoveMouseEvent(int2(2, 2));
	handleAllEvents();
	TEST_ASSERT_EQUAL_INT2(int2(2, 2), points[1]);
}

int main() {
	UNITY_BEGIN();

	RUN_TEST(test_canHandleNoEventAttached);
	RUN_TEST(test_registeredSinglePressEventCanBeCalled);
	RUN_TEST(test_registeredGlobalPressEventCanBeCalled);
	RUN_TEST(test_registeredMoveMouseEventCanBeCalled);
	RUN_TEST(test_registeredScrollMouseEventCanBeCalled);
	RUN_TEST(test_unregisteredSinglePressEventCantBeCalled);
	RUN_TEST(test_unregisteredGlobalPressEventCantBeCalled);
	RUN_TEST(test_unregisteredMoveMouseEventCantBeCalled);
	RUN_TEST(test_unregisteredScrollMouseEventCantBeCalled);
	RUN_TEST(test_mouseEventCantBeCalledWithoutEventsEnabled);
	RUN_TEST(test_mouseEventInitWillClearStoredData);
	RUN_TEST(test_mouseEventsCannotBeAddedWhenDestroyed);
	RUN_TEST(test_singlePressEventParameterHasInfluenceOutsideCallback);
	RUN_TEST(test_globalPressEventParameterHasInfluenceOutsideCallback);
	RUN_TEST(test_moveEventParameterHasInfluenceOutsideCallback);
	RUN_TEST(test_ScrollEventParameterHasInfluenceOutsideCallback);
	RUN_TEST(test_globalMouseEventTakesPriorityOverSingleMouseEvent);
	RUN_TEST(test_singlePressEventOnlyWorksOnThatButton);
	RUN_TEST(test_singlePressEventCanHaveMultipleButtonsRegistered);
	RUN_TEST(test_singlePressEventCanHaveSomeButtonsUnregistered);
	RUN_TEST(test_singlePressEventCanBeCalledMultipleTimes);
	RUN_TEST(test_globalPressEventCanBeCalledMultipleTimes);
	RUN_TEST(test_moveEventCanBeCalledMultipleTimes);
	RUN_TEST(test_scrollEventCanBeCalledMultipleTimes);
	RUN_TEST(test_singlePressEventCanBeCancelled);
	RUN_TEST(test_globalPressEventCanBeCancelled);
	RUN_TEST(test_cancelledSinglePressEventCanBeRestarted);
	RUN_TEST(test_cancelledGlobalPressEventCanBeRestarted);
	RUN_TEST(test_moveToSamePositionCausesCallback);
	RUN_TEST(test_singlePressReleaseCausesNoCallback);
	RUN_TEST(test_globalPressReleaseCausesCallback);
	RUN_TEST(test_singlePressOnNoneCanListenToButtonRelease);
	RUN_TEST(test_singlePressOnNoneCanListenToOtherButtonRelease);
	RUN_TEST(test_moveEventGetsMoveFromPassedIn);
	RUN_TEST(test_moveEventGetsMoveToPassedIn);

	return UNITY_END();
}