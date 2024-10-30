#include <stdio.h>

int main() {
    int length;
    int width;

    // Ask for the dimensions of the array
    printf("Enter length of the array: ");
    scanf("%d", &length);

    printf("Enter width of the array: ");
    scanf("%d", &width);

    // Declare the array with the correct size
    int a[length][width];

    // Prompt user to enter the numbers
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            printf("Element at [%d][%d]: ", i, j); // Prompt for each element
            scanf("%d", &a[i][j]);  // Read each element into the array
        }
    }

    // Display the array elements
    printf("Array elements are:\n");
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Find the largest element
    int largest = a[0][0]; // Initialize largest with the first element

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            if (a[i][j] > largest) {
                largest = a[i][j];
            }
        }
    }

    // Display the largest element
    printf("Largest element = %d\n", largest);

    return 0;
}
