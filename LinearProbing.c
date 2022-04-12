#include<stdio.h>
#define SIZE 20

struct bucket
{
    int part;
    int quantity;
};
typedef struct bucket Bucket;

int Hash(int);
int InsertPart(Bucket*);
int PrintHashtable(Bucket*, int);
int SearchPart(Bucket*, int);

int main()
{
    int i, part, col, collisions = 0;
    char cont;
    Bucket hashtable[SIZE];
    for(i = 0; i < SIZE; i += 1)
    {
        hashtable[i].part = 0;
        hashtable[i].quantity = 0;
    }

    printf("Enter %d parts\n", SIZE);
    for(i = 0; i < SIZE; i += 1)
    {
        col = InsertPart(hashtable);
        collisions += col;
    }
    printf("Total collisions while inserting %d parts: %d\n",SIZE, collisions);

    printf("The Parts table is\n");
    PrintHashtable(hashtable, SIZE);

    do{
        fflush(stdin);
        printf("\nEnter part to search: ");
        scanf("%d", &part);
        SearchPart(hashtable, part);
        printf("Do you wish to continue? (Y/N) ");
        fflush(stdin);
        scanf("%c", &cont);
    }while((cont == 'Y') || (cont == 'y'));

    return 0;
}

int Hash(int key)
{
    int hash = key % SIZE;  //hash function
    return hash;
}

int InsertPart(Bucket* hashtable)
{
    int part, quantity, hash, collision = 0;
    printf("Enter part ID: ");
    scanf("%d", &part);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    hash = Hash(part);
    while(hashtable[hash].part != 0)
    {
        //collision
        collision++;
        hash = (hash += 1) % SIZE;
    }
    hashtable[hash].part = part;
    hashtable[hash].quantity = quantity;
    printf("%d inserted into hashtable successfully with %d collisions\n\n", part, collision);

    return collision;
}

int PrintHashtable(Bucket* hashtable, int n)
{
    int i;
    printf("Parts |\tQuantity\n--------------------\n");
    for(i = 0; i < n; i += 1)
    {
        printf("%d |\t%d\n", hashtable[i].part, hashtable[i].quantity);
    }
    return 0;
}

int SearchPart(Bucket* hashtable, int part)
{
    int hash, collision = 0;
    hash = Hash(part);
    while(hashtable[hash].part != part)
    {
        //collision
        collision += 1;
        if(collision == 20)
        {
            printf("%d part not found in hashtable\n", part);
            return 1;
        }
        hash = (hash += 1) % SIZE;
    }
    printf("%d part sold %d quantity\n", part, hashtable[hash].quantity);

    return 0;
}