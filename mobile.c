#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5
#define MODEL_SIZE 15
#define BRAND_SIZE 15

struct node
{
    char model[MODEL_SIZE];
    char brand[BRAND_SIZE];
    int memory;
    float price;
    struct node* link;
};
typedef struct node Mobile;


Mobile* CreateMobileNode();
int AddMobile(Mobile*);
int PrintMobiles(Mobile*);
int DeleteMobiles(Mobile*);
int SortByBrand(Mobile*);
int SortByPrice(Mobile*);
int SortByBrandThenPrice(Mobile*);

int main()
{
    int i,option, check;
    char cont;
    Mobile* list = CreateMobileNode();

    printf("Enter %d mobiles: \n", SIZE);
    for(i = 0; i < SIZE; i += 1)
    {
        AddMobile(list);
    }

    printf("The mobiles are: \n");
    PrintMobiles(list);

    do{
        printf("1 - Sort by brand\n2 - Sort by price\n3 - Sort by both brand and price\nSelect the operation you want to perform: ");
        check = scanf("%d", &option);
        if(check != 1)
        {
            printf("Incorrect Input");
            return 1;
        }
        switch(option)
        {
            case 1: SortByBrand(list);
                    printf("The brand sorted mobiles are: \n");
                    PrintMobiles(list);
                    break;
            case 2: SortByPrice(list);
                    printf("The price sorted mobiles are: \n");
                    PrintMobiles(list);
                    break;
            case 3: SortByBrandThenPrice(list);
                    printf("The brand and price sorted mobiles are: \n");
                    PrintMobiles(list);
            default: printf("Invalid option\n");
        }
        printf("Do you wish to continue? (Y/N) ");
        fflush(stdin);
        scanf("%c", &cont);
    }while((cont == 'Y') || (cont == 'y'));

    DeleteMobiles(list);
    return 0;
}

Mobile* CreateMobileNode()
{
    Mobile* node = (Mobile*)malloc(sizeof(Mobile));
    node->memory = 0;
    node->price = 0;
    node->link = NULL;
    return node;
}

int AddMobile(Mobile* list)
{
    fflush(stdin);
    Mobile* mobile = CreateMobileNode();
    printf("Enter model: ");
    fgets(mobile->model, MODEL_SIZE, stdin);
    if(mobile->model == NULL)
    {
        printf("Error reading mobile model!\n");
        return 1;
    }
    printf("Enter brand: ");
    fgets(mobile->brand, BRAND_SIZE, stdin);
    if(mobile->brand == NULL)
    {
        printf("Error reading mobile brand!\n");
        return 1;
    }
    printf("Enter memory: ");
    scanf("%d", &mobile->memory);
    printf("Enter price: ");
    scanf("%f", &mobile->price);

    Mobile* curr = list;
    while(curr->link != NULL)
    {
        curr = curr->link;
    }
    curr->link = mobile;
    printf("Mobile added successfully!\n\n");
    return 0;
}

int PrintMobiles(Mobile* list)
{
    Mobile* curr = list->link;
    while(curr != NULL)
    {
        printf("%s%s%d\n%.2f\n\n", curr->model, curr->brand, curr->memory, curr->price);
        curr = curr->link;
    }
    return 0;
}

int DeleteMobiles(Mobile* list)
{
    Mobile* curr = list;
    Mobile*prev = NULL;
    while(curr != NULL)
    {
        prev = curr;
        curr = curr->link;
        free(prev);
    }
    return 0;
}

int SortByBrand(Mobile* list)
{
    int flag;
    list = list->link;
    Mobile* curr = list->link;
    Mobile* prev = list;
    char brand[BRAND_SIZE];
    strcpy(brand, list->brand);
    do{
        flag = 0;
        while(curr != NULL)
        {
            if(!(strcmp(curr->brand, brand)))
            {
                Mobile* temp;
                flag = 1;
                prev->link = curr->link;
                temp = curr->link;
                curr->link = list->link;
                list->link = curr;
                list = curr;
                curr = temp;
                continue;
            }
            prev = curr;
            curr = curr->link;
        }
        list = list->link;
        if(flag == 0)
        {
            list = curr;
        }
        strcpy(brand, list->brand);
        prev = list;
        curr = list->link;
    }while(curr != NULL);
    return 0;
}

int SortByPrice(Mobile* list)
{
    Mobile* curr = list->link;
    Mobile* next = curr->link;
    Mobile* small = curr;
    float price = small->price;
    Mobile* head = list;
    Mobile* smallprev = head;

    while(next != NULL)
    {
        //find the smallest price mobile
        while(next != NULL)
        {
            if(next->price < price)
            {
                small = next;
                price = small->price;
                smallprev = curr;
            }
            curr = next;
            next = next->link;
        }
        //swap nodes
        smallprev->link = small->link;
        small->link = head->link;
        head->link = small;

        //move to next set of nodes
        head = small;
        curr = small->link;
        next = curr->link;
        small = curr;
        smallprev = head;
        price = small->price;
    }
    return 0;
}


int SortByBrandThenPrice(Mobile* list)
{
    SortByBrand(list);

    Mobile* curr = list->link;
    Mobile* next = curr->link;
    Mobile* small = curr;
    float price = small->price;
    Mobile* head = list;
    Mobile* smallprev = head;

    char brand[BRAND_SIZE];
    strcpy(brand, curr->brand);

    while(next != NULL)
    {
        //selection sort for each brand
        while(!(strcmp(next->brand, brand)))
        {
            //find the smallest price mobile
            while(!(strcmp(next->brand, brand)))
            {
                if(next->price < price)
                {
                    small = next;
                    price = small->price;
                    smallprev = curr;
                }
                curr = next;
                next = next->link;
            }
            //swap nodes
            smallprev->link = small->link;
            small->link = head->link;
            head->link = small;

            //move to next set of nodes
            head = small;
            curr = small->link;
            next = curr->link;
            small = curr;
            smallprev = head;
            price = small->price;
        }
        smallprev = curr;
        curr = next;
        next = next->link;
        strcpy(brand, curr->brand);
        small = curr;
        price = small->price;
        head = smallprev;
    }
    return 0;
}