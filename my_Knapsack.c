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

int main() 
{
    
    char names[numberOfObjects][50];
    int weights[numberOfObjects];
    int values[numberOfObjects];

    // Get user input for objects
    getUserInput(names, weights, values);

    // Array to store the indices of chosen objects
    int chosenObjects[numberOfObjects];

    // Call the knapsack function with user input
    int totalMaxValue = Knapsack( weights, values, chosenObjects);

    printf("Total maximum value of chosen objects: %d\n", totalMaxValue);

    return 0;
}