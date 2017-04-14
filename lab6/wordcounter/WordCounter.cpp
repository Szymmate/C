//
// Created by mateusz on 10.04.17.
//

#include "WordCounter.h"

Counts::Counts() {}
Counts::~Counts() {}
Counts::Counts(int number) {
    Value = number; }
Counts & Counts::operator++() {
    Value++;
    return *this; }
bool Counts::operator<(Counts argument) const {
    return (Value<argument.Value); }
bool Counts::operator==(Counts argument) const {
    return (Value==argument.Value); }
bool Counts::operator>(Counts argument) const {
    return (Value>argument.Value); }
Word::Word() {}
Word::~Word() {}
Word::Word(string value) {
    String = value; }
bool Word::operator<(Word argument) const {
    return (String<argument.String); }
bool Word::operator==(Word argument) const {
    return (String==argument.String); }
WordCounter::WordCounter() {}
WordCounter::WordCounter(initializer_list<Word> list) {
    int IsInside;
    for (auto element : list) {
        IsInside = 0;
        for(pair<Word, Counts> pair : Dictionary) {
            if (pair.first.String == element.String) {
                ++find(Dictionary.begin(), Dictionary.end(), pair)->second;
                IsInside = 1;
                break; }}
        if (IsInside == 0) {
            Counts new_counter{1};
            Dictionary.emplace_back(std::make_pair(element, new_counter)); }}}

WordCounter::~WordCounter() {}

int WordCounter::TotalWords() {
    int total = 0;
    for(pair<Word, Counts> pair : Dictionary) {
        total += pair.second.Value; }
    return total; }
int WordCounter::DistinctWords() {
    return Dictionary.size(); }
int WordCounter::operator[](string searched_value) {
    for(auto element : Dictionary) {
        if(element.first.String == searched_value)
            return element.second.Value; }
    return 0; }
set<Word> WordCounter::Words() {
    set<Word> output_set;
    Dictionary.sort([](const pair<Word, Counts> & a, const pair<Word, Counts> & b) { return a.second > b.second; });
    for(auto element : Dictionary) {
        output_set.emplace(element.first); }
    return output_set; }