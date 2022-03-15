/*
    Design a structure to represent STATE, which includes the following attributes
    State Name, Population, Language, Literacy Rate
    Write a C program to read N states and
    Q1) Sort the states based on literacy rate from highest to lowest order.
    Q2) Display the total population of people who speak same language in ascending order.
*/

#include<stdio.h>
#define NAME_SIZE 15
#define LANG_SIZE 15
#define STATE_SIZE 5

struct state
{
    char name[NAME_SIZE];
    float population;
    char lang[LANG_SIZE];
    float literacy;
}states[STATE_SIZE] = {
    {"Madhya Pradesh", 7.33, "Hindi", 70.6},
    {"Andhra Pradesh", 4.97, "Telugu", 67.4},
    {"Uttar Pradesh", 20.42, "Hindi", 69.72},
    {"Karnataka", 6.41, "Kannada", 75.36},
    {"Telangana", 3.52, "Telugu", 66.46}
};

int main()
{
    int i, j;
    struct state t;
    for(i = 0; i < (STATE_SIZE-1); i +=1)
    {
        for(j = 0; j < (STATE_SIZE-i-1); j +=1 )
        {
            if(states[j].literacy < states[j+1].literacy)
            {
                t = states[j];
                states[j] = states[j+1];
                states[j+1] = t;
            }
        }
    }

    for(i=0; i < STATE_SIZE; i += 1)
    {
        printf("State: %s \n population: %.2f \n language: %s \n literacy: %.2f \n\n",
        states[i].name, states[i].population, states[i].lang, states[i].literacy);
    }


    return 0;
}