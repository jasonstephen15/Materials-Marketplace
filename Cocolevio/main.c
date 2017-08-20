#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void getInformation();
void sortCompanies();
void printResults();
void limitCompanies();

struct Company{;
char name[20];              // Initializing Data Structure
double amount;              // amount of item
double price;               // price per bulk
double ppu;                 // price per unit, higher ppu = better
};

int company_Pointer = 0;            //Initializing Pointers/Variables
int numCompanies = 0;
double origInventory;
int i;
int j;
int k;                             //arbitrary loop counters
struct Company database[20], temp;  //creates a database of 20 slots, and a temporary space
char done[20] = "done";             //String to compare against "done"

int main()
{

    printf("Welcome to Materials Marketplace!\n");
    printf("Type done to end program.\n \n");

    getInformation();
    sortCompanies();
    printResults();

    limitCompanies();
    return 0;
}

void getInformation()
{

        while(1)                     // populates database
         {
            printf("Please enter company name: \n");
            scanf("%s", &database[company_Pointer].name);
            if((stricmp(database[company_Pointer].name,done))==0){break;}       //allows to stop execution of program when "done" is entered

            printf("Please enter amount: \n");
            scanf("%lf", &database[company_Pointer].amount);

            printf("Please enter price: \n");
            scanf("%lf", &database[company_Pointer].price);
            while(getchar() != '\n');               //fixes bug

            database[company_Pointer].ppu =  (database[company_Pointer].price)/( database[company_Pointer].amount); //logic for ppu (how we value)
            company_Pointer++;  //next company
         }


    numCompanies = company_Pointer; //total number of companies

}

void sortCompanies()
{
    for(i=0;i<=numCompanies-1;i++)              //Method to rank companies
          {
            for(j=0;j<=numCompanies-1;j++)
            {
                    if(database[j].ppu<database[j+1].ppu)
                {
                  temp=database[j];
                  database[j]=database[j+1];
                  database[j+1]=temp;

                }
            }
            }
}

void printResults()
{
     printf("\n");
     printf("Best Clients to sell to: \n");
     for(j=0;j<=numCompanies-1;j++)
          {
                printf("%d. Company: ",(j+1));
                printf(database[j].name);
                printf("\n");
          }
           printf("\n");
}

void limitCompanies()
{
    int company_Pointer = 0;


    printf("\n");
    printf("Please enter amount of inventory: ");
    scanf("%lf", &origInventory);
    double inventory = origInventory;
    double prevInventory =0;

    for(k=0;k<=numCompanies-1;k++)
    {

    while(inventory > 0)
    {

    inventory -= database[company_Pointer].amount;


    if(inventory <= 0)
    {
        printf("Sell %lf units to %s ", prevInventory,database[company_Pointer].name);
        printf("\n");

    }
    else
    {
        printf("Sell %lf units to %s ", database[company_Pointer].amount,database[company_Pointer].name);
        printf("\n");
        company_Pointer++;
        prevInventory = inventory;
    }
    }
    }
}

