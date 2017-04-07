//
// Created by mateusz on 4.04.17
//

#include "TextPool.h"
#include <iostream>

namespace pool {
    TextPool::TextPool(TextPool &&pool){
        text.clear();
        std::swap(text, pool.text); }
    std::experimental::string_view TextPool::Intern(const std::string &str){
        for (auto s : text) {
            if (s.compare(str)==0){
                return s; }}
        std::experimental::string_view sv {str};
        text.insert(sv);
        return sv; }
    TextPool & TextPool::operator=(TextPool &&pool){
        if (this==&pool) {
            return *this; }
        else {
            text.clear();
            std::swap(text, pool.text); }}
    size_t TextPool::StoredStringCount() const {
        return text.size(); }
}