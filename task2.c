#include <stdio.h>

#define WIDTH 4
#define HEIGHT 4

// Function to print the image
void printImage(int image[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%3d ", image[i][j]);
        }
        printf("\n");
    }
}

// Function to swap pixels diagonally
void swapPixels(int image[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        int temp = image[i][i];
        image[i][i] = image[i][WIDTH - i - 1];
        image[i][WIDTH - i - 1] = temp;
    }
}

// Function to apply a basic mathematical operation (+key)
void applyMathOperation(int image[HEIGHT][WIDTH], int key) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = (image[i][j] + key) % 256; // Keep pixel in 0-255
        }
    }
}

int main() {
    int image[HEIGHT][WIDTH] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120},
        {130, 140, 150, 160}
    };

    int choice, key;

    printf("Original Image:\n");
    printImage(image);

    printf("\nChoose an encryption method:\n");
    printf("1. Swap diagonal pixels\n");
    printf("2. Apply mathematical operation (add key)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        swapPixels(image);
    } else if (choice == 2) {
        printf("Enter key value (integer): ");
        scanf("%d", &key);
        applyMathOperation(image, key);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("\nEncrypted Image:\n");
    printImage(image);

    return 0;
}
