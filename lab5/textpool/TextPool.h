//
// Created by mateusz on 4.04.17
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <set>
#include <algorithm>
#include <experimental/string_view>

namespace pool {
    class TextPool {
    public:
        TextPool() {}
        TextPool(const std::initializer_list<std::experimental::string_view> &words) : text(words) {}
        std::set<std::experimental::string_view> text;
        size_t StoredStringCount() const;
        std::experimental::string_view Intern(const std::string &str);
        TextPool(const TextPool &pool) = delete;
        TextPool(TextPool &&pool);
        TextPool &operator=(const TextPool &pool) = delete;
        TextPool &operator=(TextPool &&pool);
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H