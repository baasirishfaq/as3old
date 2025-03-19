#include "givenA3.h"

bool addNewSong(A3Song **headLL, int beginOrEnd) {
    A3Song *newSong = (A3Song *)malloc(sizeof(A3Song));
    if (newSong == NULL) {
        return false;
    }

    printf("Enter the song name: ");
    scanf("%s", newSong->songName);

    newSong->songId = strlen(newSong->songName) + (rand() % 1000) + 1;

    for (int i = 0; i < 21; i++) {
        int noteIndex = rand() % 7;
        char *notes[] = {"do", "re", "mi", "fa", "sol", "la", "ti"};
        strncpy(newSong->songNotes[i], notes[noteIndex], NOTE_LENGTH);
    }

    if (beginOrEnd == 1) {
        newSong->nextSong = *headLL;
        *headLL = newSong;
    } else {
        newSong->nextSong = NULL;
        if (*headLL == NULL) {
            *headLL = newSong;
        } else {
            A3Song *temp = *headLL;
            while (temp->nextSong != NULL) {
                temp = temp->nextSong;
            }
            temp->nextSong = newSong;
        }
    }

    return true;
}