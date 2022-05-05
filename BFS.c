#include<stdio.h>
#define GRAPH_SIZE 5

int PrintEdges(int  [][GRAPH_SIZE]);
int BFS(int [][GRAPH_SIZE]);
int inVisited(int*, int);

int main()
{
    //undirected graph for BFS
    int adj_mrx[GRAPH_SIZE][GRAPH_SIZE] = { //0  1  2  3  4
                                    /*0*/   { 0 ,1, 0, 0, 1 },
                                    /*1*/   { 1, 0, 1, 1, 1 },
                                    /*2*/   { 0, 1, 0, 1, 0 },
                                    /*3*/   { 0, 1, 1, 0, 1 },
                                    /*4*/   { 1, 1, 0, 1, 0 }};

    //directed graph for cycles
    int adj_mrx2[GRAPH_SIZE][GRAPH_SIZE] = {//0  1  2  3  4
                                    /*0*/   { 0, 1, 0, 1, 0 },
                                    /*1*/   { 0, 0, 1, 0, 1 },
                                    /*2*/   { 1, 0, 0, 0, 1 },
                                    /*3*/   { 0, 0, 1, 0, 0 },
                                    /*4*/   { 0, 0, 0, 0, 0 }};

    PrintEdges(adj_mrx);
    BFS(adj_mrx);
    //CountCycles(adj_mrx2);

    return 0;
}

int PrintEdges(int adj_mrx[][GRAPH_SIZE])
{
    int i, j;
    printf("The edges are: \n");
    for(i = 0; i < GRAPH_SIZE; i += 1)
    {
        for(j = 0; j < GRAPH_SIZE; j += 1)
        {
            if(adj_mrx[i][j] == 1)
            {
                printf("<%d, %d>\t", i, j);
            }
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

int BFS(int adj_mrx[][GRAPH_SIZE])
{
    int i, m;
    int visited[GRAPH_SIZE] = { 0, 0, 0, 0, 0 };
    int front = 0, rear = 0;

    visited[rear] = 0;
    rear += 1;

    while(1)
    {
        for(i = 0; i < GRAPH_SIZE; i += 1)
        {
            if(adj_mrx[(visited[front])][i] == 1)
            {
                m = inVisited(visited, i);
                if(m == -1)
                {
                    visited[rear] = i;
                    rear += 1;
                }
            }
        }
        front += 1;
        if(front == GRAPH_SIZE)
        {
            printf("Traverse order: ");
            for(i = 0; i < GRAPH_SIZE; i += 1)
            {
                printf("%d\t", visited[i]);
            }
            printf("\nSearch Complete\n");
            return 0;
        }
    }
    return 1;
}

int inVisited(int* visited, int x)
{
    int i;
    for(i = 0; i < GRAPH_SIZE; i += 1)
    {
        if(x == visited[i])
        {
            return i;
        }
    }
    return -1;
}