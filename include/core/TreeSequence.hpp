#pragma once
#include <functional>
#include <sstream>
#include "core/BinaryTree.hpp"
#include "core/Traversal.hpp"

template<typename T>
class TreeSequence {
private:
    BinaryTree<T>* tree;
    
public:
    TreeSequence() : tree(new BinaryTree<T>()) {}

    ~TreeSequence() {
        delete tree;
    }

    void add(T value) {
        tree->add(value);
    }

    void map(std::function<void(T&)> func){
        TreeSequence<T>* result = new TreeSequence<int>;

    }

    // bool contains(T value) const {
    //     bool found = false;
    //     tree->traverse([&found, value](T& data){
    //         if (data == value) found = true;
    //     });
    //     return found;
    // }

    // void merge(const TreeSequence<T>& other) {
    //     tree->traverse(other.tree->get_root(), [this](T& value){
    //         this->add(value);
    //     });
    // }

    std::string to_string() const {
        std::ostringstream oss;
        tree->traverse([&oss](const T& data){
            oss << data << " ";
        });
        return oss.str();
    }

    // bool contains_subtree(const TreeSequence<T>& other) const {
    //     std::string main_str = this->to_string();
    //     std::string sub_str = other.to_string();
    //     return main_str.find(sub_str) != std::string::npos;
    // }
};
