/**@file DList.h
 * Author: Chen
 *
 * Created on November 7, 2018, 11:50 PM
 */

#ifndef DLIST_H
#define DLIST_H


struct DListElem
{
  int        info;
  DListElem * next;
  DListElem * prev;
};

struct DList{
    DListElem* first;
    DListElem* last;
};

// empty list is a constant Null Pointer (address cannot be changed)
DListElem* const emptyList = 0;

void initializeDList(DList & dl);
void put(DList& dl, int val);
bool get(DList& dl, int &val);
bool isEmpty(DList dl);

#endif /* DLIST_H */

