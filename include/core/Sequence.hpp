#pragma once
#include "core/Traversal.hpp"

template <typename T>
class Sequence 
{
public:
    virtual ~Sequence() = 0;

    virtual Sequence<T>* add(T value) = 0;
    virtual Sequence<T>* set_traversal(TreeTraversal<T>* new_traversal) = 0;
    virtual Sequence<T>* map(std::function<void(T&)> func) = 0;
    virtual Sequence<T>* merge(Sequence<T>* other) = 0;
    
    virtual bool contains(T value) const = 0;
    virtual bool contains_subtree(Sequence<T>* other) const = 0;
    
    virtual std::string to_string() const = 0;
};

template<typename T>
Sequence<T>::~Sequence() {}