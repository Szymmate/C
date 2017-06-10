//
// Created by mateusz on 2.06.17.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#include <vector>
#include <map>

template <class T, class Id>
class SequentialIdGenerator {
public:
    SequentialIdGenerator(){}
    void Add(T object){repo_.insert({id_,object});++id_;}
    SequentialIdGenerator(const Id &set): id_(set){}
    T operator[](Id n) { return repo_[n]; }
    auto Size(){return repo_.size();}
    int NextValue(){
        if(!first_) ++id_;
        first_=false;
        return int(id_);
    }
private:
    bool first_=true;
    std::map<Id, T> repo_;
    Id id_=0;
};

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
