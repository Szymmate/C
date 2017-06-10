//
// Created by mateusz on 4.06.17.
//


#include <TimeRecorder.h>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

int main(){
    int retint(int a);
    double retdouble(double b);
    std::string retstring (std::string c);

    auto x = time_recorder(&retint());
    cout<<"time:  "<<x.first<<"  ,  val:"<<x.second<<endl;

    auto y = time_recorder(&retdouble);
    cout<<"time:  "<<x.first<<"  ,  val:"<<x.second<<endl;

    auto z = time_recorder(&retstring);
    cout<<"time:  "<<x.first<<"  ,  val:"<<x.second<<endl;
}