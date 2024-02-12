#include <stdio.h>
#include "my_mat.h"

// Function to get user input for objects
void getUserInput(char names[][50], int values[], int weights[]) {
    for (int i = 0; i < 5; i++) {
        printf("Enter the name of Object %d: ", i + 1);
        scanf("%s", names[i]);
        printf("Enter the value of Object %d: ", i + 1);
        scanf("%d", &values[i]);
        printf("Enter the weight of Object %d (in kg): ", i + 1);
        scanf("%d", &weights[i]);
    }
}

int main() {
    char names[5][50];
    int values[5];
    int weights[5];

    // Get user input for objects
    getUserInput(names, values, weights);

    // Array to store the indices of chosen objects
    int selected_bool[5] = {0}; // Initialize all to 0

    // Call the knapSack function with user input
    int totalMaxValue = Knapsack(weights, values, selected_bool);

    printf("Maximum profit: %d\n", totalMaxValue);

    // Print the selected items
    printSelectedItems(names, weights, values, selected_bool);

    return 0;
}