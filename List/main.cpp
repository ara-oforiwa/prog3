/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Chen
 *
 * Created on November 7, 2018, 11:38 AM
 */

#include <cstdlib>
#include "List.h"

using namespace std;

/*
 * 
 */
int main(){
    List list1 = emptyList;
    printList(list1);
    
    for(int i=1; i<1; ++i){
        insertElem(list1,i);
    }

    printList(list1);
    
    reverseList(list1);
    
    printList(list1);
    
    reverseList(list1);
    
    printList(list1);
    
    return 0;
}

