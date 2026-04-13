#include <stdio.h>
#include <string.h>

int main() {
    char s[100001]; // Adjust size based on expected constraints
    int visited[26] = {0}; // Initialize all elements to 0
    
    // Read input string
    if (scanf("%s", s) == 1) {
        int found = 0;
        
        for (int i = 0; s[i] != '\0'; i++) {
            // Map character 'a'-'z' to index 0-25
            int index = s[i] - 'a';
            
            // If we have seen this character before
            if (visited[index] > 0) {
                printf("%c\n", s[i]);
                found = 1;
                break; 
            }
            
            // Mark character as seen
            visited[index]++;
        }
        
        if (!found) {
            printf("-1\n");
        }
    }
    
    return 0;
}
