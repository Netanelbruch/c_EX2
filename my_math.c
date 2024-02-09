#include <stdio.h>
#include "my_math.h"



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
