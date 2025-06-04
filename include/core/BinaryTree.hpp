#pragma once
#include "core/TreeNode.hpp"
#include "core/Traversal.hpp"
#include "core/TreeIterator.hpp"

template <typename T>
class BinaryTree {
public:
    using tnode = TreeNode<T>;

private:
    tnode* root;
    TreeTraversal<T>* traversal;

public:
    BinaryTree(TreeTraversal<T>* new_traversal = new InOrderTraversal<T>())
    : root(nullptr), traversal(new_traversal) {}

    ~BinaryTree() {
        clear();
    }

    TreeIterator<T> iterator() {
        return TreeIterator<T>(root, traversal);
    }

    void set_traversal(TreeTraversal<T>* new_traversal){
        delete traversal;
        traversal = new_traversal;
    }

    bool contains(T value) {
        TreeIterator<T> it = iterator();
        while (it.has_next()) {
            if (it.next() == value) {
                return true;
            }
        }
        return false;

    }

    void add(T value) {
        root = add_r(root, value);
    }

    void clear() {
        clear_r(root);
        root = nullptr;
    }

private:
    tnode* add_r(tnode* node, T value) {
        if (node == nullptr) return new tnode(value);
        if (value < node->data) node->left = add_r(node->left, value);
        else if (value > node->data) node->right = add_r(node->right, value);
        return node;
    }

    void clear_r(tnode* node) {
        if (!node) return;
        clear_r(node->left);
        clear_r(node->right);
        delete node;
    }

};


// template <typename T>
// bool BinaryTree<T>::match_tree_r(tnode* n1, tnode* n2) const {
//     if (!n1 && !n2) return true; 
//     if (!n1 || !n2) return false;
//     if (n1->data != n2->data) return false;
//     return match_tree_r(n1->left, n2->left) && match_tree_r(n1->right, n2->right);
// }

// template <typename T>
// bool BinaryTree<T>::contains_subtree_r(tnode* main, tnode* sub) const {
//     if (!sub) return true;     // пустое дерево — всегда поддерево
//     if (!main) return false;
//     if (match_tree_r(main, sub)) return true;
//     return contains_subtree_r(main->left, sub) || contains_subtree_r(main->right, sub);
// }
