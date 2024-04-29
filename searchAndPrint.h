#ifndef SEARCHANDPRINT_H
#define SEARCHANDPRINT_H

#include "global.h"

TableNode* getResByTblNum(int tblNum);
void printTableInfo(TableNode* reservation);
void findTableN();
TableNode* getResByName(char* name);

#endif

