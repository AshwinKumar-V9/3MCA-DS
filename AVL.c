#include<stdio.h>
#include<stdlib.h>
#define TREE_SIZE 5

struct node{
    int value;
    int balance;
    struct node* left;
    struct node* right;
    struct node* parent;
};
typedef struct node Node;

Node* CreateNode();
Node* CreateBST();
int Insert(Node*, int, char*);
int CheckBalance(Node*, int*, int*, char*);
Node* Rotate(Node*, char*);
int Preorder(Node*);

int main()
{
    Node* tree = CreateBST();
    printf("\nThe Preorder of BST is: ");
    Preorder(tree);
    return 0;
}

Node* CreateNode()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->value = 0;
    node->balance = 0;
    return node;
}

Node* CreateBST()
{
    int i, input;
    char list[2] = {' ', ' '};
    Node* tree = CreateNode();
    printf("Enter value: ");
    scanf("%d", &input);
    tree->value = input;
    printf("Inserted %d\n", input);

    for(i = 0; i < (TREE_SIZE - 1); i += 1)
    {
        int left = 0, right = 0, j;
        printf("Enter value: ");
        scanf("%d", &input);
        Insert(tree, input, list);
        CheckBalance(tree, &left, &right, list);

        printf("[ %c, %c ]\n", list[0], list[1]);
        list[0] = ' ';
        list[1] = ' ';
    }

    return tree;
}

int Insert(Node* tree, int input, char* list)
{
    Node* curr = tree;
    if(input < curr->value)
    {
        list[0] = list[1];
        list[1] = 'L';
        if(curr->left == NULL)
        {
            Node* node = CreateNode();
            node->value = input;
            node->parent = curr;
            curr->left = node;
            printf("Inserted %d\n", input);
            return 0;
        }
        Insert(curr->left, input, list);
    }
    else if(input > curr->value)
    {
        list[0] = list[1];
        list[1] = 'R';
        if(curr->right == NULL)
        {
            Node* node = CreateNode();
            node->value = input;
            node->parent = curr;
            curr->right = node;
            printf("Inserted %d\n", input);
            return 0;
        }
        Insert(curr->right, input, list);
    }
    return 0;
}

int CheckBalance(Node* tree, int* left, int* right, char* list)
{
    if(tree->left != NULL)
    {
        CheckBalance(tree->left, left, right, list);
        (*left) = (*right) + 1;
        (*right) = 0;
    }
    tree->balance = (*left);
    if(tree->right != NULL)
    {
        (*left) = 0;
        CheckBalance(tree->right, left, right, list);
        (*right) += 1;
    }
    tree->balance -= (*right);
    if((tree->balance > 1) || (tree->balance < -1)){
        printf("Imbalance: %d node has balance %d\n", tree->value, tree->balance);
        //Rotate(tree, list);
    }
    return 0;
}

Node* Rotate(Node* tree, char* list)
{
    Node* temp;
    Node* root;
    if((list[0] == 'L') && (list[1] == 'R'))
    {
        root = tree->left->right;
        root->parent = tree->parent;
        if(tree->parent != NULL)
        {
            if(tree->parent->left == tree)
            {
                tree->parent->left = root;
            }
            else
            {
                tree->parent->right = root;
            }
        }

        root->left = tree->left;
        root->left->parent = root;
        root->left->right = NULL;

        root->right = tree;
        root->right->parent = root;
        root->right->left = NULL;
    }
    return root;
}

int Preorder(Node* tree)
{
    printf("%d (b: %d)-> ", tree->value, tree->balance);
    if(tree->left != NULL)
    {
        Preorder(tree->left);
    }
    if(tree->right != NULL)
    {
        Preorder(tree->right);
    }
    return 0;
}