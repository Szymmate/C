//
// Created by kerni on 26.03.2017.
//
#include "SimpleJson.h"
#include <string>


using nets::JsonValue;
using std::to_string;
using ::std::literals::operator""s;

JsonValue::~JsonValue(){
    _m.clear();

}

JsonValue::JsonValue(double _value){
    _d = _value;
}

JsonValue::JsonValue(int _value){
    _i = _value;
}

JsonValue::JsonValue(string _value){
    string tmp = _value;
    int i=0;
    while (i<tmp.length()){
        if (tmp[i]=='\"' || tmp[i]=='\\'){
            tmp.insert(i, 1,'\\');
            i++;
        }
        i++;
    }
    _s=tmp;
}

JsonValue::JsonValue(bool _value){
    _b = _value;
}

JsonValue::JsonValue(vector<JsonValue> _value){
    _v = _value;
}

JsonValue::JsonValue(map<string, JsonValue> _value){
    _m = _value;

}

optional<JsonValue> JsonValue::ValueByName(const string &name) const{
    for (auto &n : this->_m) {
        if (n.first==name){
            return n.second;
        }
    }
}

string JsonValue::ToString() const{
    if (_d) {
        string tmp =  to_string(*_d);
        tmp.erase (tmp.find_last_not_of('0') + 1, string::npos);
        return tmp;
    }
    else if (_i) {
        return to_string(*_i);
    }

    else if (_s) {
        string tmp = *_s;
        return "\"" + tmp + "\"";
    }

    else if (_b) {
        if (*_b==false) return "false";
        else if (*_b==true) return "true";
    }

    else if (_v) {
        string tmp = "[";
        for (auto &n : *_v) tmp = tmp+", "+n.ToString();
        tmp += "]";
        tmp = tmp.substr(2);
        tmp[0]='[';
        return tmp;
    }
    else if (&_m != nullptr) {
        string tmp = "{";
        for (auto &n : this->_m) {
            string tmp2 = n.first;
            for (int i=0;i<tmp2.length();i++){
                if (tmp2[i]=='\"' || tmp2[i]=='\\'){
                    tmp2.insert(i, 1,'\\');
                    i++;
                }
            }
            tmp = tmp+"\""+tmp2+"\": "+n.second.ToString()+", ";
        }
        tmp[tmp.size()-2]='}';
        tmp.pop_back();
        return tmp;
    }
}