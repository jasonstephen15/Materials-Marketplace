#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Company
{
char name[20];              //Initializing Data Structure
int amount;
int price;
int ppu;                    //price per unit, higher ppu = better
};

int company_Pointer = 0;    //Initializing Pointers/Variables
int bestppu = 0;
char done[20] = "done";

int main()
{
    struct Company database[50]; //database size
    printf("Welcome to Materials Marketplace!\n");
    while(1)
     {
        printf("Please enter company name: \n");
        scanf("%s", &database[company_Pointer].name);
        if((stricmp(database[company_Pointer].name,done))==0){break;}

        printf("Please enter amount: \n");
        scanf("%d", &database[company_Pointer].amount);

        printf("Please enter price: \n");
        scanf("%d", &database[company_Pointer].price);
        while(getchar() != '\n');               //fixes bug

        database[company_Pointer].ppu =  (database[company_Pointer].price)/( database[company_Pointer].amount);
        if(database[company_Pointer].ppu > bestppu){bestppu = database[company_Pointer].ppu;}

     }


     printf("\n");
     printf(database[company_Pointer].name);
     printf("\n");
     printf("%d", database[company_Pointer].amount);
     printf("\n");
     printf("%d", database[company_Pointer].price);
     printf("\n");
     printf("%d", database[company_Pointer].ppu);


}
