#include<stdio.h>
#define TEAM1_SIZE 3
#define TEAM2_SIZE 3

int main()
{
    int i, j, mem1, mem2;
    int class[TEAM1_SIZE + TEAM2_SIZE][TEAM1_SIZE + TEAM2_SIZE];
    for(i = 0; i < (TEAM1_SIZE + TEAM2_SIZE); i += 1)
    {
        for(j = 0; j < (TEAM1_SIZE + TEAM2_SIZE); j += 1)
        {
            //make team1 mutual friends
            if((i < TEAM1_SIZE) && (j < TEAM1_SIZE))
            {
                class[i][j] = 1;
            }
            //make team2 mutual friends
            else if((i >= TEAM1_SIZE) && (j >= TEAM1_SIZE))
            {
                class[i][j] = 1;
            }
            else{
                class[i][j] = 0;
            }
        }
    }

    printf("The class friends are:(initially) \n");
    for(i = 0; i < (TEAM1_SIZE + TEAM2_SIZE); i += 1)
    {
        for(j = 0; j < (TEAM1_SIZE + TEAM2_SIZE); j += 1)
        {
            printf("%d\t", class[i][j]);
        }
        printf("\n");
    }

    //make 3 friends between the teams
    for(i = 0; i < 3; i += 1){
        printf("Friendship %d:\n", (i+1));
        printf("Enter team1 student reg_no (1-3): ");
        scanf("%d", &mem1);
        printf("Enter team2 student reg_no (4-6): ");
        scanf("%d", &mem2);

        class[mem1-1][mem2-1] = 1;
        class[mem2-1][mem1-1] = 1;
        printf("Friendship set!\n\n");
    }

    printf("The class friends are:(finally) \n");
    for(i = 0; i < (TEAM1_SIZE + TEAM2_SIZE); i += 1)
    {
        for(j = 0; j < (TEAM1_SIZE + TEAM2_SIZE); j += 1)
        {
            printf("%d\t", class[i][j]);
        }
        printf("\n");
    }

    return 0;
}