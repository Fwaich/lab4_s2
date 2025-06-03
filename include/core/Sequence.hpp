#pragma once
#include "core/BinaryTree.hpp"

template <typename T>
class Sequence 
{
    virtual ~Sequence() = 0;

    virtual Sequence<T>* add(T value) = 0;
    virtual Sequence<T>* merge_with(Sequence<T>* other) = 0;
    
    virtual bool search(T value) const = 0;
    virtual bool contains_subtree(Sequence<T>* other) const = 0;
    
    virtual std::string to_string() const = 0;
};