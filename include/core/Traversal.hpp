#pragma once
#include <functional> 
#include "core/BinaryTree.hpp"
#include "core/TreeNode.hpp"



template<typename T>
class TreeTraversal {
public:
    virtual void traverse(TreeNode<T>* node, std::function<void(T&)> func) = 0;
    virtual ~TreeTraversal() = default;
};

template<typename T>
class InOrderTraversal : public TreeTraversal<T> { //LKP
public:
    void traverse(TreeNode<T>* node, std::function<void(T&)> func) override {
        if (!node) return;
        traverse(node->left, func);
        func(node->data);
        traverse(node->right, func);
    }
};

template<typename T>
class PreOrderTraversal : public TreeTraversal<T> { //KLP
public:
    void traverse(TreeNode<T>* node, std::function<void(T&)> func) override {
        if (!node) return;
        func(node->data);
        traverse(node->left, func);
        traverse(node->right, func);
    }
};

template<typename T>
class PostOrderTraversal : public TreeTraversal<T> { //LPK
public:
    void traverse(TreeNode<T>* node, std::function<void(T&)> func) override {
        if (!node) return;
        traverse(node->left, func);
        traverse(node->right, func);
        func(node->data);
    }
};