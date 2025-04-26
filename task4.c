#include <stdio.h>
#include <string.h>

int main() {
    char logs[1000] = ""; // Empty string to store keystrokes
    char input[100];

    printf("Simple Keylogger Started...\n");
    printf("Type your text below (type 'EXIT' to stop):\n");

    while (1) {
        fgets(input, sizeof(input), stdin);

        // Remove newline
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "EXIT") == 0) {
            printf("\nStopping Keylogger...\n");
            break;
        }

        strcat(logs, input);   // Add input to logs
        strcat(logs, "\n");    // Add newline after each input
    }

    printf("\nLogged Keystrokes:\n");
    printf("-------------------\n");
    printf("%s", logs);

    return 0;
}
