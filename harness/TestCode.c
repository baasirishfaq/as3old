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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "unity.h"
#include "CodeUnderTest.h"

void setUp(void)
{
}

void tearDown(void)
{
}

// Helper function to simulate user input
void simulateUserInput(const char *input)
{
    // Create a temporary file to hold the simulated input
    FILE *tempFile = tmpfile();
    if (tempFile == NULL)
    {
        perror("tmpfile");
        exit(EXIT_FAILURE);
    }

    // Write the input string to the temporary file
    fputs(input, tempFile);

    // Rewind the file to the beginning
    rewind(tempFile);

    // Redirect stdin to read from the temporary file
    if (freopen("/dev/null", "r", stdin) == NULL)
    {
        perror("freopen");
        exit(EXIT_FAILURE);
    }
}

// Helper function to redirect stdout to /dev/null
void redirectStdoutToNull(FILE **originalStdout)
{
    *originalStdout = stdout;
    if (freopen("/dev/null", "w", stdout) == NULL)
    {
        perror("freopen");
        exit(EXIT_FAILURE);
    }
    if (stdout == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
}

// Helper function to restore stdout
void restoreStdout(FILE *originalStdout)
{
    if (stdout != NULL)
    {
        fclose(stdout);
    }

    if (freopen("/dev/tty", "w", stdout) == NULL)
    {
        perror("freopen");
        exit(EXIT_FAILURE);
    }
}

void test_createPlayList(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes.csv";
    int result = createPlayList(&headLL, fileName);

    TEST_ASSERT_EQUAL(101, result);
}

void test_createPlayList1(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes1.csv";
    int result = createPlayList(&headLL, fileName);
    TEST_ASSERT_EQUAL(41, result);
}

void test_createPlayList2(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes2.csv";
    int result = createPlayList(&headLL, fileName);
    TEST_ASSERT_EQUAL(202, result);
}

void test_createPlayList3(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes3.csv";
    int result = createPlayList(&headLL, fileName);
    TEST_ASSERT_EQUAL(0, result);
}

void test_addNewSong(void)
{

    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes.csv";
    int result1 = createPlayList(&headLL, fileName);

    // Simulate user input for addNewSong
    const char *userInput = "Replay\n";
    simulateUserInput(userInput);

    // Redirect stdout to /dev/null
    FILE *originalStdout;
    redirectStdoutToNull(&originalStdout);

    bool returnValue = addNewSong(&headLL, 3);

    // Restore stdout
    restoreStdout(originalStdout);
    TEST_ASSERT_FALSE(returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_addNewSong1(void)
{

    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes1.csv";
    int result1 = createPlayList(&headLL, fileName);

    // Simulate user input for addNewSong
    const char *userInput = "Replay1\n";
    simulateUserInput(userInput);
    FILE *originalStdout;
    redirectStdoutToNull(&originalStdout);
    bool returnValue = addNewSong(&headLL, 1);
    // Restore stdout
    restoreStdout(originalStdout);
    TEST_ASSERT_TRUE(returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_addNewSong2(void)
{

    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes2.csv";
    int result1 = createPlayList(&headLL, fileName);

    // Simulate user input for addNewSong
    const char *userInput = "Replay2\n";
    simulateUserInput(userInput);
    // Redirect stdout to /dev/null
    FILE *originalStdout;
    redirectStdoutToNull(&originalStdout);
    bool returnValue = addNewSong(&headLL, -1);
    restoreStdout(originalStdout);
    TEST_ASSERT_FALSE(returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_addNewSong3(void)
{

    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes2.csv";
    int result1 = createPlayList(&headLL, fileName);

    // Simulate user input for addNewSong
    const char *userInput = "Replay3\n";
    simulateUserInput(userInput);
    // Redirect stdout to /dev/null
    FILE *originalStdout;
    redirectStdoutToNull(&originalStdout);
    bool returnValue = addNewSong(&headLL, 2);
    restoreStdout(originalStdout);
    TEST_ASSERT_TRUE(returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_playSongGivenId(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes.csv";
    int result1 = createPlayList(&headLL, fileName);
    int songId;
    A3Song *temp = headLL;
    for (int i = 0; i < 35; i++)
    {
        // find songID of 36th song
        temp = temp->nextSong;
    }
    songId = temp->songId;
    FILE *originalStdout;
    redirectStdoutToNull(&originalStdout);
    int returnValue = playSongGivenId(headLL, songId);
    restoreStdout(originalStdout);
    TEST_ASSERT_EQUAL(1, returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_playSongGivenId1(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes1.csv";
    int result1 = createPlayList(&headLL, fileName);

    A3Song *temp = headLL;
    int songId;
    for (int i = 0; i < 40; i++)
    {
        // find songID of 36th song
        temp = temp->nextSong;
    }
    songId = temp->songId;
    FILE *originalStdout;
    redirectStdoutToNull(&originalStdout);
    int returnValue = playSongGivenId(headLL, songId);
    restoreStdout(originalStdout);

    TEST_ASSERT_EQUAL(1, returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_playSongGivenId2(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes2.csv";
    int result1 = createPlayList(&headLL, fileName);
    A3Song *temp = headLL;
    int songId;
    for (int i = 0; i < 135; i++)
    {
        // find songID of 36th song
        temp = temp->nextSong;
    }
    songId = temp->songId;
    FILE *originalStdout;
    redirectStdoutToNull(&originalStdout);
    int returnValue = playSongGivenId(headLL, songId);
    restoreStdout(originalStdout);

    TEST_ASSERT_EQUAL(1, returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_playSongGivenId3(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes3.csv";
    int result1 = createPlayList(&headLL, fileName);
    // int songId;
    // A3Song *temp = headLL;

    // songId = temp->songId;
    int returnValue = playSongGivenId(headLL, 5);

    TEST_ASSERT_EQUAL(-1, returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_playSongGivenName(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes.csv";
    int result1 = createPlayList(&headLL, fileName);
    char givenSongName[MAX_LENGTH] = "Rustic SAGA";
    FILE *originalStdout;
    redirectStdoutToNull(&originalStdout);
    int returnValue = playSongGivenName(headLL, givenSongName);
    restoreStdout(originalStdout);
    TEST_ASSERT_EQUAL(1, returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_playSongGivenName1(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes1.csv";
    int result1 = createPlayList(&headLL, fileName);
    char givenSongName[MAX_LENGTH] = "ShiMMering Harmony";
    FILE *originalStdout;
    redirectStdoutToNull(&originalStdout);
    int returnValue = playSongGivenName(headLL, givenSongName);
    restoreStdout(originalStdout);
    TEST_ASSERT_EQUAL(1, returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_playSongGivenName2(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes2.csv";
    int result1 = createPlayList(&headLL, fileName);
    char givenSongName[MAX_LENGTH] = "Flowers";
    FILE *originalStdout;
    redirectStdoutToNull(&originalStdout);
    int returnValue = playSongGivenName(headLL, givenSongName);
    restoreStdout(originalStdout);
    TEST_ASSERT_EQUAL(-1, returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_playSongGivenName3(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes3.csv";
    int result1 = createPlayList(&headLL, fileName);
    char givenSongName[MAX_LENGTH] = "Rustic saga";
    FILE *originalStdout;
    redirectStdoutToNull(&originalStdout);
    int returnValue = playSongGivenName(headLL, givenSongName);
    restoreStdout(originalStdout);
    TEST_ASSERT_EQUAL(-1, returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_countNotesInASong(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes.csv";
    int result1 = createPlayList(&headLL, fileName);
    int songId;
    A3Song *temp = headLL;
    for (int i = 0; i < 35; i++)
    {
        // find songID of 36th song
        temp = temp->nextSong;
    }
    songId = temp->songId;
    // printf("Song name: %s\n", temp->songName);
    char whichNote[4] = "do";

    int returnValue = countNotesInASong(headLL, songId, whichNote);
    TEST_ASSERT_EQUAL(5, returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_countNotesInASong1(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes1.csv";
    int result1 = createPlayList(&headLL, fileName);
    int songId;
    A3Song *temp = headLL;
    for (int i = 0; i < 37; i++)
    {
        // find songID of 36th song
        temp = temp->nextSong;
    }
    songId = temp->songId;
    // printf("Song name: %s\n", temp->songName);
    char whichNote[4] = "do";

    int returnValue = countNotesInASong(headLL, songId, whichNote);
    TEST_ASSERT_EQUAL(0, returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_countNotesInASong2(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes2.csv";
    int result1 = createPlayList(&headLL, fileName);
    int songId;
    A3Song *temp = headLL;
    for (int i = 0; i < 150; i++)
    {
        // find songID of 36th song
        temp = temp->nextSong;
    }
    songId = temp->songId;
    // printf("Song name: %s\n", temp->songName);
    char whichNote[4] = "fa";

    int returnValue = countNotesInASong(headLL, songId, whichNote);
    TEST_ASSERT_EQUAL(5, returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}

void test_countNotesInASong3(void)
{
    A3Song *headLL = NULL; // Declare and initialize headLL
    char fileName[MAX_LENGTH] = "musicalNotes3.csv";
    int result1 = createPlayList(&headLL, fileName);
    int songId = 0;

    char whichNote[4] = "ga";

    int returnValue = countNotesInASong(headLL, songId, whichNote);
    TEST_ASSERT_EQUAL(-1, returnValue); // Use TEST_ASSERT_FALSE to check if returnValue is false
}
