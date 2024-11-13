#include <Arduino.h>
#include <unity.h>
#include "schedule_calcs.h"

static void nullIgnCallback(void) {};

void test_adjust_crank_angle_pending_below_minrevolutions()
{
    auto counter = decltype(+IGN4_COUNTER){0};
    auto compare = decltype(+IGN4_COMPARE){0};
    IgnitionSchedule schedule(counter, compare, nullIgnCallback, nullIgnCallback);

    schedule.Status = PENDING;
    currentStatus.startRevolutions = 0;

    schedule.compare = 101;
    schedule.counter = 100;

    // Should do nothing.
    adjustCrankAngle(schedule, 359, 180);

    TEST_ASSERT_EQUAL(101, schedule.compare);
    TEST_ASSERT_EQUAL(100, schedule.counter);
    TEST_ASSERT_FALSE(schedule.endScheduleSetByDecoder);
}


void test_adjust_crank_angle_pending_above_minrevolutions()
{
    auto counter = decltype(+IGN4_COUNTER){0};
    auto compare = decltype(+IGN4_COMPARE){0};
    IgnitionSchedule schedule(counter, compare, nullIgnCallback, nullIgnCallback);
    
    schedule.Status = PENDING;
    currentStatus.startRevolutions = 2000;
    // timePerDegreex16 = 666;

    schedule.compare = 101;
    schedule.counter = 100;
    schedule.endCompare = 100;
    constexpr uint16_t newCrankAngle = 180;
    constexpr uint16_t chargeAngle = 359;

    adjustCrankAngle(schedule, chargeAngle, newCrankAngle);

    TEST_ASSERT_EQUAL(101, schedule.compare);
    TEST_ASSERT_EQUAL(100, schedule.counter);
    TEST_ASSERT_EQUAL(schedule.counter+uS_TO_TIMER_COMPARE(angleToTimeMicroSecPerDegree(chargeAngle-newCrankAngle)), schedule.endCompare);
    TEST_ASSERT_TRUE(schedule.endScheduleSetByDecoder);
}

void test_adjust_crank_angle_running()
{
    auto counter = decltype(+IGN4_COUNTER){0};
    auto compare = decltype(+IGN4_COMPARE){0};
    IgnitionSchedule schedule(counter, compare, nullIgnCallback, nullIgnCallback);
    
    schedule.Status = RUNNING;
    currentStatus.startRevolutions = 2000;
    // timePerDegreex16 = 666;

    schedule.compare = 101;
    schedule.counter = 100;
    schedule.endCompare = 100;
    constexpr uint16_t newCrankAngle = 180;
    constexpr uint16_t chargeAngle = 359;

    adjustCrankAngle(schedule, chargeAngle, newCrankAngle);

    TEST_ASSERT_EQUAL(schedule.counter+uS_TO_TIMER_COMPARE(angleToTimeMicroSecPerDegree(chargeAngle-newCrankAngle)), schedule.compare);
    TEST_ASSERT_EQUAL(100, schedule.counter);
    TEST_ASSERT_EQUAL(100, schedule.endCompare);
    TEST_ASSERT_FALSE(schedule.endScheduleSetByDecoder);
}

void test_adjust_crank_angle()
{
    RUN_TEST(test_adjust_crank_angle_pending_below_minrevolutions);
    RUN_TEST(test_adjust_crank_angle_pending_above_minrevolutions);
    RUN_TEST(test_adjust_crank_angle_running);
}