//
// Created by kerni on 11.06.17.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <Tree.h>

using namespace std;

namespace tree {

    template <class T>
    class TreeIterator {
    public:
        Tree<T> *root;
        TreeIterator(){};
        TreeIterator(Tree<T> * root_);

        //from labs
        const void PushBack(const T new_value){
            itered.push_back(new_value);
        }

        //operators
        void operator++();
        bool operator!=(const TreeIterator &other)const;
        T operator*();

        int iterator;
        vector<T> itered;

    };

    template <class T>
    TreeIterator<T>::TreeIterator(Tree<T> *_root) {
        root = _root;
        iterator = 0;
    }

    template <class T>
    void TreeIterator<T>::operator++() {
        iterator++;
    }

    template <class T>
    bool TreeIterator<T>::operator!=(const TreeIterator &other) const {
        return this->iterator != other.iterator;
    }

    template <class T>
    T TreeIterator<T>::operator*() {
        return itered[iterator];
    }


    //=============================== INORDER (SAME FILE, WRONG TESTS) ===============================


    template <class T>
    class InOrderTreeIterator : public TreeIterator<T> {
    public:
        InOrderTreeIterator(){};
        InOrderTreeIterator(Tree<T> * ptr);
        void BuildVector(Tree<T> *node);
    };

    template <class T>
    InOrderTreeIterator<T>::InOrderTreeIterator(Tree<T> *ptr) : TreeIterator<T>(ptr){
        BuildVector(ptr);
    }

    template <class T>
    void InOrderTreeIterator<T>::BuildVector(Tree<T> *node) {
        if (node->left)
            BuildVector(node->left.get());

        this->PushBack(node->value);

        if (node->right)
            BuildVector(node->right.get());
    }


    template <class T>
    class InOrderTreeView {
    public:
        InOrderTreeView(){};
        InOrderTreeView(Tree<T> * root);
        InOrderTreeIterator<T> begin();
        InOrderTreeIterator<T> end();
        InOrderTreeIterator<T> in_iterator;
    };

    template <class T>
    InOrderTreeView<T>::InOrderTreeView(Tree<T> *root) : in_iterator(root)  {
    }

    template <class T>
    InOrderTreeIterator<T> InOrderTreeView<T>::begin() {
        in_iterator.iterator = 0;
        return in_iterator;
    }

    template <class T>
    InOrderTreeIterator<T> InOrderTreeView<T>::end() {
        in_iterator.iterator = int(in_iterator.itered.size());
        return in_iterator;
    }

    template <class T>
    InOrderTreeView<T> InOrder(Tree<T> *root){
        return InOrderTreeView<T>(root);
    }


    //=============================== POSTORDER (SAME FILE, WRONG TESTS) ===============================

    template <class T>
    class PostOrderTreeIterator : public TreeIterator<T> {
    public:
        PostOrderTreeIterator(){};
        PostOrderTreeIterator(Tree<T> * ptr);
        void BuildVector(Tree<T> *node);
    };

    template <class T>
    PostOrderTreeIterator<T>::PostOrderTreeIterator(Tree<T> *ptr) : TreeIterator<T>(ptr){
        BuildVector(ptr);
    }

    template <class T>
    void PostOrderTreeIterator<T>::BuildVector(Tree<T> *node) {
        if (node->left)
            BuildVector(node->left.get());
        if (node->right)
            BuildVector(node->right.get());

        this->PushBack(node->value);
    }


    template <class T>
    class PostOrderTreeView {
    public:
        PostOrderTreeView(){};
        PostOrderTreeView(Tree<T> * root);
        PostOrderTreeIterator<T> begin();
        PostOrderTreeIterator<T> end();
        PostOrderTreeIterator<T> tree_iterator;
    };

    template <class T>
    PostOrderTreeView<T> PostOrder(Tree<T> *root){
        return PostOrderTreeView<T>(root);
    }

    template <class T>
    PostOrderTreeIterator<T> PostOrderTreeView<T>::begin() {
        tree_iterator.iterator = 0;
        return tree_iterator;
    }

    template <class T>
    PostOrderTreeIterator<T> PostOrderTreeView<T>::end() {
        tree_iterator.iterator = int(tree_iterator.itered.size());
        return tree_iterator;
    }

    template <class T>
    PostOrderTreeView<T>::PostOrderTreeView(Tree<T> *root):tree_iterator(root)  {
    }

    template <class T>
    class PreOrderTreeIterator : public TreeIterator<T> {
    public:
        PreOrderTreeIterator(){};
        PreOrderTreeIterator(Tree<T> * ptr);
        void BuildVector(Tree<T> *node);
    };

    template <class T>
    PreOrderTreeIterator<T>::PreOrderTreeIterator(Tree<T> *ptr) : TreeIterator<T>(ptr){
        BuildVector(ptr);
    }

    template <class T>
    void PreOrderTreeIterator<T>::BuildVector(Tree<T> *node) {
        this->PushBack(node->value);
        if (node->left)
            BuildVector(node->left.get());
        if (node->right)
            BuildVector(node->right.get());
    }


    template <class T>
    class PreOrderTreeView {
    public:
        PreOrderTreeView(){};
        PreOrderTreeView(Tree<T> * root);
        PreOrderTreeIterator<T> begin();
        PreOrderTreeIterator<T> end();
        PreOrderTreeIterator<T> pre_iterator;
    };


    template <class T>
    PreOrderTreeView<T> PreOrder(Tree<T> *root){
        return PreOrderTreeView<T>(root);
    }

    template <class T>
    PreOrderTreeIterator<T> PreOrderTreeView<T>::begin() {
        pre_iterator.iterator = 0;
        return pre_iterator;
    }

    template <class T>
    PreOrderTreeIterator<T> PreOrderTreeView<T>::end() {
        pre_iterator.iterator = int(pre_iterator.itered.size());
        return pre_iterator;
    }


    template <class T>
    PreOrderTreeView<T>::PreOrderTreeView(Tree<T> *root) : pre_iterator(root)  {
    }



}

#endif //JIMP_EXERCISES_TREEITERATORS_H
