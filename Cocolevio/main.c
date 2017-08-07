#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Company
{
char name[20];              // Initializing Data Structure
double amount;              // amount of item
double price;               // price per bulk
double ppu;                 // price per unit, higher ppu = better
};

int company_Pointer = 0;    //Initializing Pointers/Variables

char done[20] = "done";     //String to compare against "done"
int i;
int j;

int main()
{
    struct Company database[20], temp; //creates a database of 20 slots, and a temporary space
    printf("Welcome to Materials Marketplace!\n");

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


    int numCompanies = company_Pointer; //total number of companies


     printf("\n");
     printf("Best Clients to sell to: \n");

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

          for(j=0;j<=numCompanies-1;j++)
          {
                printf("%d",(j+1));
                printf(". Company: ");
                printf(database[j].name);
                printf("\n");
          }

        }



