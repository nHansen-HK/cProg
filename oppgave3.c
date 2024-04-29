#include "include/global.h"
#include "include/tableRes.h"
#include "include/searchAndPrint.h"
#include "include/order.h"

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
                case 3: {
                    TableNode* reservation = NULL;
                    char name[21];
                    //clear the input buffer again
                    int c;
                    while((c = getchar()) != '\n' && c != EOF);
                    // get name with potetial spaces
                    printf("Name to search for: \n");
                    if (fgets(name, sizeof(name), stdin) != NULL) {
                        name[strcspn(name, "\n")] = 0;
                    } else {
                        printf("Error in getting name\n");
                        break;
                    } 
                    
                    reservation = getResByName(name);
                    if (reservation == NULL) {
                        printf("No reservation found under that name");
                        break;
                    }
                    printTableInfo(reservation);
                    break;
                }
                    // get reservation by name and print info 
                case 4: // delete a reservation
                    break;
                case 5: // add an order
                    //test
                    if (addOrder() == 1) {
                        printf("Order Added Successfully\n");
                    } else {
                        printf("Something went wrong with the order\n");
                    }
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


