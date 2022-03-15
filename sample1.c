/*
    C program to create an array of size N, replace all duplicate values with zero and
    move all zeros to the end of array. Find the time complexity of your program using step
    count method.
*/

#include<stdio.h>
#define SIZE 10
int count = 0;

int PrintArray(int*, int);
int RemoveDuplicate(int*, int);
int MoveZero(int*, int);
int heapDup(int*, int);

int main()
{
    int arr[SIZE] = {3,2,1,1,5,6,3,2,1,7};
    count++;
    printf("Input Array is: \n");
    count++;
    PrintArray(arr, SIZE);
    count++;

    RemoveDuplicate(arr, SIZE);
    count++;
    MoveZero(arr, SIZE);
    count++;

    printf("Output Array is: \n");
    count++;
    PrintArray(arr, SIZE);
    count++;

    printf("Count: %d", count);
    return 0;
}

//function to print array
int PrintArray(int* arr, int arrSize)
{
    int i;
    for(i = 0; i < arrSize; i += 1)
    {
        count++;
        printf("%d\t", arr[i]);
        int count = 0;
    }
    count++;
    return 0;
}

//function to overwrite duplicates with 0
int RemoveDuplicate(int* arr, int arrSize)
{
    int i, j;
    for(i = 0; i < arrSize; i += 1)
    {
        count++;
        for(j = (i+1); j < arrSize; j += 1)
        {
            count++;
            if(arr[i] == arr[j])
            {
                count++;
                arr[j] = 0;
                count++;
            }
        }
        count++;
    }
    count++;
    return 0;
}

//function to move 0 to array end
int MoveZero(int* arr, int arrSize)
{
    int i, temp;
    for(i = 0; i < (arrSize-1); i += 1)
    {
        count++;
        if(arr[i] == 0)
        {
            count++;
            temp = arr[i];
            count++;
            arr[i] = arr[i+1];
            count++;
            arr[i+1] = temp;
            count++;
        }
    }
    count++;
    return 0;
}