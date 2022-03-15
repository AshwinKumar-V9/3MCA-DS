#include<stdio.h>
#define SIZE 5


struct node
{
    int value;
    struct node* left;
    struct node* right;
};
int InsertValue(struct node*, int);
int PrintTree(struct node*);

int main()
{
    int i, res;
    struct node tree;
    tree.value = 0;
    tree.left = NULL;
    tree.right = NULL;
    struct node* curr = &tree;
    int arr[SIZE] = {2,5,1,2,0};

    for(i = 0; i < SIZE; i += 1)
    {
        //printf("Enter the value: ");
        //scanf("%d", res);
        InsertValue(curr, arr[i]);
    }

    printf("The sorted Binary Tree is: \n");
    PrintTree(curr);
    return 0;
}

int InsertValue(struct node* curr, int res)
{
    if(res < curr->value)
    {
        if(curr->left == NULL)
        {
            struct node left;
            curr->left = &left;
            left.value = res;
            left.left = NULL;
            left.right = NULL;
        }
        else
        {
            InsertValue(curr->left, res);
        }
    }
    else if(res > curr->value)
    {
        if (curr->right == NULL)
        {
            struct node right;
            curr->right = &right;
            right.value = res;
            right.left = NULL;
            right.right = NULL;
        }
        else
        {
            InsertValue(curr->right, res);
        }
    }
    return 0;
}

int PrintTree(struct node* tree)
{
    struct node* curr = tree;
    struct node* prev = NULL;
    do
    {
        while(curr->left != NULL)
        {
            prev = curr;
            curr = curr->left;
        }
        printf("%d ", curr->value);
        if(curr->right != NULL)
        {
            prev = curr;
            curr = curr->right;
            PrintTree(curr);
            curr = prev;
        }
        curr = prev;
    }while(curr != NULL);

    // printf("%d ", curr->value);
    // if(curr->right != NULL)
    // {
    //     prev = curr;
    //     curr = curr->right;
    //     PrintTree(curr);
    // }
    // curr = prev;

    return 0;
}