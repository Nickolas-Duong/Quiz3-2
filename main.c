//main.c hosts the code to run the program, pulling from Table.c, Bill.h and BillFunctions.c in order to print a reciept for the user to view
//When run, the user also inputs two arguments: Tax and Tip percentages.
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "Bill.h"

//main function - argc and argv[]
void main()
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

    srand((unsigned) time(&t));

    matchPtr = searchMenuByNumber(MenuTable, MenuTableEntries, (rand() % 4)+1);
 
    if (matchPtr != NULL)
    {
        printf("Menu number %d\n", matchPtr->menuNum);
    }
    else
    {
        printf("Menu number not found\n");
    }
    //declare local variable for tax percent based on inputs -> if no input assume 0
    //declare local variable for tip percent based on inputs -> if no input assume 0

    //print tax percent and total tax

    //print tip percent and total tip

    //print final bill cost
    
    EXIT_SUCCESS;
}
