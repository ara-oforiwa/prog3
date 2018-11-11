/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**@file  main.cpp
 * File:   main.cpp
 * Author: Chen
 *
 * Created on October 9, 2018, 11:07 PM
 */

#include <iostream>
#include <string>

#include "main.h"

using namespace std;

// The number of letters in the used alphabet
int const MAX_CHAR_VAL = 26;

/**
 * This program encrypts and decrypts text using the Vigenere algorithm.
 */
int main() {

    string clear_text = "hallo my name is chen and i am writing a code that is capable of encrypting and decrypting text using the vinigere quadrat method in an overly complicated manner";
    string password = "HOCHSCHULE";

    string encrypted_text;
    encrypt(clear_text, password, encrypted_text);
    cout << "The encrypted text is:\n" << encrypted_text << endl;
    
    string decrypted_text;
    decrypt(encrypted_text,password,decrypted_text);  
    cout << "The decrypted text is:\n" << decrypted_text << endl;    
    
    cout << "Press any key to continue..." << endl;
    cin.sync();
    cin.get();
    
    return 0;
}

/**
 * A generic function for the encryption or decryption, it takes the text 
 * (either original or encrypted), the password, an output string and a pointer 
 * to the function that performs the required operation; encryption or decryption.
 * @param text the text to encrypt/decrypt 
 * @param password A password to be used for encryption/decryption
 * @param code An output variable that returns the encrypted or decrypted text.
 * @param operation A pointer to the function performing the required operation.
 */
void enc_dec_vigenere(string text, string password, string &code, char (*operation)(int,int)){
    int text_index = 0;
    int pass_index = 0;
    
    // Traverses the input text 
    while (text_index < text.size()){
        // Spaces are not encrypted, text index is incremented but not
        // the password index, to keep pass aligned with text.
        if(text[text_index] == ' '){
            code  += ' ';
            text_index++;
        }
        else{
            // The index of the current character
            int num_char = value(text[text_index]); 
            
            // While the numeric value of the character is between 1 and 26
            // a shift index between 0 and 25 is required, hence the decrement.
            int shift_index = value(password[pass_index]) - 1;
            
            // 'operation' shifts the character by the required amount backwards
            // of forward, depending on the provided function.
            char new_letter = operation(num_char, shift_index);
            
            // The new letter is concatenated to the output string
            code += new_letter;
     
            text_index++;       
            // Password index is incremented, if it exceeds the length of the 
            // password, modulo will cycle back to zero.
            pass_index = (pass_index + 1) % password.size();
        }
    }
}

/**
 * Masks in the least significant 5 bits of an ASCII character numeric value.
 * A number representing a letter between a and z (1-26 respectively) is returned.
 * 01100100
 * AND
 * 00011111 
 */
int value(char c){
    return c & 31;
}

/**
 * Takes an index of a letter a to z (1-26) and completes the required most 
 * significant bits of its ASCII representation, the respective char is returned.
 */
char symbol(int n){
    return n | 96;
}

/**
 * Calculates the character that is achieved by shifting backwards as used in
 * the Vigenere decryption process. Shifting is cyclic.
 */
char shift_forward(int n_char,int shift_index) {
    int result = n_char + shift_index;
    if(result > MAX_CHAR_VAL){
        result = result - MAX_CHAR_VAL;
    }
    return symbol(result);
}

/**
 * Calculates the character that is achieved by shifting forward as used in
 * the Vigenere encryption process. Shifting is cyclic.
 */
char shift_backwards(int n_char,int shift_index){
    int result = n_char - shift_index;
    if(result <= 0){
        result = result + MAX_CHAR_VAL;
    }
    return symbol(result);
}

/**
 * An interface to the encryption process, calls the generic function with the
 * required operation
 */
void encrypt(string text, string password, string &code){
    enc_dec_vigenere(text,password,code,shift_forward);
}

/**
 * An interface to the decryption process, calls the generic function with the
 * required operation
 */
void decrypt(string code, string password, string &text){
    enc_dec_vigenere(code, password, text, shift_backwards);
}

