#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "include/oppgave3.h"

//      GLOBAL VARIABLES
#define NUM_TABLES 20
TableNode* firstTable = NULL;
// Declares a list of the tables of the resturant
bool tablesTaken[NUM_TABLES];

//      FUNCTIONS FOR TABLE RESERVATION
int getRandomTable()
{
    int randomIndex;
    do {
        randomIndex = rand() % NUM_TABLES;
    } while (tablesTaken[randomIndex]);
    
    tablesTaken[randomIndex] = true;
    return randomIndex + 1;
}

TableNode* addReservation(int tblNum, char* name, int seats, int time) 
{
    TableNode* current = NULL;
    // allocating a node in the heap
    TableNode* reservation = malloc(sizeof(TableNode));
    if (reservation == NULL) return NULL; // error check
    // Adding the data to the TableNode
    reservation->tableNumber = tblNum;
    // Here i had a 2 hour long "bug" where i just pointed the reservation customer name to the name-array from
    // parse reservation, instead of allocating for a new string for each node. 
    // This caused the of all the reservations to be the newest name. Finally i figured this out after
    // 1000 printf statements checking all the addresses and variables in each step... Which i removed so you could read the code :D
    reservation->customer = malloc(strlen(name) + 1);
    if (reservation->customer != NULL) {
        strcpy(reservation->customer, name);
    } else {
        return NULL;
    }
    reservation->numOfSeats = seats;
    reservation->timeOfOrder = time;
    reservation->firstOrder = NULL; // no orders yet, so NULL

    // If list is empty
    if (firstTable == NULL) {
        firstTable = reservation;
        reservation->next = NULL;
        reservation->prev = NULL;
        printf("    *Successful reservation for %s, list was empty\n---\n", reservation->customer);
        printf("\n");
    // If list is not empty, run through list and sort by name, insert node in correct point of list 
    } else {
        current = firstTable;
        bool completed = false;
        while (!completed) {
            // If the current name looked at comes before the new reservations name alphabetically
            if (strcmp(current->customer, name) <= 0) {
                // If end of the list, insert new reservation at the end 
                if (current->next == NULL) {
                    current->next = reservation;
                    reservation->prev = current;
                    reservation->next = NULL;
                    completed = true;
                    printf("New reservation for %s, inserted at the end of the list\n---\n", name);
                // If not go to the next in list
                } else {
                    current = current->next;
                }
            // If the current name does not come before the new reservation alphabetically
            } else {
                // If first in list, insert new reservation in the start and set firstTable to reservation
                if (current->prev == NULL) {
                    current->prev = reservation;
                    reservation->next = current;
                    reservation->prev = NULL;
                    firstTable = reservation;
                    completed = true;
                    printf("New reservation for %s, inserted at the start of the list\n---\n", name);
                // If not first, insert in front of current
                } else {
                    reservation->prev = current->prev;
                    reservation->next = current;
                    current->prev->next = reservation;
                    current->prev = reservation;
                    completed = true;
                    printf("New reservation for %s, inserted somewhere in the middle of the list\n---\n", name);
                }
            }
        }
    }
    return reservation;
}

TableNode* parseReservation()
{
    char name[21];
    int numPeople;
    int time;
    int success;

    printf("To add a reservation: \n");
    
    // Gets next char from stdin until it finds a new line char or no more input
    // This fixed a bug where it would skip fgets because of previous scanf calls.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    // Get name 
    printf("Please give your name, max 20 character\n"); 
    // Since it needs to support spaces, i cant use scanf
    if (fgets(name, sizeof(name), stdin) != NULL) {
        // Removes the read newline character by finding its index and setting null char instead
        name[strcspn(name, "\n")] = 0;
    } else {
        printf("Error in getting name\n");
        return NULL;
    }
   
    // Get numPeople
    printf("How many people can we expect?\n"); 
    success = scanf("%d", &numPeople);
    if (success != 1) {
        printf("Error, could not get the number of people\n");
        return NULL;
    }
   
    // Get time
    printf("\nWhat time would you like to come?\n");
    printf("    Format:     hhmmDDMMYY\n");
    printf("    Example:    1710280424\n");
    printf("    =           17:10, 28.04.2024\n");
    success = scanf("%d", &time);
    if (success != 1) {
        printf("Error, input is wrong\n");
        return NULL;
    }
    
    // Get randotable that is free
    int tableNumber = getRandomTable();
    printf("\nYour table number is, %d\n\n", tableNumber);
    
    return addReservation(tableNumber, name, numPeople, time);
}
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
    TableNode* current = firstTable;

    return current;
    
}
//  FUNCTIONS FOR ADDING ORDERS
void addOrder()
{
    int tblNum;
    printf("Table:\n");
    scanf("%d", &tblNum);

    printf("What is your name\n");

    /*
    void* next;
    char* purchaser;
    char* orderName;
    int price;
    */
}

//  MENU AND MAIN FUNCTIONALITY 
void printMenu()
{
    printf("\n");
    printf("    ***     *** *** *** *** *** ***     ***\n");
    printf("    ***     RESTURANT ORDER PROGRAM     ***\n");
    printf("    ***     *** *** *** *** *** ***     ***\n");
    printf("\n");
    printf("    --- Please Select An Option ---\n");
    printf("\n");
    printf("    1.  Add a reservation\n");
    printf("    2.  Get reservation by number in list\n");
    printf("    3.  Get reservation by name\n");
    printf("    4.  Delete a reservation\n");
    printf("    5.  Add an order\n");
    printf("    6.  Get orders by table\n");
    printf("    7.  Get orders by customer\n");
    printf("    8.  QUIT...\n");
}

int main() 
{
    // Set the tablesTaken array to false initially
    memset(tablesTaken, false, sizeof(tablesTaken));

    // Seeds the rand function for use in the selection of a table
    srand((unsigned int)time(NULL));

    int option = -1;
    // Loops unitl the quit option is given
    while (option != 8) {
        // Show menu initially and every time after an action is taken, or uponp quit
        printMenu();
        // Get option from user and store return value as errror check
        int success = scanf("%d", &option);
        if (success == 1 && option > 0 && option < 8) { // checks that option is valdi and is between the correct range
            // Here the different options are exectued based on user input.
            switch (option) {
                case 1: { // addReservation
                    TableNode* latestTable = parseReservation(); 
                    if (latestTable == NULL) printf("An error occured, no reservation made..\n");
                    printTableInfo(latestTable);
                    break;
                }
                case 2: // get N table
                    findTableN();
                    break;
                case 3: // get reservation by name and print info 
                    break;
                case 4: // delete a reservation
                    break;
                case 5: // add an order
                    break;
                case 6: // print all orders of given table
                    break;
                case 7: // print all orders by name and table
                    break;
                case 8: // quit
                    break;
            }
        } else {
            break;
        }
    }
}


