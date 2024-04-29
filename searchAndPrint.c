#include "include/searchAndPrint.h"
//  FUNCTIONS FOR GETTING TABLE DATA
//
void printTableInfo(TableNode* reservation)
{
    printf("Table number:       %d\n", reservation->tableNumber);
    printf("Customer name:      %s\n", reservation->customer);
    printf("Seats:              %d\n", reservation->numOfSeats);
    printf("Time:               %d\n", reservation->timeOfOrder);
    
    if (reservation->firstOrder == NULL) {
        printf("This table has no orders\n");
    } else {
        printf("This table has orders, functionality is building\n");
    }
}

void findTableN()
{
    TableNode* current = firstTable;
    int n;
    printf("Give the number in the list you which to show\n");
    int success = scanf("%d", &n);
    if (success != 1 || n < 1) {
        printf("Error in getting num. Number must be over 0\n");
        findTableN();
    }

    if (firstTable == NULL) {
        printf("List is empty, bummer..\n");
    } else {
        // Loop until the nth table res
        for (int i = 1; i <= n; i++) {
            if (i == n) {
                printTableInfo(current);
            } else if (current->next == NULL) { // reached end of list
                printf("Reservation number %d is not there\n", n);
                break;
            } else {
                current = current->next;
            }
        }
    }
}
TableNode* getResByTblNum(int tblNum)
{
    // Point the search pointer to the first table 
    TableNode* current = firstTable;

    while (current != NULL) { // search unitl end of list
        // if you find correct value, exit before end
        if (current->tableNumber == tblNum) break;
        current = current->next;
    }
    return current; // returns NULL if nothing found (reached end), and correct reservation if foudn
}

TableNode* getResByName(char* name) // same as function above 
{
    TableNode* current = firstTable;

    while (current != NULL) {
        // use case-insesetive vversion to make search less painful
        if (strcasecmp(current->customer, name) == 0) break;
        current = current->next;
    }
    return current;
}


