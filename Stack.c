#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 10

int* CreateStack(int);
int Push(int*, int*, int);
int Pop(int*, int*);
int PrintStack(int*, int*);

int main()
{
    int* stack = CreateStack(STACK_SIZE);
    int top = -1;
    int i, res;

    printf("Enter 10 elements: ");
    scanf("%d", &res);
    while(!(Push(stack, &top, res)))
    {
        scanf("%d", &res);
    }

    PrintStack(stack, &top);
    Pop(stack, &top);
    PrintStack(stack, &top);
    free(stack);
    return 0;
}

int* CreateStack(int size)
{
    int* stack = (int*)malloc(size * sizeof(int));
    return stack;
}

int Push(int* stack, int* top, int value)
{
    if((*top) == (STACK_SIZE-1))
    {
        printf("Stack Overflow.\n");
        return 1;
    }
    (*top) += 1;
    stack[(*top)] = value;
    printf("%d pushed onto stack.\n", value);
    return 0;
}

int Pop(int* stack, int* top)
{
    int res = stack[(*top)];
    (*top) -= 1;
    printf("Popped value: %d\n", res);
    return res;
}

int PrintStack(int* stack, int* top)
{
    int i;
    printf("The stack elements are: ");
    for(i = 0; i <= (*top); i += 1)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
    return 0;
}