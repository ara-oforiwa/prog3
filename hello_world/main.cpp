/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Chen
 *
 * Created on October 8, 2018, 11:47 AM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */

double f(double x){
    // e to the power of - (x pow 2)
    return exp(-pow(x,2));
}

double integral(double a, double b, int n){
    // Base length of all the rectangles
    double step = (b - a) / n;
    double area = 0;
    
    for(double i=step; i < b; i+=step){
        // Gets the side length of each triangle under the function graph
        // and sums its product with the base
        area += f(i) * step;
    }
    
    return area;
} 

int main(int argc, char** argv) {
    // 0 <= x <= 1 the more we divide this segment, the more accurate the result.
    double area = integral(0,1,100000); 
    cout << area << endl;
    
    cin.sync();cin.get();
    return 0;
}




