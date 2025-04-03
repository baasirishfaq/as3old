#include "givenA3.h"

int deleteASongGivenId(A3Song **headLL, int givenSongId) {
    A3Song *current = *headLL;
    A3Song *previous = NULL;

    while (current != NULL) {
        if (current->songId == givenSongId) {
            if (previous == NULL) {
                *headLL = current->nextSong;
            } else {
                previous->nextSong = current->nextSong;
            }
            free(current);
            return 1;
        }
        previous = current;
        current = current->nextSong;
    }
    return -1;
}