/*Linked List and its basic opeartions*/

#include<stdio.h>
#include<stdlib.h>
#include<LinkedList.h>
#define LIST_SIZE 4

// struct node
// {
//     int data;
//     struct node* link;
// };
// typedef struct node Node;

// Node* CreateNode();
// Node* CreateLinkedList();
// int InsertIntoLinkedList(Node*, int);
// int DeleteFromLinkedList(Node*);
// //Node* SearchFromLinkedList();
// int PrintLinkedList(Node*);
// int DeleteLinkedList(Node*);

int main()
{
    int i, res;
    Node* list = CreateLinkedList();

    printf("Enter %d list elements: ", LIST_SIZE);
    for(i = 0; i < LIST_SIZE; i += 1)
    {
        scanf("%d", &res);
        InsertIntoLinkedList(list, res);
    }

    printf("The Linked List is: \n");
    PrintLinkedList(list);

    printf("Delete last\n");
    DeleteFromLinkedList(list);
    PrintLinkedList(list);

    DeleteLinkedList(list);
    printf("LinkedList deleted!");
    return 0;
}

// Node* CreateNode()
// {
//     Node* node = (Node*)malloc(sizeof(Node));
//     node->data = (int)NULL;
//     node->link = NULL;
//     return node;
// }

// Node* CreateLinkedList()
// {
//     return CreateNode();
// }

// int InsertIntoLinkedList(Node* list, int value)
// {
//     Node* curr = list;
//     while(curr->link != NULL)
//     {
//         curr = curr->link;
//     }
//     Node* node = CreateNode();
//     node->data = value;
//     curr->link = node;
//     return 0;
// }

// int DeleteFromLinkedList(Node* list)
// {
//     Node* curr = list;
//     Node* prev = NULL;
//     while(curr->link != NULL)
//     {
//         prev = curr;
//         curr = curr->link;
//     }
//     prev->link = NULL;
//     free(curr);
//     return 0;
// }

// int PrintLinkedList(Node* list)
// {
//     Node* curr = list;
//     printf("| Head | %p |-->", curr->link);
//     curr = curr->link;
//     while(curr->link != NULL)
//     {
//         printf("| %d | %p |-->", curr->data, curr->link);
//         curr = curr->link;
//     }
//     printf("| %d | NULL |\n", curr->data);
//     return 0;
// }

// int DeleteLinkedList(Node* list)
// {
//     Node* curr = list;
//     Node* prev = NULL;
//     while(curr != NULL)
//     {
//         prev = curr;
//         curr = curr->link;
//         free(prev);
//     }
//     return 0;
// }

