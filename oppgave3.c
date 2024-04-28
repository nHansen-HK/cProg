#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "include/oppgave3.h"

#define NUM_TABLES 20

TableNode* firstTable = NULL;
// Declares a list of the tables of the resturant
bool tablesTaken[NUM_TABLES];

TableNode* addReservation(int tblNum, char* name, int seats, int time) 
{
    // allocating a node in the heap
    TableNode* reservation = malloc(sizeof(TableNode));
    if (reservation == NULL) return NULL; // error check
    
    // Adding the data to the TableNode
    reservation->tableNumber = tblNum;
    reservation->customer = name;
    reservation->numOfSeats = seats;
    reservation->timeOfOrder = time;
    reservation->firstOrder = NULL; // no orders yet, so NULL

    // If list is empty
    if (firstTable == NULL) {
        firstTable = reservation;
        reservation->next = NULL;
        reservation->prev = NULL;
        printf("New reservation for %s, list was empty\n---\n", name);
    // If list is not empty, run through list and sort by name, insert node in correct point of list 
    } else {
        TableNode* current = firstTable;
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

int getRandomTable()
{
    int randomIndex;
    do {
        randomIndex = rand() % NUM_TABLES;
    } while (tablesTaken[randomIndex]);
    
    return randomIndex + 1;
}

void printMenu()
{
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
    TableNode* newReservation = addReservation(20, "Borg", 5, 170000);
    TableNode* fiejge = addReservation(20, "Amondsen", 5, 170000);
    TableNode* wrigje = addReservation(20, "Xavier", 5, 170000);
    TableNode* gjr = addReservation(20, "Bobia", 5, 170000);

    // Set the tablesTaken array to false initially
    memset(tablesTaken, false, sizeof(tablesTaken));

    // Seeds the rand function for use in the selection of a table
    srand((unsigned int)time(NULL));

    int option = -1;
    // Loops unitl the quit option is given
    while (option != 8) {
        printMenu();
        int success = scanf("%d", &option);
        if (success == 1 && option > 0 && option < 8) {
            switch (option) {
                case 1: {
                    char* name;
                    int numPeople;
                    int time;

                    printf("To add a reservation: \n");

                    printf("Please give your name\n"); 
                    int success = scanf("%s", name);
                    if (success != 1) printf(stderr, "Error in getting name");

                    printf("How many people can we expect?\n"); 
                    success = scanf("%d", &numPeople);
                    if (success != 1) printf(stderr, "Error, could not get the number of people");
// WORK FROM HERE TMRW
                    break;
                }
                
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
            }
        }
    }
    printMenu(); 
        

}


