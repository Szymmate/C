//
// Created by mateusz on 09.03.17.
//

#include "XorCypherBreaker.h"
std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary){

}
#include <algorithm>
using std::find;
using std::vector;
using std::string;

vector<string> dictionary {"the","of"};

//THERE ARE BETTER WAYS TO LOOK FOR A WORD BUT IT WORKS
find(dictionary.begin(), dictionary.end(),"of")