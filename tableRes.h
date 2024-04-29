#ifndef TABLERES_H
#define TABLERES_H

#include "global.h"

TableNode* addReservation(int tblNum, char* name, int seats, int time);
TableNode* parseReservation();
int getRandomTable();

#endif
