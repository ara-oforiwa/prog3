//List.h

#ifndef _LIST_H_
#define _LIST_H_

//definition of a list element
struct ListElem
{
  int        info;
  ListElem * next;
};

// shortcut for list = pointer to a list element
typedef ListElem * List;

// empty list is a Null Pointer
const List emptyList = 0;

void printList(List lst);
void insertLast(List & lst, int info);
void reverseList(List & lst);
int  listLength(List lst);
void insertElem(List& lst, int info);
bool removeElem(List& lst, int& info);


ListElem * searchElem(List lst, int info);


#endif
