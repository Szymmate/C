//
// Created by kerni on 18.03.17.
//

#include "SmartTree.h"

//using namespace std;

namespace datastructures {

    std::unique_ptr <SmartTree> CreateLeaf(int value){
        std::unique_ptr<SmartTree> leaf  = std::make_unique<SmartTree>();
        leaf -> value = value;
        leaf -> left = nullptr;
        leaf -> right = nullptr;
        return leaf;
    }

    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        if (tree->left == nullptr) {
            tree -> left =  std::move(left_subtree);
        }
        return tree;
    }

    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        if (tree->right == nullptr) {
            tree -> right =  std::move(right_subtree);
        }
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if (unique_ptr != nullptr){
            if (unique_ptr->left) PrintTreeInOrder(unique_ptr->left,out);
            *out << unique_ptr->value << ", ";
            if (unique_ptr->right) PrintTreeInOrder(unique_ptr->right,out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree)    {
        std::string out = "";
       out.append("[");
        if (tree != nullptr){
            out.append(std::to_string(tree->value));
            out.append(" ");
            out.append(DumpTree(tree->left));
            out.append(" ");
            out.append(DumpTree(tree->right));
            return out + "]";
        }
        else
        {
            return "[none]";
        }
    }

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){

        std::unique_ptr <SmartTree> tree1 = CreateLeaf(0);
        std::string tmp="";
        int i=1;
        int j,bracket;

        //Loading left/right subtree to string
        while(tree[i]!=' ' && tree[i]!=']'){
            tmp+=tree[i];
            i++;
        }

        //Break condition
        if(tmp=="none") return 0;

        //For negative
        if(tmp!="none" && tmp[0]=='-'){
            for (int k=1; k<tmp.size(); k++) tree1->value=10*tree1->value+tmp[k]-'0';
            tree1->value*=-1;
        }

        //For positive
        if(tmp!="none"&&tmp[0]!='-'){
            for (int k=0; k<tmp.size(); k++) tree1->value=10*tree1->value+tmp[k]-'0';
        }

        //Brackets
        i+=1;
        j=i;
        bracket=1;
        while(bracket>0){
            i++;
            if(tree[i]=='[') bracket++;
            if(tree[i]==']') bracket--;
        }
        tree1->left=RestoreTree(tree.substr(j,i-1));

        j=i+2;
        i+=2;
        bracket=1;
        while(bracket>0){
            i++;
            if(tree[i]=='[') bracket++;
            if(tree[i]==']') bracket--;
        }
        tree1->right=RestoreTree(tree.substr(j,i-1));

        return tree1;
    }

    };