//
// Created by mateusz on 06.03.17.
//

#include "Palindrome.h"
using namespace std;
bool is_palindrome(std::string palindrome_1){
    int left;
    int right;
    bool flag=true;
    for(left=0, right=palindrome_1.length()-1; left <=right; left++ ,right --){
        if (palindrome_1[left] != palindrome_1[right]){
            flag=false;
            break;
        }
    }
    return flag;
}
