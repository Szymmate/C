//
// Created by kerni on 26.03.2017.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "SimpleJson.h"

using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::nets::JsonValue;
using ::std::literals::operator""s;

int main() {

    vector<JsonValue> js {JsonValue{56.6},JsonValue{45},JsonValue{"abc"s}};
    map<string, JsonValue> obj_v {{"account_balance", {-107.89}},{"values",JsonValue{js}},{"name",JsonValue{"Test name"s}},{"age",JsonValue{13}}};
    JsonValue obj {obj_v};
    cout<<obj.ToString();
{"age": 13, "name": "Test name", "values": [56.6, 45, "abc"]} kolejność argumentów nie ma znaczenia w przypadku obiektu

cout << obj.ToString() << endl;
 cout << "name: " << obj.ValueByName("name")->ToString() << endl;
   cout << "values: " << obj.ValueByName("values")->ToString() << endl;
   cout << "age: " << obj.ValueByName("age")->ToString() << endl;
   //obiekty optional można traktować jak wartości boolean (true wartość obecna, false optional jest pusty)
   if (obj.ValueByName("xyz")) {
       cout << "is present" << endl;
   } else {
       cout << "is absent" << endl;
   }
    map<string, JsonValue> obj_2 {{R"(\"abc\")"s, JsonValue{10}}};
    JsonValue obj2 = JsonValue{obj_2};
    cout<<obj2.ToString();

}

