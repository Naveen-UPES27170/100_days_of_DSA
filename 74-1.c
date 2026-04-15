#include <stdio.h>
#include <string.h>

struct Candidate {
    char name[100];
    int votes;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Candidate list[n]; // Array to store unique candidates
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        char currentName[100];
        scanf("%s", currentName);

        int found = 0;
        // Check if candidate is already in our list
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(list[j].name, currentName) == 0) {
                list[j].votes++;
                found = 1;
                break;
            }
        }

        // If candidate is new, add them to the list
        if (!found) {
            strcpy(list[uniqueCount].name, currentName);
            list[uniqueCount].votes = 1;
            uniqueCount++;
        }
    }

    // Determine the winner
    int winnerIdx = 0;
    for (int i = 1; i < uniqueCount; i++) {
        if (list[i].votes > list[winnerIdx].votes) {
            winnerIdx = i;
        } 
        else if (list[i].votes == list[winnerIdx].votes) {
            // Tie-breaker: Lexicographically smaller name
            if (strcmp(list[i].name, list[winnerIdx].name) < 0) {
                winnerIdx = i;
            }
        }
    }

    printf("%s %d\n", list[winnerIdx].name, list[winnerIdx].votes);

    return 0;
}
