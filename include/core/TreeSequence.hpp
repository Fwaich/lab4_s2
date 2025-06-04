#pragma once
#include <functional>
#include <sstream>
#include "core/BinaryTree.hpp"
#include "core/Sequence.hpp"

template<typename T>
class TreeSequence : public Sequence<T> {
private:
    BinaryTree<T>* tree;
    
public:
    TreeSequence() : tree(new BinaryTree<T>()) {}

    ~TreeSequence() {
        delete tree;
    }

    Sequence<T>* add(T value) override {
        tree->add(value);
        return this;
    }

    Sequence<T>* set_traversal(TreeTraversal<T>* new_traversal) override {
        tree->set_traversal(new_traversal);
        return this;
    }

    Sequence<T>* map(std::function<void(T&)> func) override {
        tree->traverse(func);
        return this;
    }

    Sequence<T>* merge(Sequence<T>* other) override {
        // tree->traverse(other.tree->get_root(), [this](T& value){
        //     this->add(value);
        // });
        return this;
    }

    bool contains(T value) const override {
        bool found = false;
        tree->traverse([&found, value](T& data){
            if (data == value) found = true;
        });
        return found;
    }

    bool contains_subtree(Sequence<T>* other) const override {
        //для этого должен быть один обход
        std::string main_str = this->to_string();
        std::string sub_str = other->to_string();
        return main_str.find(sub_str) != -1;
    }
    

    std::string to_string() const {
        std::ostringstream oss;
        tree->traverse([&oss](const T& data){
            oss << data << " ";
        });
        return oss.str();
    }

    TreeSequence<T>& operator+=(const T& value) {
        this->add(value);
        return *this;
    }

};

