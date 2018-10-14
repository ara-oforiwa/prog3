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

char shift_backwards(int n_char,int shift_index) {
    int result = n_char + shift_index;
    if(result > MAX_CHAR_VAL){
        result = result - MAX_CHAR_VAL;
    }
    return symbol(result);
}

char shift_forward(int n_char,int shift_index){
    int result = n_char - shift_index;
    if(result <= 0){
        result = result + MAX_CHAR_VAL;
    }
    return symbol(result);
}

void enc_dec_vigenere(string text, string password, string &code, char (*operation)(int,int)){
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
            char new_letter = operation(num_char, shift_index);
            
            code += new_letter;
            
            text_index++;
            
            // Cyclicly increment the password index
            pass_index = (pass_index + 1) % password.size();
        }
    }
}

void encrypt(string text, string password, string &code){
    enc_dec_vigenere(text,password,code,shift_forward);
}

void decrypt(string code, string password, string &text){
    enc_dec_vigenere(code, password, text, shift_backwards);
}

int main(int argc, char** argv) {

    int t = 'b' & 31;
    
    string text = "hallo my name is chen and i am writing a code that is capable to encrypt and decrypt text using the vinigerete quadrat or shift key method";
    string password = "PASSWORT";
    string result;
    
    encrypt(text, password, result);
    cout << result << endl;

    text = "waddk ap gpmw ao qyxc afv e od pgilaju r vddw ldok bh cshwpcx io wfyfpii afv zstknpl lalk nhify pvv oxnayafvmt qmszfrm dr kzetk dty ewpvfw";
    password = "PASSWORT";
    string result2;
    decrypt(text,password,result2);
    
    cout << result2 << endl;    
    return 0;
}



