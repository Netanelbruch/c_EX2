#include <stdio.h>
#include "my_mat.h"


// void print(int arr[N][N]){
//     for(int i = 0; i<N ; i++)
//         {
//             for (int j = 0; j< N; j++)
//             {
                
//                 printf("%d ", arr[i][j]);
//             }
//             printf("\n");
//         }
// }


int min(int num1, int num2){
    
    if (num1<num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
    
}

int max(int num1, int num2){
    
    if (num1<num2)
    {
        return num2;
    }
    else
    {
        return num1;
    }
    
}


void A(int arr[N][N])
{

    for(int i = 0; i<N ; i++)
    {
        for (int j = 0; j< N; j++)
        {
                
            scanf("%d", &arr[i][j]);
        }

    }


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j==i)
            {
                continue;
            }
            
           for (int k = 0; k < N; k++)
           {
              
                if(k == i || k==j){
                    continue;
                }    

                if ( arr[j][i] == 0 ||  arr[i][k] == 0)
                {
                    continue;
                }

                

                if (arr[j][k] == 0 && j!=k) 
                {
                    arr[j][k] = arr[j][i] + arr[i][k];
                } 

                else{
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]); 
                }
                
                
           }
              
        }
    }

}



void B(int matrix[N][N], int i, int j)
{

     if (matrix[i][j]==0)
    {
         printf("False\n");
    }
    else
    {
       printf("True\n");
    }
   
}



void C(int matrix[N][N], int i, int j)
{

    if (matrix[i][j] == 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", matrix[i][j]);
    }
    
}

int knapsack( int weights[numberOfObjects], int values[numberOfObjects], int chosenObjects[numberOfObjects])
{
    int i, currentCapacity;
    int dpTable[numberOfObjects + 1][knapsackCapacity + 1];

    // Build a table dpTable[][] in a bottom-up manner
    for (i = 0; i <= numberOfObjects; i++) {
        for (currentCapacity = 0; currentCapacity <= knapsackCapacity; currentCapacity++) {
            if (i == 0 || currentCapacity == 0)
                dpTable[i][currentCapacity] = 0;
            else if (weights[i - 1] <= currentCapacity)
                dpTable[i][currentCapacity] = max(values[i - 1] + dpTable[i - 1][currentCapacity - weights[i - 1]], dpTable[i - 1][currentCapacity]);
            else
                dpTable[i][currentCapacity] = dpTable[i - 1][currentCapacity];
        }
    }

    // Find the selected items and calculate the total maximum value
    int maxValue = dpTable[numberOfObjects][knapsackCapacity];
    printf("Maximum value in the Knapsack: %d\n", maxValue);

    currentCapacity = knapsackCapacity;
    int count = 0;

    // Populate the array of chosen objects
    for (i = numberOfObjects; i > 0 && maxValue > 0; i--) {
        if (maxValue != dpTable[i - 1][currentCapacity]) {
            chosenObjects[count++] = i - 1;
            maxValue -= values[i - 1];
            currentCapacity -= weights[i - 1];
        }
    }

    // Print the list of chosen objects
    printf("Selected items:\n");
    for (i = count - 1; i >= 0; i--) {
        int index = chosenObjects[i];
        printf("(Weight: %d kg, Value: %d)\n", weights[index], values[index]);
    }

    return dpTable[numberOfObjects][knapsackCapacity];
}
