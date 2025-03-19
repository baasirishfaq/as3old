#include "givenA3.h"

int playSongGivenName(A3Song *headLL, char givenSongName[MAX_LENGTH]) {
    A3Song *current = headLL;
    while (current != NULL) {
        if (strcmp(current->songName, givenSongName) == 0) {
            printf("Song ID: %d\n", current->songId);
            printf("Song Name: %s\n", current->songName);
            printf("Notes: ");
            for (int i = 0; i < 21; i++) {
                printf("%s.", current->songNotes[i]);
            }
            printf("\n");
            return 1;
        }
        current = current->nextSong;
    }
    return -1;
}