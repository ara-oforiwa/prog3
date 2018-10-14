/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Chen
 *
 * Created on October 9, 2018, 11:07 PM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int value(char c){
    return c & 31;
}

char symbol(int n){
    return n | 96;
}

string encrypt(string text, string password){
//    char result[text.size() + 1]; 
    string result;
    
    int text_index = 0;
    for(; text_index < text.size(); text_index++){
        int pass_index;
//        cout << "(" << text[text_index] << "," << password[pass_index] << "}" << endl; 
        if(text[text_index] == ' '){
            result[text_index] = ' ';
        }
        else{
            pass_index  = text_index % password.size();
            int n_char = value(text[text_index]); 
            int n_pass = value(password[pass_index]);
            int n_code;
            if((n_char + n_pass) > 26){
                n_code = ((n_char + n_pass) % 26) - 1;
            }else{
                n_code = n_char + n_pass - 1;
            }
            cout << text[text_index] << "(" << n_char << ")| " 
                    << password[pass_index] << "(" << n_pass << ")" << "=>" 
                    << symbol(n_code) << endl;
//            result[text_index] = symbol(n_code);
        }
    }
//    result[text_index] = '\0';
//    cout << result << endl;
    return result;
}
/*
 * 
 */
int main(int argc, char** argv) {

    int t = 'b' & 31;
    
    string text = "vigenere quadrat";
    string password = "password";
    
//    cout << "Please input a text to be encrypted:" << endl;    
//    getline(cin,text);
//    
//    cout << "Please input a password to encrypt the text with" << endl;
//    cin >> password;
    
    string result = encrypt(text, password);
    cout << result << endl;
//    
//    cout << 6 % 4 << endl;
    return 0;
}



