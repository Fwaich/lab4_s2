#pragma once
#include <functional>
#include "core/Traversal.hpp"
#include "core/BinaryTree.hpp"
#include "core/Sequence.hpp"

template<typename T>
class TreeSequence : public Sequence<T> {
private:
    BinaryTree<T>* tree;
    
public:
    TreeSequence() : tree(new BinaryTree<T>()) {}

    TreeSequence(BinaryTree<T>* new_tree) : tree(new_tree) {}

    ~TreeSequence() {
        delete tree;
    }

    Sequence<T>* add(T value) override {
        tree->add(value);
        return this;
    }

    Sequence<T>* remove(const T& value) override {
        tree->remove(value);
        return this;
    }

    Sequence<T>* set_traversal(TreeTraversal<T>* new_traversal) override {
        tree->set_traversal(new_traversal);
        return this;
    }

    bool contains(const T& value) const override {
        return tree->contains(value);
    }

    Sequence<T>* extract_subtree(const T& value) const override {
        BinaryTree<T>* subtree = tree->extract_subtree(value);
        return new TreeSequence<T>(subtree);
    }

    std::string to_string() const override {
        return tree->to_string();
    }

    TreeSequence<T>& operator+=(const T& value) {
        this->add(value);
        return *this;
    }

};

