
//
// Created by mateusz on 10.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include "string"
#include "iostream"
#include "list"
#include <regex>
#include <set>

using namespace std;

namespace datastructures
{
    class Counts{
    private:
        friend class WordCounter;
        int Value;
    public:
        Counts();
        Counts(int);
        ~Counts();
        Counts & operator++();
        bool operator<(Counts) const;
        bool operator>(Counts) const;
        bool operator==(Counts) const; };
    class Word{
        friend class WordCounter;
        string String;
    public:
        Word();
        Word(string str);
        ~Word();
        bool operator<(Word) const;
        bool operator==(Word) const; };
    class WordCounter {
        list<pair<Word, Counts>> Dictionary;
    public:
        WordCounter();
        WordCounter(initializer_list<Word>);
        ~WordCounter();
        int operator[](string wanted);
        int DistinctWords();
        int TotalWords();
        set<Word> Words();
    };
}

using namespace datastructures;

#endif //JIMP_EXERCISES_WORDCOUNTER_H