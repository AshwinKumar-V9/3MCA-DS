#include<stdio.h>
#include<string.h>
#define STR_SIZE 20
#define PAT_SIZE 5

int Find(char [], char []);

int main()
{
    char string[STR_SIZE]= "AABAACAADAABAABA";
    char pattern[PAT_SIZE] = "AABA";

    Find(string, pattern);

    return 0;
}

int Find(char string[STR_SIZE], char pattern[PAT_SIZE])
{
    int i, j, t, flag, index, count = 0;
    int m = strlen(string);
    int n = strlen(pattern);
    for(i = 0; i < m; i += 1)
    {
        t = i;
        flag = 0;
        index = i;
        for(j = 0; j < n; j += 1)
        {
            count += 1;
            if(string[i] != pattern[j])
            {
                flag = 1;
                break;
            }
            i += 1;
        }
        i = t;
        if(flag == 0)
        {
            printf("String matched at index %d\n", index);
        }
    }
    printf("Total char comparisons: %d\n", count);
    return 0;
}