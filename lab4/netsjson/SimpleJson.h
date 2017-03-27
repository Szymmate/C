//
// Created by kerni on 26.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <map>
#include <vector>
#include <iostream>

using std::string;
using std::map;
using std::vector;
using std::experimental::optional;
using ::std::literals::operator""s;

namespace nets {
    class JsonValue {

    public:

        ~JsonValue();
        JsonValue(double _value);
        JsonValue(int _value);
        JsonValue(string _value);
        JsonValue(bool _value);
        JsonValue(vector<JsonValue> _value);
        JsonValue(map<string, JsonValue> _value);

        optional<JsonValue> ValueByName(const string &name) const;
        string ToString() const;


    private:

        optional<double> _d;
        optional<int> _i;
        optional<string> _s;
        optional<bool> _b;
        optional<vector<JsonValue>> _v; // Value array of JSON
        map<string, JsonValue> _m; // JSON Object


    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
