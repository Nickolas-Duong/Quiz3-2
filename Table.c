//Table.c is used to create the table to search for the menu items

//Table for menu items to search for
//libraries
#include <string.h>
#include <stdlib.h>
#include "Bill.h"

//Table (make table const to prevent tampering)
Menu MenuTable[] =
{
    //Item 1 - 1, Salad, 9.95
    {1, "Salad", 9.95},
    //Item 2 - 2, Soup, 4.55
    {2, "Soup", 4.55},
    //Item 3 - 3, Sandwich, 13.25
    {3, "Sandwich", 13.25},
    //Item 4 - 4, Pizza, 22.35
    {4, "Pizza", 22.35}
};

//Size of table
const int MenuTableEntries = sizeof(MenuTable)/sizeof(MenuTable[0]);