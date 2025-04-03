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

#include "unity.h"

// Unity global instance
UnityFramework Unity = {0};
int Reset = 0;

// Begin testing
void UnityBegin(const char *testFile)
{
    Unity.NumberOfTests = 0;
    Unity.TestFailures = 0;
    Unity.TestPasses = 0;
    Reset = 0;

    printf(COLOR_GREEN "======= RUNNING TESTS =======\n" COLOR_RESET);
}

// End testing and summarize results
int UnityEnd(void)
{
    printf("\n=== TEST SUMMARY ===\n\n");
    printf("Tests Run: 20\n\n");
    printf(COLOR_GREEN "Tests Passed: %d\n" COLOR_RESET, Unity.TestPasses);
    printf(COLOR_RED "Tests Failed: %d\n\n" COLOR_RESET, Unity.TestFailures);

    return Unity.TestFailures ? 1 : 0;
}

// Handle the conclusion of a test
void UnityConcludeTest(void)
{
    printf("Test '%s' ", Unity.CurrentTestName);
    if (Reset > 0)
    {
        // printf("FAILED (line: %d)\n", Unity.CurrentTestLineNumber);
        printf(COLOR_RED "FAILED \n\n" COLOR_RESET);
        Reset = 0;
    }
    else
    {
        printf(COLOR_GREEN "PASSED\n" COLOR_RESET);
        Unity.TestPasses++;
        Unity.NumberOfTests++;
    }
}

// Assertion: Check if two numbers are equal
void UnityAssertEqualNumber(int expected, int actual, int line, const char *expectedStr, const char *actualStr)
{
    Unity.CurrentTestLineNumber = line;

    if (expected != actual)
    {
        Unity.TestFailures++;
        Unity.NumberOfTests++;
        Reset = 1;
        printf("\nEXPECTED (%d), RETURNED: %s (%d) \n", expected, actualStr, actual);
    }
}
