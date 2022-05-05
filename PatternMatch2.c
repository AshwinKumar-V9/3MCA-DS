#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STR_SIZE 20
#define PAT_SIZE 5

int FindKMP(char [], char []);
int FindLPS(char [], int*, int);

int main()
{
    char string[STR_SIZE]= "AABAACAADAABAABA";
    char pattern[PAT_SIZE] = "AABA";

    FindKMP(string, pattern);

    return 0;
}

int FindKMP(char string[STR_SIZE], char pattern[PAT_SIZE])
{
    int i, j = 0, count = 0;
    int m = strlen(string);
    int n = strlen(pattern);

    int* LPS = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i += 1)
    {
        LPS[i] = 0;
    }

    FindLPS(pattern, LPS, n);

    printf("The LPS array is: ");
    for (i = 0; i < n; i += 1)
    {
        printf("%d ",LPS[i]);
    }
    printf("\n");

    for(i = 0; i < m; i += 1)
    {
        while(j < n)
        {
            count += 1;
            if(string[i] != pattern[j])
            {
                if(j == 0)
                {
                    i += 1;
                    continue;
                }
                j = LPS[j - 1];
                continue;
            }
            i += 1;
            j += 1;
        }
        printf("String matched at index %d\n", i-n);
        i -= 1;
        j = LPS[j - 1];
    }
    printf("Total char comparisons: %d\n", count);

    free(LPS);
    return 0;
}

int FindLPS(char pattern[PAT_SIZE], int* LPS, int n)
{
    int i=1, j=0;
    while(i < n)
    {
        if(pattern[j] == pattern[i])
        {
            j += 1;
            LPS[i] = j;
            i += 1;
            continue;
        }
        else if(j == 0)
        {
            LPS[i] = 0;
            i += 1;
            continue;
        }
        else{
            j = LPS[j - 1];
        }
    }
    return 0;
}