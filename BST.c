#include<stdio.h>
#include<stdlib.h>
#define TREE_SIZE 7

struct node
{
    int value;
    struct node* left;
    struct node* right;
    struct node* parent;
};
typedef struct node Node;

Node* CreateNode();
Node* CreateBST();
int Insert(Node*, int);
int PrintTree(Node*, int*, int*);
int Inorder(Node*, int*, int*);
int Preorder(Node*, int*, int*);
int Postorder(Node*, int*, int*);
int FindNum(int*, int);

int main()
{
    int input;
    Node* tree = CreateBST();
    int list[TREE_SIZE];
    int rear = 0;
    PrintTree(tree, list, &rear);

    printf("\nEnter number to search: ");
    scanf("%d", &input);
    FindNum(list, input);

    return 0;
}

int PrintTree(Node* tree, int* list, int* rear)
{
    int i;
    printf("\nThe Preorder of BST is: ");
    Preorder(tree, list, rear);

    for(i = 0; i < TREE_SIZE; i += 1)
    {
        printf("%d -> ", list[i]);
    }

    (*rear) = 0;
    printf("\nThe Postorder of BST is: ");
    Postorder(tree, list, rear);

    for(i = 0; i < TREE_SIZE; i += 1)
    {
        printf("%d -> ", list[i]);
    }

    (*rear) = 0;
    printf("\nThe Inorder of BST is: ");
    Inorder(tree, list, rear);

    for(i = 0; i < TREE_SIZE; i += 1)
    {
        printf("%d -> ", list[i]);
    }
    return 0;
}

int Inorder(Node* tree, int* list, int* rear)
{
    if(tree->left != NULL)
    {
        Inorder(tree->left, list, rear);
    }
    list[(*rear)] = tree->value;
    (*rear) += 1;
    if(tree->right != NULL)
    {
        Inorder(tree->right, list, rear);
    }
    return 0;
}
int Preorder(Node* tree, int* list, int* rear)
{
    if(tree->left != NULL)
    {
        list[(*rear)] = tree->value;
        (*rear) += 1;
        Preorder(tree->left, list, rear);
        Preorder(tree->right, list, rear);
        return 0;
    }
    list[(*rear)] = tree->value;
    (*rear) += 1;

    return 0;
}
int Postorder(Node* tree, int* list, int* rear)
{
    if(tree->left != NULL)
    {
        Postorder(tree->left, list, rear);
        Postorder(tree->right, list, rear);
        list[(*rear)] = tree->value;
        (*rear) += 1;
        return 0;
    }
    list[(*rear)] = tree->value;
    (*rear) += 1;

    return 0;
}

Node* CreateNode()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->value = 0;
    return node;
}

Node* CreateBST()
{
    int i, input;
    Node* tree = CreateNode();
    printf("Enter value: ");
    scanf("%d", &input);
    tree->value = input;
    printf("Inserted %d\n", input);

    for(i = 0; i < (TREE_SIZE - 1); i += 1)
    {
        printf("Enter value: ");
        scanf("%d", &input);
        Insert(tree, input);
    }

    return tree;
}

int Insert(Node* tree, int input)
{
    Node* curr = tree;
    if(input < curr->value)
    {
        if(curr->left == NULL)
        {
            Node* node = CreateNode();
            node->value = input;
            node->parent = curr;
            curr->left = node;
            printf("Inserted %d\n", input);
            return 0;
        }
        curr = curr->left;
        Insert(curr, input);
    }
    else if(input > curr->value)
    {
        if(curr->right == NULL)
        {
            Node* node = CreateNode();
            node->value = input;
            node->parent = curr;
            curr->right = node;
            printf("Inserted %d\n", input);
            return 0;
        }
        curr = curr->right;
        Insert(curr, input);
    }
    return 0;
}

int FindNum(int* list, int num)
{
    int i;
    if(list[0] > num)
    {
        printf("Floor: null - Ceil: %d\n", list[0]);
        return 0;
    }
    for(i = 0; i < TREE_SIZE; i += 1)
    {
        if(list[i] == num)
        {
            printf("Number found\n");
            return 0;
        }
        else if(list[i] > num)
        {
            printf("Floor: %d - Ceil: %d\n", list[i-1] ,list[i]);
            return 0;
        }
    }
    printf("Floor: %d - Ceil: null\n", list[i-1]);
    return 0;
}