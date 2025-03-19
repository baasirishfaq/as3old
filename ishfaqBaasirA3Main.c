#include "givenA3.h"
#include <time.h>

int main() {
    A3Song *headLL = NULL;
    int choice;
    char fileName[MAX_LENGTH];
    int songId;
    char songName[MAX_LENGTH];
    char note[4];
    int beginOrEnd;
    int result;

    // Seed the random number generator
    srand(time(NULL));

    do {
        printf("\nMenu:\n");
        printf("1. Create a new playlist\n");
        printf("2. Add a new song to an existing playlist\n");
        printf("3. Play all songs in the given playlist\n");
        printf("4. Play a song from the playlist, given its id\n");
        printf("5. Play a song from the playlist, given its name\n");
        printf("6. Count the number of occurrences of a note in a given song\n");
        printf("7. Delete a song from the playlist, given its id\n");
        printf("8. Delete the entire playlist\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");

        // Validate menu choice input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 9.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the file name (e.g., MusicalTunes.csv): ");
                scanf("%s", fileName);
                result = createPlayList(&headLL, fileName);
                if (result == -1) {
                    printf("Failed to open the file or file is empty.\n");
                } else {
                    printf("Playlist created with %d songs.\n", result);
                }
                break;

            case 2:
                if (headLL == NULL) {
                    printf("Playlist is empty. Please create a playlist first.\n");
                    break;
                }
                printf("Enter 1 to add at the beginning or 2 to add at the end: ");
                if (scanf("%d", &beginOrEnd) != 1 || (beginOrEnd != 1 && beginOrEnd != 2)) {
                    printf("Invalid input. Please enter 1 or 2.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                if (addNewSong(&headLL, beginOrEnd)) {
                    printf("Song added successfully.\n");
                } else {
                    printf("Failed to add the song.\n");
                }
                break;

            case 3:
                if (headLL == NULL) {
                    printf("Playlist is empty.\n");
                } else {
                    playPlayList(headLL);
                }
                break;

            case 4:
                if (headLL == NULL) {
                    printf("Playlist is empty.\n");
                    break;
                }
                printf("Enter the song ID: ");
                if (scanf("%d", &songId) != 1) {
                    printf("Invalid input. Please enter a valid song ID.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                result = playSongGivenId(headLL, songId);
                if (result == -1) {
                    printf("Song not found.\n");
                }
                break;

            case 5:
                if (headLL == NULL) {
                    printf("Playlist is empty.\n");
                    break;
                }
                printf("Enter the song name: ");
                getchar(); // Clear the newline character left by previous scanf
                fgets(songName, MAX_LENGTH, stdin);
                songName[strcspn(songName, "\n")] = '\0'; // Remove the newline character
                result = playSongGivenName(headLL, songName);
                if (result == -1) {
                    printf("Song not found.\n");
                }
                break;

            case 6:
                if (headLL == NULL) {
                    printf("Playlist is empty.\n");
                    break;
                }
                printf("Enter the song ID: ");
                if (scanf("%d", &songId) != 1) {
                    printf("Invalid input. Please enter a valid song ID.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                printf("Enter the note to count: ");
                scanf("%s", note);
                result = countNotesInASong(headLL, songId, note);
                if (result == -1) {
                    printf("Song not found.\n");
                } else {
                    printf("The note %s appears %d times in the song.\n", note, result);
                }
                break;

            case 7:
                if (headLL == NULL) {
                    printf("Playlist is empty.\n");
                    break;
                }
                printf("Enter the song ID: ");
                if (scanf("%d", &songId) != 1) {
                    printf("Invalid input. Please enter a valid song ID.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                result = deleteASongGivenId(&headLL, songId);
                if (result == -1) {
                    printf("Song not found.\n");
                } else {
                    printf("Song deleted successfully.\n");
                }
                break;

            case 8:
                if (headLL == NULL) {
                    printf("Playlist is already empty.\n");
                } else {
                    deletePlayList(&headLL);
                    printf("Playlist deleted successfully.\n");
                }
                break;

            case 9:
                printf("Exiting the program.\n");
                if (headLL != NULL) {
                    deletePlayList(&headLL); // Clean up memory before exiting
                }
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 9.\n");
        }
    } while (choice != 9);

    return 0;
}