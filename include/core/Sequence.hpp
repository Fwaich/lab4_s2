#pragma once
#include "core/Traversal.hpp"

template <typename T>
class Sequence 
{
public:
    virtual ~Sequence() = 0;

    virtual Sequence<T>* add(T value) = 0;
    virtual Sequence<T>* remove(const T& value) = 0;
    virtual Sequence<T>* set_traversal(TreeTraversal<T>* new_traversal) = 0;
    
    virtual bool contains(const T& value) const = 0;
    virtual Sequence<T>* map(const double& factor) = 0;
    virtual Sequence<T>* where(std::string value) = 0;
    virtual Sequence<T>* extract_subtree(const T& value) const = 0;
    
    virtual std::string to_string() const = 0;
};

template<typename T>
Sequence<T>::~Sequence() {}