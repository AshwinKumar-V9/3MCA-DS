/*This is a linked list where the node following a node with negative key is removed*/

#include<stdio.h>
#include<LinkedList.h>
#define SIZE 10

int DeleteAfterNegative(Node*);

int main()
{
    int i, res;
    Node* list = CreateLinkedList();

    printf("Enter %d list elements: ", SIZE);
    for(i = 0; i < SIZE; i += 1)
    {
        scanf("%d", &res);
        InsertIntoLinkedList(list, res);
    }
    printf("The linked list is: \n");
    PrintLinkedList(list);

    DeleteAfterNegative(list);
    printf("List after deletion: \n");
    PrintLinkedList(list);

    DeleteLinkedList(list);
    return 0;
}

int DeleteAfterNegative(Node* list)
{
    Node* curr = list;
    while(curr->link != NULL)
    {
        if(curr->data < 0)
        {
            Node* next = curr->link;
            curr->link = next->link;
            next->link = NULL;
            free(next);
        }
        curr = curr->link;
    }
    return 0;
}