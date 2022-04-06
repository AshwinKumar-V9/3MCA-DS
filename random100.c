#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 100

int LinearSearch(int*);
int BinarySearch(int*);
int QuickSort(int*, int, int);

int main()
{
	int i,j, arr[SIZE];
	for(i = 0;i < SIZE; i += 1) //100 iterations
	{
		arr[i] = rand() % 200 + 1; //random number between 1-200
	}

	//print arr
	printf("The arr values are:");
	for(i = 0;i < SIZE; i += 1)
	{
		if((i % 10) == 0)
		{
			printf("\n");
		}
		printf("%d\t", arr[i]);
	}
	printf("\n\n");

	LinearSearch(arr);
    BinarySearch(arr);

	return 0;
}

//100 random numbers searched in arr[]
int LinearSearch(int* arr)
{
	int i, j, search, search_count = 0, successful = 0, count,sum = 0, percent, avg_search;
	for(i = 0;i < SIZE; i += 1)
	{
		count = 0;
		search_count += 1;
		search = rand() % 200 + 1; //random search number

		//linear search
		for(j = 0;j < SIZE; j += 1)
		{
			count += 1;
			if(arr[j] == search)
			{
				successful += 1;
				break;
			}
		}
		sum += count;
	}
	avg_search = sum/ search_count;
	percent = (successful * SIZE)/search_count;
	printf("Linear Search \nTotal Search: %d\nSuccessful Searches: %d\nPercentage of successful searches: %d\nAverage search count:%d\n\n", search_count, successful, percent, avg_search);
}

int BinarySearch(int* arr)
{
    int i, first, last, middle, search, search_count = 0, successful = 0, count,sum = 0, percent, avg_search;

    QuickSort(arr, 0, SIZE-1);
    //print sorted arr
	printf("The sorted arr values are:");
	for(i = 0;i < SIZE; i += 1)
	{
		if((i % 10) == 0)
		{
			printf("\n");
		}
		printf("%d\t", arr[i]);
	}
	printf("\n\n");

    for(i = 0;i < SIZE; i += 1)
	{
		count = 0;
		search_count += 1;
		search = rand() % 200 + 1; //random search number

        first = 0;
        last = SIZE - 1;
        while (first <= last)
        {
            count += 1;
            middle = (first+last)/2;
            if(arr[middle] < search)
            {
                first = middle + 1;
            }
            else if(arr[middle] == search)
            {
                successful += 1;
                break;
            }
            else
            {
                last = middle - 1;
            }
        }
		sum += count;
	}
	avg_search = sum/ search_count;
	percent = (successful * SIZE)/search_count;
	printf("Binary Search \nTotal Search: %d\nSuccessful Searches: %d\nPercentage of successful searches: %d\nAverage search count:%d\n", search_count, successful, percent, avg_search);

    return 0;
}

int QuickSort(int* arr, int first, int last)
{
    int i, j, pivot, temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while((arr[i] <= arr[pivot]) && (i<last))
            {
                i++;
            }
            while(arr[j]>arr[pivot])
            {
                j--;
            }
            if(i<j)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }

        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        QuickSort(arr,first,j-1);
        QuickSort(arr,j+1,last);
    }
    return 0;
}
