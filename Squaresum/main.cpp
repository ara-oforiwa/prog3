/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Chen
 *
 * Created on October 15, 2018, 12:24 PM
 */
#define SQUARESUM(a,b) (a*a + b*b)

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int a=2,b=5;
    cout << SQUARESUM(a,b) << endl;
    return 0;
}

