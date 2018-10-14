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

int const MAX_CHAR_VAL = 26;

int value(char c){
    return c & 31;
}

char symbol(int n){
    return n | 96;
}

char get_symbol(int i,int n){
    int result = i + n;
    if(result > MAX_CHAR_VAL){
        result = result - MAX_CHAR_VAL;
    }
    return symbol(result);
}

void encrypt(string text, string password, string &code){
//    char result[text.size() + 1]; 
    
    int text_index = 0;
    int pass_index = 0;
    while (text_index < text.size()){
        // Spaces are not encrypted, text index is incremented but not
        // the password index, to keep pass aligned with text.
        if(text[text_index] == ' '){
            code  += ' ';
            text_index++;
        }
        else{
            int num_char = value(text[text_index]); 
            int shift_index = value(password[pass_index]) - 1;
            char new_letter = get_symbol(num_char, shift_index);
            
            code += new_letter;
            
            text_index++;
            
            // Cyclicly increment the password index
            pass_index = (pass_index + 1) % password.size();
        }
    }
}

    /*
 * 
 */
int main(int argc, char** argv) {

    int t = 'b' & 31;
    
    string text = "vigenere quadrat";
    string password = "passwort";
    string result;
//    cout << "Please input a text to be encrypted:" << endl;    
//    getline(cin,text);
//    
//    cout << "Please input a password to encrypt the text with" << endl;
//    cin >> password;
    
    encrypt(text, password, result);
    cout << result << endl;
//    
//    cout << 6 % 4 << endl;
    return 0;
}



