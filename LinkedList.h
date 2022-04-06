/*Linked List and its basic opeartions*/

#include<stdio.h>
#include<stdlib.h>
#define LIST_SIZE 4

struct node
{
    int data;
    struct node* link;
};
typedef struct node Node;

Node* CreateNode();
Node* CreateLinkedList();
int InsertIntoLinkedList(Node*, int);
int DeleteFromLinkedList(Node*);
int PrintLinkedList(Node*);
int DeleteLinkedList(Node*);

Node* CreateNode()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = (int)NULL;
    node->link = NULL;
    return node;
}

Node* CreateLinkedList()
{
    return CreateNode();
}

int InsertIntoLinkedList(Node* list, int value)
{
    Node* curr = list;
    while(curr->link != NULL)
    {
        curr = curr->link;
    }
    Node* node = CreateNode();
    node->data = value;
    curr->link = node;
    return 0;
}

int DeleteFromLinkedList(Node* list)
{
    Node* curr = list;
    Node* prev = NULL;
    while(curr->link != NULL)
    {
        prev = curr;
        curr = curr->link;
    }
    prev->link = NULL;
    free(curr);
    return 0;
}

int PrintLinkedList(Node* list)
{
    Node* curr = list;
    printf("| Head | %p |-->", curr->link);
    curr = curr->link;
    while(curr->link != NULL)
    {
        printf("| %d | %p |-->", curr->data, curr->link);
        curr = curr->link;
    }
    printf("| %d | NULL |\n", curr->data);
    return 0;
}

int DeleteLinkedList(Node* list)
{
    Node* curr = list;
    Node* prev = NULL;
    while(curr != NULL)
    {
        prev = curr;
        curr = curr->link;
        free(prev);
    }
    return 0;
}

