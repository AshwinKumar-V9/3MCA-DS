#include<stdio.h>
#include<LinkedList.h>
#define ROW_SIZE 3
#define COL_SIZE 3

struct colnode
{
    struct colnode* down_link;
    Node* right_link;
};
typedef struct colnode ColNode;

ColNode* CreateColumnNode();
ColNode* CreateLinkedMatrix(int, int);
int PrintLinkedMatrix(ColNode*);
int DeleteLinkedMatrix(ColNode*);

int main()
{
    ColNode* matrix = CreateLinkedMatrix(ROW_SIZE, COL_SIZE);

    printf("The linked matrix is: \n");
    PrintLinkedMatrix(matrix);

    DeleteLinkedMatrix(matrix);
    return 0;
}

ColNode* CreateColumnNode()
{
    ColNode* node = (ColNode*)malloc(sizeof(ColNode));
    node->down_link = NULL;
    node->right_link = NULL;
    return node;
}

ColNode* CreateLinkedMatrix(int row, int col)
{
    int i, j, res;
    ColNode* matrix = CreateColumnNode();
    ColNode* curr_row = matrix;

    printf("Enter %d x %d matrix elements: ", row, col);
    for(i = 0; i < row; i += 1)
    {
        //create new row list
        Node* list = CreateLinkedList();
        for(j = 0; j < col; j += 1)
        {
            scanf("%d", &res);
            InsertIntoLinkedList(list, res);
        }

        //add row list to row index
        curr_row->right_link = list->link;
        free(list);

        //point row index to next row
        ColNode* row = CreateColumnNode();
        curr_row->down_link = row;
        curr_row = row;
    }
    return matrix;
}

int PrintLinkedMatrix(ColNode* matrix)
{
    Node* curr_col;
    ColNode* curr_row = matrix;

    while(curr_row->down_link != NULL)
    {
        printf("| %p | %p |-->",curr_row->down_link, curr_row->right_link);
        curr_col = curr_row->right_link;
        while(curr_col->link != NULL)
        {
            printf("| %d | %p |-->",curr_col->data, curr_col->link);
            curr_col = curr_col->link;
        }
        printf("| %d | NULL |\n",curr_col->data);
        curr_row = curr_row->down_link;
    }
    return 0;
}

int DeleteLinkedMatrix(ColNode* matrix)
{
    Node* curr_col;
    Node* prev_col = NULL;
    ColNode* curr_row = matrix;
    ColNode* prev_row = NULL;

    while(curr_row->down_link != NULL)
    {
        //delete row
        curr_col = curr_row->right_link;
        while(curr_col != NULL)
        {
            prev_col = curr_col;
            curr_col = curr_col->link;
            free(prev_col);
        }
        prev_row = curr_row;
        curr_row = curr_row->down_link;
        free(prev_row);
    }
    return 0;
}