//main.c hosts the code to run the program, pulling from Table.c, Bill.h and BillFunctions.c in order to print a reciept for the user to view
//When run, the user also inputs two arguments: Tax and Tip percentages.
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "Bill.h"

//main function - argc and argv[]
void main(int argc, char * argv[])
{
    //function prototypes
    PtrToMenu searchMenuByNumber(const Menu table[], int sizeTable, int numberToFind);

    //extern table
    extern Menu MenuTable[];

    //extern table size
    extern const int MenuTableEntries;

    //random generate how many items in array
    time_t t;
    PtrToMenu matchPtr;
    int maxOrder;
    double cost = 0;
    double tax, tip;

    //Randomize random
    srand((unsigned) time(&t));
    
    //set max order size
    maxOrder = (rand() % 10) + 1;
    
    //generate max order
    for(int i = 0; i < maxOrder; i++)
    {
        //get menu item
        matchPtr = searchMenuByNumber(MenuTable, MenuTableEntries, (rand() % 4)+1);

        //if found
        if (matchPtr != NULL)
        {
            //print item information
            printf("Menu number %d\n", matchPtr->menuNum);
            printf("%s\n", matchPtr->menuName);
            printf("Item Cost: $%f\n\n", matchPtr->menuCost);

            //increase cost
            cost = cost + matchPtr->menuCost;
        }
        //if not found
        else
        {
            printf("Menu number not found\n");
        }
    }

    //declare local variable for tax percent based on inputs -> if no input assume 0
    tax = atof(argv[1]);
    
    //declare local variable for tip percent based on inputs -> if no input assume 0
    tip = atof(argv[2]);

    //print tax percent and total tax
    printf("Tax Percent: %f\nTax: $%f\n", tax, tax*cost);

    //print tip percent and total tip
    printf("Tip Percent: %f\nTip: $%f\n", tip, tip*cost);
    
    //print final bill cost
    printf("Total: $%f\n", cost+(tax*cost)+(tip*cost));

    EXIT_SUCCESS;
}
