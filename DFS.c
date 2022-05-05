#include<stdio.h>
#define GRAPH_SIZE 5

int PrintEdges(int  [][GRAPH_SIZE]);
int DFS(int [][GRAPH_SIZE]);
int inVisited(int*, int);
int traverse(int [][GRAPH_SIZE], int*, int, int);
int CountCycles(int [][GRAPH_SIZE]);
int traverse1(int [][GRAPH_SIZE], int*, int, int);


int main()
{
    int adj_mrx[GRAPH_SIZE][GRAPH_SIZE] = { //0  1  2  3  4
                                    /*0*/   { 0, 1, 0, 0, 1 },
                                    /*1*/   { 1, 0, 1, 1, 1 },
                                    /*2*/   { 0, 1, 0, 0, 1 },
                                    /*3*/   { 0, 1, 0, 0, 1 },
                                    /*4*/   { 1, 1, 1, 1, 0 }};

    int adj_mrx1[GRAPH_SIZE][GRAPH_SIZE] = { //0  1  2  3  4
                                    /*0*/   { 0, 1, 0, 0, 1 },
                                    /*1*/   { 0, 0, 1, 1, 0 },
                                    /*2*/   { 0, 0, 0, 0, 0 },
                                    /*3*/   { 1, 0, 1, 1, 0 },
                                    /*4*/   { 0, 0, 0, 1, 0 }};

    PrintEdges(adj_mrx1);
    DFS(adj_mrx);
    CountCycles(adj_mrx1);

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

int DFS(int adj_mrx[][GRAPH_SIZE])
{
    int i;
    int visited[GRAPH_SIZE] = { 0, 0, 0, 0, 0 };
    int front = 0, rear = 0;

    visited[rear] = 0;
    rear += 1;

    traverse(adj_mrx, visited, front, rear);

    printf("Traverse order: ");
    for(i = 0; i < GRAPH_SIZE; i += 1)
    {
        printf("%d\t", visited[i]);
    }
    printf("\nSearch Complete\n");
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

int traverse(int adj_mrx[][GRAPH_SIZE], int* visited, int x, int rear)
{
    int i, m;
    for(i = 0; i < GRAPH_SIZE; i += 1)
    {
        if(adj_mrx[(visited[x])][i] == 1)
        {
            m = inVisited(visited, i);
            if(m == -1)
            {
                visited[rear] = i;
                rear += 1;
                traverse(adj_mrx, visited, i, rear);
            }
        }
    }
    return 0;
}

int CountCycles(int adj_mrx[][GRAPH_SIZE])
{
    int i, cycles = 0;
    int visited[GRAPH_SIZE] = { 0, 0, 0, 0, 0 };
    int front = 0, rear = 0;

    visited[rear] = 0;
    rear += 1;

    cycles += traverse1(adj_mrx, visited, front, rear);
    printf("Cycles: %d\n", cycles);

    return 0;
}

int traverse1(int adj_mrx[][GRAPH_SIZE], int* visited, int front, int rear)
{
    int i, m, cycle = 0;
    for(i = 0; i < GRAPH_SIZE; i += 1)
    {
        if(adj_mrx[(visited[front])][i] == 1)
        {
            m = inVisited(visited, i);
            if(m == -1)
            {
                visited[rear] = i;
                cycle += traverse1(adj_mrx, visited, (front + 1), (rear + 1));
            }
            else
            {
                cycle += 1;
            }
        }
    }
    return cycle;
}

