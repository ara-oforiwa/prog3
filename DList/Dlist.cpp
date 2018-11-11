/**@file DList.cpp 
 * File:   DList.cpp
 * Author: Chen
 *
 * Created on November 7, 2018, 11:50 PM
 */
#include "DList.h"
/**
 * Initializes a new list by setting first and last pointers to null.
 * @param dl A reference to the List to initialize
 */
void initializeDList(DList & dl){
    dl.first = emptyList;
    dl.last = emptyList;
}

/**
 * Inserts a new item to the beginning of the list.
 * @param dl A reference to the list
 * @param val The value of the new list item
 */
void put(DList& dl, int val){
    // Initialize a new element
    DListElem* newElement = new DListElem;
    newElement->info = val;
    newElement->prev = emptyList;
    newElement->next = emptyList;
    
    // first element in list
    if(isEmpty(dl)){
        dl.first = newElement;
        dl.last = newElement;
    // at least one element already in the list
    }else{
        newElement->next = dl.first;
        dl.first->prev = newElement;    
        dl.first = newElement;
    }        
}

/**
 * Retrieves an the value of the last item in the list. It then removes the item
 * and releases its memory.
 * @param dl A reference to the list
 * @param val A reference to the value to be returned
 * @return True if a value is returned, False if the list is empty
 */
bool get(DList& dl, int &val){
    if(isEmpty(dl))
        return false;

    // value of last element goes into the reference variable
    val = dl.last->info;\

    // List contains only one element
    if(dl.last == dl.first){
        // release memory area 'first' is pointing too (of 'last')
        delete dl.first; 
        initializeDList(dl);
    }
    // List contains at least two elements
    else{
        // A new pointer to the new last element
        DListElem* newLast = dl.last->prev;
        newLast->next = emptyList;
        // release memory containing the last cell 
        delete dl.last;
        // update pointer to last element
        dl.last = newLast;
    }
    
    return true;
}

/**
 * Determines if a list is empty 
 * @param dl A copy of the list
 * @return True if the list is empty, False if it is not
 */
bool isEmpty(DList dl){
    // it's enough that only one points to null, but would be an invalid state..
    return dl.first == emptyList || dl.last == emptyList;
}
