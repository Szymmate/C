//
// Created by mateusz on 06.03.17.
//

#include "DoubleBasePalindromes.h"

using namespace std;
bool is_palindrome(std::string palindrome_1) {
    int left;
    int right;
    bool flag = true;
    for (left = 0, right = palindrome_1.length() - 1; left <= right; left++, right--) {
        if (palindrome_1[left] != palindrome_1[right]) {
            flag = false;
            break;
        }
    }
    return flag;
}


string decimal_to_binary(int decimal){
    string bin;
    char holder=' ';
    while(decimal!=0){
        holder=decimal%2+'0';
        bin=holder+bin;
        decimal/=2;}
    return bin;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t sum=0;
    int decimal;
    string binar;
    string str_decimal;
    bool flag_decimal;
    bool flag_binar;
    for (decimal=1; decimal<=max_vaule_exculsive; decimal++){
        str_decimal=to_string(decimal);
        flag_decimal=is_palindrome(str_decimal);
        if (flag_decimal){
            binar=decimal_to_binary(decimal);
            flag_binar=is_palindrome(binar);
            if (flag_binar)
                sum=sum+decimal;
        }
    }
    return sum;}