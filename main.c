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
    double cost;
    double tax, tip;

    srand((unsigned) time(&t));

    matchPtr = searchMenuByNumber(MenuTable, MenuTableEntries, (rand() % 4)+1);
 
    if (matchPtr != NULL)
    {
        printf("Menu number %d\n", matchPtr->menuNum);
        printf("%s\n", matchPtr->menuName);
        printf("Item Cost: %f\n", matchPtr->menuCost);

        cost = cost + matchPtr->menuCost;
    }
    else
    {
        printf("Menu number not found\n");
    }
    //declare local variable for tax percent based on inputs -> if no input assume 0
    tax = atof(argv[1]);
    
    //declare local variable for tip percent based on inputs -> if no input assume 0
    tip = atof(argv[2]);

    //print tax percent and total tax
    printf("Tax: %f\n", tax*cost);

    //print tip percent and total tip
    printf("Tip: %f\n", tip*cost);
    
    //print final bill cost
    printf("Total: %f\n", cost+(tax*cost)+(tip*cost));

    EXIT_SUCCESS;
}
