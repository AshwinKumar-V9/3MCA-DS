#include<stdio.h>

int main()
{
    int i, hash;
    char ch, arr[26], cont;
    for(i = 0; i < 26; i += 1)
    {
        arr[i] = '*';
    }

    printf("Enter 10 lowercase alpha characters: ");
    for(i = 0; i < 10; i += 1)
    {
        scanf("%c", &ch);
        hash = (int)ch - 97;    //hash function
        arr[hash] = ch;
    }

    printf("The hash table is:\nKey |\tValue\n--------------\n");
    for(i = 0; i < 26; i += 1)
    {
        printf("%d |\t%c\n", i, arr[i]);
    }

    do{
        fflush(stdin);
        printf("\nEnter search element: ");
        scanf("%c", &ch);
        hash = (int)ch - 97;    //hash function
        if((hash >= 0) && (hash < 26) && (arr[hash] == ch))
        {
            printf("Element %c found at %d in hash table\n", arr[hash], hash);
        }
        else
        {
            printf("Element %c not in hash table\n", ch);
        }

        printf("Do you wish to continue? (Y/N) ");
        fflush(stdin);
        scanf("%c", &cont);
    }while((cont == 'Y') || (cont == 'y'));

    return 0;
}