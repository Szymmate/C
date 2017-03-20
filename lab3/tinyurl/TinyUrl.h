//
// Created by mateusz on 18.03.17.
//


#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>
using namespace std;

namespace tinyurl
{
    struct TinyUrlCodec{ array<char, 6> tab; map<string,string> kod;};
    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}

using namespace tinyurl;

#endif //JIMP_EXERCISES_TINYURL_H
