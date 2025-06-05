#pragma once
#include "core/Traversal.hpp"

class ITraversal {
public:
    virtual ~ITraversal() = default;
};

template<typename T>
class TreeTraversalAdapter : public ITraversal {
private:
    TreeTraversal<T>* traversal;

public:
    TreeTraversalAdapter(TreeTraversal<T>* traversal)
        : traversal(traversal) {}

    ~TreeTraversalAdapter() override {
        delete traversal;
    }

    TreeTraversal<T>* get() const {
        return traversal;
    }
};
