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

#include <iostream>
#include <string>

using namespace std;

// The number of letter in the used alphabet
int const MAX_CHAR_VAL = 26;

// Forward declarations
int value(char c);
char symbol(int n);
char shift_backwards(int n_char,int shift_index);
char shift_forward(int n_char,int shift_index);
void enc_dec_vigenere(string text, string password, string &code, char (*operation)(int,int));
void encrypt(string text, string password, string &code);
void decrypt(string code, string password, string &text);
// Forward declarations

/*
 * This program encrypts and decrypts text using the Vigenere algorithm.
 */
int main(int argc, char** argv) {

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

/*
 * Masks in the least significant 5 bits of an ASCII character numeric value.
 * A number representing a letter between a and z (1-26 respectively) is returned. 
 */
int value(char c){
    return c & 31;
}

/*
 * Takes an index of a letter a to z (1-26) and completes the required most 
 * significant bits of its ASCII representation, the respective char is returned.
 */
char symbol(int n){
    return n | 96;
}

/*
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

/*
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

/*
 * An interface to the encryption process, calls the generic function with the
 * required operation
 */
void encrypt(string text, string password, string &code){
    enc_dec_vigenere(text,password,code,shift_forward);
}

/*
 * An interface to the decryption process, calls the generic function with the
 * required operation
 */
void decrypt(string code, string password, string &text){
    enc_dec_vigenere(code, password, text, shift_backwards);
}

/*
 * A generic function for the encryption or decryption, it takes the text 
 * (either original or encrypted), the password, an output string and a pointer 
 * to the function that performs the required operation; encryption or decryption.
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