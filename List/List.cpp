/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "List.h"
#include <iostream>

using namespace std;

void printList(List lst){
    if(lst == emptyList){
        cout << "Empty list!" << endl;
        return;
    }
    
    while(lst->next != emptyList){
        cout << lst->info << "-";
        lst = lst->next;
    }

    cout << lst->info << endl;
}

void insertLast(List & lst, int info){
    
    // Create and initialize a new list item pointer
    ListElem * newElement = new ListElem;
    newElement->info = info;
    newElement->next = emptyList;
    
    if(lst == emptyList){
        lst = newElement;    
    }else{
        // create a pointer to the referenced list element
        ListElem * temp = lst;
        while(temp->next != emptyList){
            // move the pointer down the list 
            temp = temp->next;
        }
        temp->next = newElement;        
    }
}

void reverseList(List & lst){
    List newList = emptyList;
    List lstPointer = lst;
    
    while(lstPointer != emptyList){
        insertElem(newList,lstPointer->info);
        lstPointer = lstPointer->next;
    }
    
    lst = newList;
}

int  listLength(List lst){
    
}

void insertElem(List& lst, int info){
    List newElement = new ListElem;
    newElement->info = info;
    newElement->next = lst;
    
    lst = newElement;

}

bool removeElem(List& lst, int& info){
    return false;
}

ListElem * searchElem(List lst, int info){
    return emptyList;
}

