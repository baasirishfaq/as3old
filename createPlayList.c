#include "givenA3.h"
#include <time.h> // For srand() and rand()

int createPlayList(A3Song **headLL, char fileName[MAX_LENGTH]) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return -1; // File failed to open
    }

    char line[256];
    int songCount = 0;
    A3Song *tail = NULL; // To keep track of the end of the list for insertion

    // Seed the random number generator
    srand(time(NULL));

    while (fgets(line, sizeof(line), file)) {
        A3Song *newSong = (A3Song *)malloc(sizeof(A3Song));
        if (newSong == NULL) {
            fclose(file);
            return -1; // Memory allocation failed
        }

        // Parse the song name
        char *token = strtok(line, ",");
        if (token == NULL) {
            free(newSong); // Skip malformed lines
            continue;
        }
        strncpy(newSong->songName, token, MAX_LENGTH - 1);
        newSong->songName[MAX_LENGTH - 1] = '\0'; // Ensure null-termination

        // Parse the 21 notes
        int noteCount = 0;
        for (int i = 0; i < 21; i++) {
            token = strtok(NULL, ",");
            if (token == NULL) {
                // If there are fewer than 21 notes, fill the remaining notes with "N/A"
                strncpy(newSong->songNotes[i], "N/A", NOTE_LENGTH - 1);
            } else {
                strncpy(newSong->songNotes[i], token, NOTE_LENGTH - 1);
            }
            newSong->songNotes[i][NOTE_LENGTH - 1] = '\0'; // Ensure null-termination
        }

        // Generate a unique song ID
        newSong->songId = strlen(newSong->songName) + (rand() % 1000) + 1;
        newSong->nextSong = NULL;

        // Insert the new song at the end of the linked list
        if (*headLL == NULL) {
            *headLL = newSong; // First song in the list
        } else {
            tail->nextSong = newSong; // Append to the end
        }
        tail = newSong; // Update the tail pointer
        songCount++;
    }

    fclose(file);
    return songCount; // Return the number of songs added
}