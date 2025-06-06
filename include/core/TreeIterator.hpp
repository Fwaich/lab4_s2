#pragma once
#include "core/Traversal.hpp"
#include "core/TreeNode.hpp"

template<typename T>
class TreeTraversal;

template <typename T>
class TreeIterator {
    std::vector<TreeNode<T>*> nodes;
    size_t index = 0;

public:
    TreeIterator(TreeNode<T>* root, TreeTraversal<T>* traversal) {
        traversal->traverse(root, nodes);
    }

    bool has_next() const {
        return index < nodes.size();
    }

    T& next() {
        return nodes[index++]->data;
    }

    void reset() { index = 0; }
};
