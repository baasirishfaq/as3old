// Copyright 2025 daman
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef UNITY_H
#define UNITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_RESET "\033[0m"

// Data structure to hold test information
typedef struct
{
    const char *CurrentTestName;
    int CurrentTestLineNumber;
    int NumberOfTests;
    int TestFailures;
    int TestPasses;
} UnityFramework;

extern UnityFramework Unity; // Declare Unity as a global variable

// Unity Core Functions
void UnityBegin(const char *testFile);
int UnityEnd(void);
void UnityConcludeTest(void);

// Assertion Macros
#define TEST_ASSERT_EQUAL(expected, actual) \
    UnityAssertEqualNumber((int)(expected), (int)(actual), __LINE__, #expected, #actual)
#define TEST_ASSERT_FALSE(expression) \
    UnityAssertEqualNumber(0, (int)(expression), __LINE__, #expression, "FALSE")

#define TEST_ASSERT_TRUE(expression) \
    UnityAssertEqualNumber(1, (int)(expression), __LINE__, #expression, "TRUE")

/* #define TEST_ASSERT_EQUAL_STRING(expected, actual) \
    if (strcmp(expected, actual) != 0) \
    { \
    UnityAssertEqualNumber(0, 1, __LINE__, expected, actual); \
    } */

/* #define TEST_ASSERT_FLOAT_WITHIN(delta, expected, actual) \
UnityAssertFloatWithin(delta, (float)(expected), (float)(actual), __LINE__, #expected, #actual)
*/
// #define TEST_ASSERT_TRUE(condition) UNITY_TEST_ASSERT((condition), __LINE__, " Expected TRUE Was FALSE")
// #define TEST_ASSERT_UNLESS(condition) UNITY_TEST_ASSERT(!(condition), __LINE__, " Expression Evaluated To TRUE")
// #define TEST_ASSERT_FALSE(condition) UNITY_TEST_ASSERT(!(condition), __LINE__, " Expected FALSE Was TRUE")

// Assertion Implementations
void UnityAssertEqualNumber(int expected, int actual, int line, const char *expectedStr, const char *actualStr);
/* void UnityAssertFloatWithin(float delta, float expected, float actual, int line, const char *expectedStr, const char *actualStr);
 */
#endif // UNITY_H
