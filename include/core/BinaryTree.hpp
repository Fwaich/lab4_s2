#pragma once
#include <sstream>
#include <functional>
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
        delete traversal;
    }

    TreeIterator<T> iterator() {
        return TreeIterator<T>(root, traversal);
    }

    void set_traversal(TreeTraversal<T>* new_traversal){
        delete traversal;
        traversal = new_traversal;
    }

    bool contains(const T& value) {
        auto it = iterator();
        while (it.has_next()) {
            if (it.next() == value) {
                return true;
            }
        }
        return false;
    }

    std::string to_string() {
        std::ostringstream oss;
        auto it = iterator();
        while (it.has_next()) {
            oss << it.next() << ' ';
        }
        return oss.str();
    }

    void add(T value) {
        root = add_r(root, value);
    }

    void remove(const T& value) {
        bool found = false;
        root = remove_r(root, value, found);
        if (!found) {
            throw std::runtime_error("Element not found");
        }
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

    tnode* remove_r(tnode* node, const T& value, bool& found) {
        if (!node) return nullptr;
    
        if (value < node->data) {
            node->left = remove_r(node->left, value, found);
        } else if (value > node->data) {
            node->right = remove_r(node->right, value, found);
        } else {
            found = true;
    
            // случай 1: один или ноль потомков
            if (!node->left) {
                tnode* right = node->right;
                delete node;
                return right;
            } else if (!node->right) {
                tnode* left = node->left;
                delete node;
                return left;
            }
    
            // случай 2: два потомка
            tnode* min_node = find_min_node(node->right);
            node->data = min_node->data;
            node->right = remove_r(node->right, min_node->data, found);
        }
        return node;
    }

};

template <typename T>
TreeNode<T>* find_min_node(TreeNode<T>* node) {
    while (node->left) node = node->left;
    return node;
}
