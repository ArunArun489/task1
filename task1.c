#include <stdio.h>
#include <string.h>

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        message[i] = ch;
    }
}

void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' - shift + 26) % 26) + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' - shift + 26) % 26) + 'A';
        }
        message[i] = ch;
    }
}

int main() {
    char message[1000];
    int shift, choice;

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline

    printf("Enter shift value: ");
    scanf("%d", &shift);

    printf("Choose:\n1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(message, shift);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, shift);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
