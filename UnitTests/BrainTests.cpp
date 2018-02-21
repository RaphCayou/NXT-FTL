#include "pch.h"
#include "../NXT-FTL/brain.h"
#include "../NXT-FTL/brain.cpp"

using namespace nxtftl;

/*

ASSERT_* yields a fatal failure and returns from the current function
EXPECT_* yields a nonfatal failure, allowing the function to continue running

							Error messages
ASSERT_TRUE(i == 1) << "This text is displayed if the assertion fails" << i;

							Basic operators
ASSERT_TRUE(condition)
ASSERT_FALSE(condition)
ASSERT_EQ(val1, val2)
ASSERT_NE(val1, val2)
ASSERT_LT(val1, val2)
ASSERT_LE(val1, val2)
ASSERT_GT(val1, val2)
ASSERT_GE(val1, val2)

EXPECT_TRUE(condition)
EXPECT_FALSE(condition)
EXPECT_EQ(val1, val2)
EXPECT_NE(val1, val2)
EXPECT_LT(val1, val2)
EXPECT_LE(val1, val2)
EXPECT_GT(val1, val2)
EXPECT_GE(val1, val2)

String operators :
ASSERT_STREQ(str1, str2)
ASSERT_STRNE(str1, str2)
ASSERT_STRCASEEQ(str1, str2) : ignores case
ASSERT_STRCASENE(str1, str2) : ignores case

EXPECT_STREQ(str1, str2)
EXPECT_STRNE(str1, str2)
EXPECT_STRCASEEQ(str1, str2) : ignores case
EXPECT_STRCASENE(str1, str2) : ignores case

					Fixtures
Declaration :

class MyTestFixture : public ::testing::Test {
protected:
virtual void SetUp() {
// Code here will be called immediately after the constructor (right
// before each test).
}

virtual void TearDown() {
// Code here will be called immediately after each test (right
// before the destructor).
}

// Objects declared here can be used by all tests in the test case for Foo.
int my_int_var {};
};

Usage :
// IMPORTANT : Use TEST_F(fixture, caseName) instead of TEST(test, caseName)
// Name of test must be name of fixture (ex: MyTestFixture)
TEST_F(MyTestFixture, AnyCustomTestCaseName) {
	// Members of the fixtures are available directly as if they were declared locally.
	EXPECT_EQ(my_int_var, 0);
}

*/

static unsigned int STOP_DISTANCE = 10;
static unsigned int COLOR_VALUE = 10;

class BrainTestFixture : public ::testing::Test {
protected:
	virtual void SetUp() {
		touch.is_pressed = false;
		distance.distance = 15;
	}

	brain brain{ STOP_DISTANCE };
	touch_sensor_dto touch{};
	distance_sensor_dto distance{};
	color_sensor_dto left{};
	color_sensor_dto right{};
};

TEST_F(BrainTestFixture, BrainStopOnDistance) {
	distance.distance = 5;

	auto directionResult = brain.compute_direction(touch, distance, left, right);

	EXPECT_FALSE(std::get<1>(directionResult));
	EXPECT_EQ(0, std::get<0>(directionResult));
}

TEST_F(BrainTestFixture, BrainStopOnTouch) {
	touch.is_pressed = true;

	auto directionResult = brain.compute_direction(touch, distance, left, right);

	EXPECT_FALSE(std::get<1>(directionResult));
	EXPECT_EQ(0, std::get<0>(directionResult));
}

TEST_F(BrainTestFixture, BrainGoLeft) {

	auto directionResult = brain.compute_direction(touch, distance, left, right);

	EXPECT_TRUE(std::get<1>(directionResult));
	EXPECT_GT(0, std::get<0>(directionResult));
}

TEST_F(BrainTestFixture, BrainGoRight) {

	auto directionResult = brain.compute_direction(touch, distance, left, right);

	EXPECT_TRUE(std::get<1>(directionResult));
	EXPECT_LT(0, std::get<0>(directionResult));
}