#include <stdio.h>
#include <string.h>

char findFirstNonRepeating(char* s) {
    int count[26] = {0}; // Frequency array for 'a'-'z'
    int n = strlen(s);

    // Step 1: Fill the frequency array
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    // Step 2: Find the first character with a count of 1
    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    // Step 3: If no unique character is found
    return '$';
}

int main() {
    char s[100001]; // Assuming a maximum string length
    if (scanf("%s", s) == 1) {
        printf("%c\n", findFirstNonRepeating(s));
    }
    return 0;
}
