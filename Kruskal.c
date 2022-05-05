#include<stdio.h>
#define GRAPH_SIZE 5
#define EDGE_SIZE 7

struct edge
{
    int u;
    int v;
    int weight;
};
typedef struct edge Edge;


int PrintEdges(int  [][GRAPH_SIZE], Edge*);
int inSortedEdges(int, int, Edge*, int);
int sortEdges(Edge*, int);
int calculateMinSpanTree(Edge* ,int, int [][GRAPH_SIZE]);
int inVisited(int*, int);
int checkCycles(int [][GRAPH_SIZE]);
int traverse1(int [][GRAPH_SIZE], int*, int, int);
int PrintEdges2(int [][GRAPH_SIZE]);

int main()
{
    //undirected weighted graph
    int adj_mrx[GRAPH_SIZE][GRAPH_SIZE] = { //0  1  2  3  4
                                    /*0*/   { 0 ,10, 0, 18, 0 },
                                    /*1*/   { 10, 0, 14, 0, 8 },
                                    /*2*/   { 12, 14, 0, 16, 20 },
                                    /*3*/   { 18, 0, 16, 0, 0 },
                                    /*4*/   { 0, 8, 20, 0, 0 }};

    int adj_mrx1[GRAPH_SIZE][GRAPH_SIZE] = { //0  1  2  3  4
                                    /*0*/   { 0, 0, 0, 0, 0 },
                                    /*1*/   { 0, 0, 0, 0, 0 },
                                    /*2*/   { 0, 0, 0, 0, 0 },
                                    /*3*/   { 0, 0, 0, 0, 0 },
                                    /*4*/   { 0, 0, 0, 0, 0 }};
    Edge sortedEdges[EDGE_SIZE * 2];
    int size;

    size = PrintEdges(adj_mrx, sortedEdges);
    calculateMinSpanTree(sortedEdges, size, adj_mrx1);
    return 0;
}

int PrintEdges(int adj_mrx[][GRAPH_SIZE], Edge* sortedEdges)
{
    int i, j, m = 0;
    for(i = 0; i < GRAPH_SIZE; i += 1)
    {
        for(j = 0; j < GRAPH_SIZE; j += 1)
        {
            if(adj_mrx[i][j] > 0)
            {
                if(inSortedEdges(i, j, sortedEdges, m))
                {
                    continue;
                }
                sortedEdges[m].u = i;
                sortedEdges[m].v = j;
                sortedEdges[m].weight = adj_mrx[i][j];
                m += 1;
            }
        }
    }
    sortEdges(sortedEdges, m);
    return m;
}

int inSortedEdges(int i, int j, Edge* sortedEdges, int size)
{
    int x;
    for(x = 0; x < size; x += 1)
    {
        if((sortedEdges[x].u == j) && (sortedEdges[x].v == i))
        {
            return 1;
        }
    }
    return 0;
}

int sortEdges(Edge* sortedEdges, int size)
{
    int i, j;
    Edge temp;
    for(i = 0; i < (size - 1); i += 1)
    {
        for(j = 0; j < (size - i - 1); j += 1)
        {
            if(sortedEdges[j].weight > sortedEdges[j + 1].weight)
            {
                temp.u =  sortedEdges[j].u;
                temp.v =  sortedEdges[j].v;
                temp.weight =  sortedEdges[j].weight;

                sortedEdges[j].u = sortedEdges[j + 1].u;
                sortedEdges[j].v = sortedEdges[j + 1].v;
                sortedEdges[j].weight = sortedEdges[j + 1].weight;

                sortedEdges[j + 1].u = temp.u;
                sortedEdges[j + 1].v = temp.v;
                sortedEdges[j + 1].weight = temp.weight;
            }
        }
    }

    printf("Sorted edges are: \n");
    for(i = 0; i < size; i += 1)
    {
        printf("(%d, %d) - %d\n", sortedEdges[i].u, sortedEdges[i].v, sortedEdges[i].weight);
    }
    printf("\n");
    return 0;
}

int calculateMinSpanTree(Edge* sortedEdges, int size, int adj_mrx[][GRAPH_SIZE])
{
    int i, cycles = 0, m, n;
    for(i = 0; i < size; i += 1)
    {
        adj_mrx[sortedEdges[i].u][sortedEdges[i].v] = sortedEdges[i].weight;
        cycles = checkCycles(adj_mrx);
        if(cycles > 0)
        {
            adj_mrx[sortedEdges[i].u][sortedEdges[i].v] = 0;
        }
        for(m = 0; m < GRAPH_SIZE; m += 1)
        {
            for(n = 0; n < GRAPH_SIZE; n += 1)
            {
                printf("%d\t", adj_mrx[m][n]);
            }
            printf("\n");
        }
    }
    PrintEdges2(adj_mrx);
    return 0;
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

int checkCycles(int adj_mrx[][GRAPH_SIZE])
{
    int i, cycles = 0;
    int visited[GRAPH_SIZE] = { 0, 0, 0, 0, 0 };
    int front = 0, rear = 0;

    visited[rear] = 0;
    rear += 1;

    cycles += traverse1(adj_mrx, visited, front, rear);
    printf("Cycles: %d\n", cycles);
    return cycles;
}

int traverse1(int adj_mrx[][GRAPH_SIZE], int* visited, int front, int rear)
{
    int i, m, cycle = 0;
    for(i = 0; i < GRAPH_SIZE; i += 1)
    {
        if(adj_mrx[(visited[front])][i] > 0)
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

int PrintEdges2(int adj_mrx[][GRAPH_SIZE])
{
    int i, j;
    printf("The edges are: \n");
    for(i = 0; i < GRAPH_SIZE; i += 1)
    {
        for(j = 0; j < GRAPH_SIZE; j += 1)
        {
            if(adj_mrx[i][j] > 0)
            {
                printf("<%d, %d>\t", i, j);
            }
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}