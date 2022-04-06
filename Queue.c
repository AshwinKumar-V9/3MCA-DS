#include<stdio.h>
#include<stdlib.h>

int* CreateQueue(int);
int Enqueue(int*, int*, int*, int, int);
int Dequeue(int*, int*, int);
int FindSum(int*, int*, int*, int);
int RemoveNegative(int*, int*, int*, int);

int main()
{
    int front = -1, rear = -1, sum, input, i, size;
    float avg;
    printf("Enter the no of elements: ");
    scanf("%d", &size);
    int* queue = CreateQueue(size);

    //input queue
    printf("Enter the elements: ");
    while(rear < (size-1))
    {
        scanf("%d", &input);
        Enqueue(queue, &front, &rear, size, input);
    }
    printf("Queue full!\n");

    //print queue
    printf("The queue is: ");
    for(i = front; i <= rear; i += 1)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");

    sum = FindSum(queue, &front, &rear, size);
    avg = (float)sum/size;

    printf("The sum is %d and average is %.2f \n", sum, avg);

    RemoveNegative(queue, &front, &rear, size);
    //print queue
    printf("The queue is: ");
    for(i = front; i <= rear; i += 1)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");

    free(queue);
    return 0;
}

int* CreateQueue(int size)
{
    int* queue = (int*)malloc(size * sizeof(int));
    return queue;
}

int Enqueue(int* queue, int* front, int* rear, int size, int value)
{
    if((*rear) == -1)
    {
        (*front) += 1;
    }
    (*rear) = (((*rear) + 1) % size);
    queue[(*rear)] = value;
    printf("%d inserted to queue \n", value);
    return 0;
}

int Dequeue(int* queue, int* front, int size)
{
    int value = queue[(*front)];
    (*front) = (((*front) + 1) % size);
    printf("%d popped from queue \n", value);
    return value;
}

int FindSum(int* queue, int* front, int* rear, int size)
{
    int i, sum = 0, out, count = 0;
    while(count < size)
    {
        out = Dequeue(queue, front, size);
        sum += out;
        Enqueue(queue, front, rear, size, out);
        count += 1;
    }
    return sum;
}

int RemoveNegative(int* queue, int* front, int* rear, int size)
{
    int i, out, count = 0;
    while(count < size)
    {
        out = Dequeue(queue, front, size);
        if(out < 0)
        {
            count += 1;
            continue;
        }
        Enqueue(queue, front, rear, size, out);
        count += 1;
    }
    return 0;
}