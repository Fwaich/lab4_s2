#pragma once
#include <functional> 
#include "core/BinaryTree.hpp"
#include "core/TreeNode.hpp"

template <typename T>
class TreeTraversal {
public:
    virtual void traverse(TreeNode<T>* root, std::vector<TreeNode<T>*>& result) = 0;
    virtual ~TreeTraversal() = default;
};

template <typename T>
class InOrderTraversal : public TreeTraversal<T> {
public:
    void traverse(TreeNode<T>* node, std::vector<TreeNode<T>*>& result) override {
        if (!node) return;
        traverse(node->left, result);
        result.push_back(node);
        traverse(node->right, result);
    }
};

template <typename T>
class PreOrderTraversal : public TreeTraversal<T> {
public:
    void traverse(TreeNode<T>* node, std::vector<TreeNode<T>*>& result) override {
        if (!node) return;
        result.push_back(node);
        traverse(node->left, result);
        traverse(node->right, result);
    }
};

template <typename T>
class PostOrderTraversal : public TreeTraversal<T> {
public:
    void traverse(TreeNode<T>* node, std::vector<TreeNode<T>*>& result) override {
        if (!node) return;
        traverse(node->left, result);
        traverse(node->right, result);
        result.push_back(node);
    }
};
