//
// Created by mateusz on 06.03.17.
//

#include "DoubleBasePalindromes.h"

using namespace std;

bool is_palindrome(std::string palindrome_1){
    string palindrome_2;
    int left;
    int right;
    bool flag;
    palindrome_2=palindrome_1;
    for(left=0, right=palindrome_2.length()-1; left<=right; left++ ,right --){
        if (palindrome_2[left] != palindrome_2[right]){
            flag=false;
            break;}
        else{
            flag= true;}
    }
    return flag;}


string decimal_to_binary(uint64_t decimal){
    string bin;
    char holder=' ';
    while(decimal!=0){
        holder=decimal%2+'0';
        bin=holder+bin;
        decimal/=2;}
    return bin;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t sum;
    sum=0;
    uint64_t decimal;
    string binar;
    string str_decimal;
    bool flag_decimal;
    bool flag_binar;
    for (decimal=1; decimal<=max_vaule_exculsive; decimal++){
        str_decimal=to_string(decimal);
        binar=decimal_to_binary(decimal);
        flag_decimal=is_palindrome(str_decimal);
        flag_binar=is_palindrome(binar);
        if (flag_decimal && flag_binar){
            sum=sum+decimal;}
    }
    return sum;}