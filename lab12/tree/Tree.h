//
// Created by kerni on 30.05.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <cstddef>
#include <iostream>

#include <sstream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;

namespace tree{

    template<class T>
    class Tree  {
    public:
        T value;
        Tree();
        Tree(T value);

        unique_ptr<Tree<T>> left;
        unique_ptr<Tree<T>> right;
        int size;
        int depth;

        ~Tree(){};


        auto Root(){
            return this;
        };

        T Value(){
            return value;
        }
        int Size(){
            return size;
        }
        int Depth();

        void Insert(T value);
        bool operator<(const Tree &other) const;

    };

    template<class T>
    Tree<T>::Tree() {
        depth= 0;
        size = 0;
        left = nullptr;
        right = nullptr;
    }

    template<class T>
    Tree<T>::Tree(T _value) {
        size = 1;
        depth = 1;
        this->value = _value;
        left = nullptr;
        right = nullptr;
    }


    template<class T>
    void Tree<T>::Insert(T _value) {
        if (_value < value) {
            if (left != nullptr)
                left->Insert(_value);
            else {
                unique_ptr<Tree<T>> newnode = make_unique<Tree<T>>();
                newnode->value = _value;
                newnode->left = nullptr;
                newnode->right = nullptr;
                this->left = move(newnode);
            }
        }
        else {
            if (right != nullptr)
                right->Insert(_value);
            else {
                unique_ptr<Tree<T>> newnode = make_unique<Tree<T>>();
                newnode->value = _value;
                newnode->left = nullptr;
                newnode->right = nullptr;
                this->right = move(newnode);
            }
        }
        size++;
    }


    template<class T>
    int Tree<T>::Depth(){
        if(this) {
            return 1 + max(this->left->Depth(), this->right->Depth());
        } else {
            return 0;
        }
    }

    template <class T>
    bool Tree<T>::operator<(const Tree &other) const {
        return this->value < other.value;
    }
}



#endif //JIMP_EXERCISES_TREE_H
