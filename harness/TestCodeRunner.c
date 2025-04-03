/**
 * Copyright 2025 daman
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*=======Test Runner Used To Run Each Test Below=====*/

#define TEST_PROTECT() (1) // Simplified for now, always returns true

#define RUN_TEST(TestFunc, TestLineNum)            \
    {                                              \
        Unity.CurrentTestName = #TestFunc;         \
        Unity.CurrentTestLineNumber = TestLineNum; \
        Unity.NumberOfTests++;                     \
        if (TEST_PROTECT())                        \
        {                                          \
            setUp();                               \
            TestFunc();                            \
        }                                          \
        if (TEST_PROTECT())                        \
        {                                          \
            tearDown();                            \
        }                                          \
        UnityConcludeTest();                       \
    }

/*=======Automatically Detected Files To Include=====*/
#include "unity.h"
#include <setjmp.h>
#include <string.h>
#include <stdio.h>
#include "math.h"
#include "../include/givenA3.h"

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_createPlayList(void);
extern void test_createPlayList1(void);
extern void test_createPlayList2(void);
extern void test_createPlayList3(void);
extern void test_addNewSong(void);
extern void test_addNewSong1(void);
extern void test_addNewSong2(void);
extern void test_addNewSong3(void);
extern void test_playSongGivenId(void);
extern void test_playSongGivenId1(void);
extern void test_playSongGivenId2(void);
extern void test_playSongGivenId3(void);
extern void test_playSongGivenName(void);
extern void test_playSongGivenName1(void);
extern void test_playSongGivenName2(void);
extern void test_playSongGivenName3(void);
extern void test_countNotesInASong(void);
extern void test_countNotesInASong1(void);
extern void test_countNotesInASong2(void);
extern void test_countNotesInASong3(void);

/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
    tearDown();
    setUp();
}

// ANSI escape codes for colors
// #define COLOR_GREEN "\033[32m"
// #define COLOR_RED "\033[31m"
// #define COLOR_RESET "\033[0m"

/*=======MAIN=====*/
int main(void)
{
    UnityBegin("TestCode.c");

    // A3Song *headLL = NULL;
    // char fileName[MAX_LENGTH] = "musicalNotes.csv";
    printf("\n\n" COLOR_GREEN "***** Begin Testing *****" COLOR_RESET "\n\n");

    RUN_TEST(test_createPlayList, 10);
    RUN_TEST(test_createPlayList1, 15);
    RUN_TEST(test_createPlayList2, 20);
    RUN_TEST(test_createPlayList3, 25);
    RUN_TEST(test_addNewSong, 30);
    RUN_TEST(test_addNewSong1, 35);
    RUN_TEST(test_addNewSong2, 40);
    RUN_TEST(test_addNewSong3, 45);
    RUN_TEST(test_playSongGivenId, 50);
    RUN_TEST(test_playSongGivenId1, 55);
    RUN_TEST(test_playSongGivenId2, 60);
    RUN_TEST(test_playSongGivenId3, 65);
    RUN_TEST(test_playSongGivenName, 70);
    RUN_TEST(test_playSongGivenName1, 75);
    RUN_TEST(test_playSongGivenName2, 80);
    RUN_TEST(test_playSongGivenName3, 85);
    RUN_TEST(test_countNotesInASong, 90);
    RUN_TEST(test_countNotesInASong1, 95);
    RUN_TEST(test_countNotesInASong2, 100);
    RUN_TEST(test_countNotesInASong3, 105);

    printf("\n" COLOR_RED "***** Testing Ends *****" COLOR_RESET "\n\n");

    return (UnityEnd());
}
