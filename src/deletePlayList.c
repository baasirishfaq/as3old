#include "givenA3.h"

void deletePlayList(A3Song **headLL) {
    A3Song *current = *headLL;
    A3Song *next;

    while (current != NULL) {
        next = current->nextSong;
        free(current);
        current = next;
    }

    *headLL = NULL;
}