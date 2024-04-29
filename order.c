#include "include/order.h"

//  FUNCTIONS FOR ADDING ORDERS
int insertOrder(TableNode* reservation, char* purchaser, char* ordername, int price)
{
    // searching pointer for orders
    OrderNode* current = NULL;
    // allocate for order
    OrderNode* newOrder = malloc(sizeof(OrderNode));
    if (newOrder == NULL) {
        printf("Allocation error for order\n");
        return 0;
    }
    // allocate the string and copy from the addOrder buffer
    newOrder->purchaser = malloc(strlen(purchaser) + 1);
    if (newOrder->purchaser != NULL) {
        strcpy(newOrder->purchaser, purchaser);
    } else {
        printf("String allocation error, purchaser name\n");
        return 0;
    }
    // also allocate for the ordername
    newOrder->orderName = malloc(strlen(ordername) + 1);
    if (newOrder->orderName != NULL) {
        strcpy(newOrder->orderName, ordername);
    } else {
        printf("String allocation error, orderName\n");
        return 0;
    }
    // set price
    newOrder->price = price;

    // INSERTION INTO LIST
    current = reservation->firstOrder; // set search pointer to the first Order
    newOrder->next = NULL; // This must be done no matter the state of the list
    // if no orders for reservation
    if (current == NULL) {
        reservation->firstOrder = newOrder;
    } else {
        // go to the last order in list
        while (current->next != NULL) {
            current = current->next; 
        }
        // then insert at end
        current->next = newOrder;
    }
    // order inserted successfully
    return 1;
}
int addOrder()
{
    int success;
    // data
    TableNode* reservation = NULL;
    int tblNum;
    char nameBuf[16];
    char foodBuf[21];
    int price;

    printf("Table:\n");
    success = scanf("%d", &tblNum);
    if (success != 1) return 0;

    printf("What is the first name, max 15 characters\n");
    success = scanf("%s15", nameBuf);
    if (success != 1) return 0;

    printf("Name of dish/drink: \n");
    success = scanf("%s20", foodBuf);
    if (success != 1) return 0;

    printf("Price of dish/drink: \n");
    success = scanf("%d", &price);
    if (success != 1) return 0;

    reservation = getResByTblNum(tblNum);

    if (insertOrder(reservation, nameBuf, foodBuf, price) != 1) {
        printf("Order insert error\n");
        return 0;
    }

    return 1;
}
