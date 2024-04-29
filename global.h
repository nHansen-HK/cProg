#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Nubmer of tables constant
#define NUM_TABLES 20

typedef struct OrderNode {
    // Pointer to the next order in list
    void* next;
    // Order data
    char* purchaser;
    char* orderName;
    int price;
} OrderNode;

typedef struct TableNode {
    // Pointers to other TableNode
    struct TableNode* next;
    struct TableNode* prev;
    // Table data
    int tableNumber;
    char* customer;
    int numOfSeats;
    int timeOfOrder;
    // Pointer to first OrderNode of the table, acting as the head of the Order list
    OrderNode* firstOrder;
} TableNode;

// THe global variables 
extern bool tablesTaken[NUM_TABLES];
extern TableNode* firstTable;

#endif




