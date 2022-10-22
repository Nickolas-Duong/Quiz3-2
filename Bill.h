//Bill.h prepares the struct for the program to use

//Header file for project
#ifndef BILL_H
#define BILL_H

//Libraries used
#include <stdio.h>
#include <stddef.h>

//pointer struct for restaurant items
typedef struct
{
    //menu number
    int menuNum;

    //name
    char *menuName;

    //cost
    double menuCost;
}Menu, *PtrToMenu;
//Pointer info to link ptrs
typedef const Menu *PtrToConstMenu;
//Function Definitions used in the 

#endif