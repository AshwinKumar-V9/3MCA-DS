#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 10

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* CreateStack();
struct node* Push(struct node*, struct node*, int);
struct node* Pop(struct node*, struct node*);
int PrintStack(struct node*);
int DeleteStack(struct node*, struct node*);

int main()
{
    struct node* stack = CreateStack();
    struct node* top = stack;
    int i, res;
    //int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Enter 10 elements: ");
    for(i = 0; i < STACK_SIZE; i += 1)
    {
        scanf("%d", &res);
        top = Push(stack, top, res);
    }

    PrintStack(stack);
    top = Pop(stack, top);
    PrintStack(stack);
    free(stack);
    return 0;
}

struct node* CreateStack()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;
    return head;
}

struct node* Push(struct node* stack, struct node* top, int value)
{
    struct node* s_node = (struct node*)malloc(sizeof(struct node));
    s_node->data = value;
    s_node->prev = top;
    s_node->next = NULL;

    top->next = s_node;
    top = s_node;
    printf("%d pushed onto stack.\n", value);
    return top;
}

struct node* Pop(struct node* stack, struct node* top)
{
    int res = top->data;
    top = top->prev;
    free(top->next);
    top->next = NULL;
    printf("Popped value: %d\n", res);
    return top;
}

int PrintStack(struct node* stack)
{
    struct node* curr;
    curr = stack;
    printf("The stack elements are: ");
    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    return 0;
}

int DeleteStack(struct node* stack, struct node* top)
{
    struct node* curr = top;
    while(curr != NULL)
    {
        curr = top->prev;
        free(top);
    }
    printf("\n");
    return 0;
}