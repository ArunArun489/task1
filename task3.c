#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i;
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for(i = 0; i < length; i++) {
        if(isupper(password[i]))
            hasUpper = 1;
        else if(islower(password[i]))
            hasLower = 1;
        else if(isdigit(password[i]))
            hasDigit = 1;
        else
            hasSpecial = 1;
    }

    printf("\nPassword Analysis:\n");
    printf("-------------------\n");
    printf("Length: %d\n", length);
    printf("Contains Uppercase: %s\n", hasUpper ? "Yes" : "No");
    printf("Contains Lowercase: %s\n", hasLower ? "Yes" : "No");
    printf("Contains Digit: %s\n", hasDigit ? "Yes" : "No");
    printf("Contains Special Character: %s\n", hasSpecial ? "Yes" : "No");

    printf("\nPassword Strength: ");

    if(length >= 8 && hasUpper && hasLower && hasDigit && hasSpecial)
        printf("Strong\n");
    else if(length >= 6 && ((hasUpper && hasLower) || (hasLower && hasDigit) || (hasUpper && hasDigit)))
        printf("Moderate\n");
    else
        printf("Weak\n");

    return 0;
}
