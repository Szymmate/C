//
// Created by mateusz on 06.03.17.

#include <iostream>
#include <string>
#include "Palindrome.h"

using namespace std;
int main()
{
    int flag;
    string palindrome;
    bool test;
    cout << "Aby wyjsc wpisz 0, aby sprawdzic palindrome 1\n";
    cin >>flag;
    if (flag==0)
        return 0;
    else{
        cout<< "Prosze podaj napis\n";
        cin >> palindrome;
        test=is_palindrome(palindrome);
        if (test==false)
            cout<< "Wyraz nie jest palindromem\n";
        else
            cout<< "Wyraz jest palindromem\n";
        return 1;
    }



}