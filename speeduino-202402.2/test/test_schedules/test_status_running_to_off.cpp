
#include <Arduino.h>
#include <unity.h>

#include "scheduler.h"

#define TIMEOUT 1000
#define DURATION 1000

static void emptyCallback(void) {  }

void test_status_running_to_off_inj1(void)
{
    initialiseSchedulers();
    setFuelSchedule(fuelSchedule1, TIMEOUT, DURATION);
    while( (fuelSchedule1.Status == PENDING) || (fuelSchedule1.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, fuelSchedule1.Status);
}

void test_status_running_to_off_inj2(void)
{
    initialiseSchedulers();
    setFuelSchedule(fuelSchedule2, TIMEOUT, DURATION);
    while( (fuelSchedule2.Status == PENDING) || (fuelSchedule2.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, fuelSchedule2.Status);
}

void test_status_running_to_off_inj3(void)
{
    initialiseSchedulers();
    setFuelSchedule(fuelSchedule3, TIMEOUT, DURATION);
    while( (fuelSchedule3.Status == PENDING) || (fuelSchedule3.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, fuelSchedule3.Status);
}

void test_status_running_to_off_inj4(void)
{
    initialiseSchedulers();
    setFuelSchedule(fuelSchedule4, TIMEOUT, DURATION);
    while( (fuelSchedule4.Status == PENDING) || (fuelSchedule4.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, fuelSchedule4.Status);
}

void test_status_running_to_off_inj5(void)
{
#if INJ_CHANNELS >= 5
    initialiseSchedulers();
    setFuelSchedule(fuelSchedule5, TIMEOUT, DURATION);
    while( (fuelSchedule5.Status == PENDING) || (fuelSchedule5.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, fuelSchedule5.Status);
#endif
}

void test_status_running_to_off_inj6(void)
{
#if INJ_CHANNELS >= 6
    initialiseSchedulers();
    setFuelSchedule(fuelSchedule6, TIMEOUT, DURATION);
    while( (fuelSchedule6.Status == PENDING) || (fuelSchedule6.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, fuelSchedule6.Status);
#endif
}

void test_status_running_to_off_inj7(void)
{
#if INJ_CHANNELS >= 7
    initialiseSchedulers();
    setFuelSchedule(fuelSchedule7, TIMEOUT, DURATION);
    while( (fuelSchedule7.Status == PENDING) || (fuelSchedule7.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, fuelSchedule7.Status);
#endif
}

void test_status_running_to_off_inj8(void)
{
#if INJ_CHANNELS >= 8
    initialiseSchedulers();
    setFuelSchedule(fuelSchedule8, TIMEOUT, DURATION);
    while( (fuelSchedule8.Status == PENDING) || (fuelSchedule8.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, fuelSchedule8.Status);
#endif
}


void test_status_running_to_off_ign1(void)
{
    initialiseSchedulers();
    ignitionSchedule1.pStartCallback = emptyCallback;
    ignitionSchedule1.pEndCallback = emptyCallback;
    setIgnitionSchedule(ignitionSchedule1, TIMEOUT, DURATION);
    while( (ignitionSchedule1.Status == PENDING) || (ignitionSchedule1.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, ignitionSchedule1.Status);
}

void test_status_running_to_off_ign2(void)
{
    initialiseSchedulers();
    ignitionSchedule2.pStartCallback = emptyCallback;
    ignitionSchedule2.pEndCallback = emptyCallback;
    setIgnitionSchedule(ignitionSchedule2, TIMEOUT, DURATION);
    while( (ignitionSchedule2.Status == PENDING) || (ignitionSchedule2.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, ignitionSchedule2.Status);
}

void test_status_running_to_off_ign3(void)
{
    initialiseSchedulers();
    ignitionSchedule3.pStartCallback = emptyCallback;
    ignitionSchedule3.pEndCallback = emptyCallback;
    setIgnitionSchedule(ignitionSchedule3, TIMEOUT, DURATION);
    while( (ignitionSchedule3.Status == PENDING) || (ignitionSchedule3.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, ignitionSchedule3.Status);
}

void test_status_running_to_off_ign4(void)
{
    initialiseSchedulers();
    ignitionSchedule4.pStartCallback = emptyCallback;
    ignitionSchedule4.pEndCallback = emptyCallback;
    setIgnitionSchedule(ignitionSchedule4, TIMEOUT, DURATION);
    while( (ignitionSchedule4.Status == PENDING) || (ignitionSchedule4.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, ignitionSchedule4.Status);
}

void test_status_running_to_off_ign5(void)
{
#if IGN_CHANNELS >= 5
    initialiseSchedulers();
    ignitionSchedule5.pStartCallback = emptyCallback;
    ignitionSchedule5.pEndCallback = emptyCallback;
    setIgnitionSchedule(ignitionSchedule5, TIMEOUT, DURATION);
    while( (ignitionSchedule5.Status == PENDING) || (ignitionSchedule5.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, ignitionSchedule5.Status);
#endif
}

void test_status_running_to_off_ign6(void)
{
#if IGN_CHANNELS >= 6
    initialiseSchedulers();
    ignitionSchedule6.pStartCallback = emptyCallback;
    ignitionSchedule6.pEndCallback = emptyCallback;
    setIgnitionSchedule(ignitionSchedule6, TIMEOUT, DURATION);
    while( (ignitionSchedule6.Status == PENDING) || (ignitionSchedule6.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, ignitionSchedule6.Status);
#endif
}

void test_status_running_to_off_ign7(void)
{
#if IGN_CHANNELS >= 7
    initialiseSchedulers();
    ignitionSchedule7.pStartCallback = emptyCallback;
    ignitionSchedule7.pEndCallback = emptyCallback;
    setIgnitionSchedule(ignitionSchedule7, TIMEOUT, DURATION);
    while( (ignitionSchedule7.Status == PENDING) || (ignitionSchedule7.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, ignitionSchedule7.Status);
#endif
}

void test_status_running_to_off_ign8(void)
{
#if IGN_CHANNELS >= 8
    initialiseSchedulers();
    ignitionSchedule8.pStartCallback = emptyCallback;
    ignitionSchedule8.pEndCallback = emptyCallback;
    setIgnitionSchedule(ignitionSchedule8, TIMEOUT, DURATION);
    while( (ignitionSchedule8.Status == PENDING) || (ignitionSchedule8.Status == RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_EQUAL(OFF, ignitionSchedule8.Status);
#endif
}

void test_status_running_to_off(void)
{
    RUN_TEST(test_status_running_to_off_inj1);
    RUN_TEST(test_status_running_to_off_inj2);
    RUN_TEST(test_status_running_to_off_inj3);
    RUN_TEST(test_status_running_to_off_inj4);
    RUN_TEST(test_status_running_to_off_inj5);
    RUN_TEST(test_status_running_to_off_inj6);
    RUN_TEST(test_status_running_to_off_inj7);
    RUN_TEST(test_status_running_to_off_inj8);

    RUN_TEST(test_status_running_to_off_ign1);
    RUN_TEST(test_status_running_to_off_ign2);
    RUN_TEST(test_status_running_to_off_ign3);
    RUN_TEST(test_status_running_to_off_ign4);
    RUN_TEST(test_status_running_to_off_ign5);
    RUN_TEST(test_status_running_to_off_ign6);
    RUN_TEST(test_status_running_to_off_ign7);
    RUN_TEST(test_status_running_to_off_ign8);
}
