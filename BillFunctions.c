//BillFunctions.c hosts all of the function definitions used by the program
#include <string.h>
#include "Bill.h"


//searchItemTable pointer function - Searches the function for the indicated number for the menu
static PtrToMenu searchMenuTable(PtrToConstMenu ptr, int tableSize, const void *targetPtr, int (*functionPtr)(const void *, PtrToConstMenu))
{   
    //set end pointer (table size + 1)
    PtrToConstMenu endPtr = ptr + tableSize;
        //for loop to search through table
    for(; ptr < endPtr; ptr++)
    {
        //if pointer points to menu item
        if((*functionPtr)(targetPtr, ptr) == 0)
        {
            //return item
            return (PtrToMenu) ptr;
        }
    }
    //return NULL if not found
    return NULL;
}        
//compareItemNumber - compares random number to number in table
static int compareMenuNumber(const void *targetPtr, PtrToConstMenu tableValuePtr)
{
    //return if item number found
    return * (int *) targetPtr != tableValuePtr->menuNum;
}

//randomItemNumber - Randomize what menu item is returned by program (wrapper!)
PtrToMenu searchMenuByNumber(PtrToConstMenu ptr, int size, int number)
{
    //return pointer to menu item from searching table
    return searchMenuTable(ptr, size, &number, compareMenuNumber);
}