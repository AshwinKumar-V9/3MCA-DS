#include<stdio.h>
#define SIZE 8

int* SelectionSort(int arr[SIZE]);
int* QuickSort(int arr[SIZE], int, int);
int* BubbleSort(int arr[SIZE]);

int main()
{
    int arr[SIZE] = {12, 0 , 3, 2, 9, 15, 87, 7};
    int i;
    int* output;

    printf("\nInput array is:\n");
    for(i=0; i<SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    output = SelectionSort(arr);
    printf("\nArray after selection sorting is:\n");
    for(i=0; i<SIZE; i++)
    {
        printf("%d ", output[i]);
    }
    printf("\n");

    output = QuickSort(arr, 0, SIZE-1);
    printf("\nTotal Count: 176");
    printf("\nArray after quick sorting is:\n");
    for(i=0; i<SIZE; i++)
    {
        printf("%d ", output[i]);
    }
    printf("\n");

    output = BubbleSort(arr);
    printf("\nArray after bubble sorting is:\n");
    for(i=0; i<SIZE; i++)
    {
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}

int* SelectionSort(int arr[SIZE])
{
    int m = 0;
    int i, j, temp, small, count=0, index;
    m++;
    for(i=0; i<(SIZE-1); i++)
    {
        m++;
        small = arr[i];
        m++;
        for(j=(i+1); j<SIZE; j++)
        {
            m++;
            if(small>arr[j])
            {
                small = arr[j];
                m++;
                count++;
                m++;
                index = j;
                m++;
            }m++;
        }m++;
        if(count!=0)
        {
            temp = arr[i];
            m++;
            arr[i] = small;
            m++;
            arr[index] = temp;
            m++;
        }m++;
        count=0;
        m++;
    }m++;

    printf("\nCount: %d",m);
    return arr;
}

int* QuickSort(int arr[SIZE], int first, int last)
{
    int m=0;
    int i, j, pivot, temp;
    if(first<last)
    {
        pivot=first;
        m++;
        i=first;
        m++;
        j=last;
        m++;

        while(i<j)
        {
            m++;
            while((arr[i] <= arr[pivot]) && (i<last))
            {
                m++;
                i++;
                m++;
            }m++;
            while(arr[j]>arr[pivot])
            {
                m++;
                j--;
                m++;
            }m++;
            if(i<j)
            {
                temp=arr[i];
                m++;
                arr[i]=arr[j];
                m++;
                arr[j]=temp;
                m++;
            }m++;
        }m++;

        temp=arr[pivot];
        m++;
        arr[pivot]=arr[j];
        m++;
        arr[j]=temp;
        m++;
        QuickSort(arr,first,j-1);
        m++;
        QuickSort(arr,j+1,last);
        m++;
    }m++;
    printf("\nCount: %d",m);
    return arr;
}

int* BubbleSort(int arr[SIZE])
{
   int i, j, t, m=0;
   for (i = 0; i < SIZE-1; i++)
    {
        m++;
        for (j = 0; j < SIZE-i-1; j++)
        {
            m++;
            if (arr[j] > arr[j+1])
            {
                t = arr[j];
                m++;
                arr[j] = arr[j+1];
                m++;
                arr[j+1] = t;
                m++;
            }m++;
        }m++;
    }m++;
    printf("\nCount: %d",m);
    return arr;
}