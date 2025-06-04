#include <iostream>
#include "core/BinaryTree.hpp"
#include "core/TreeSequence.hpp"
#include "core/Sequence.hpp"

int main() {

    BinaryTree<int>* a = new BinaryTree<int>();
    
    a->add(1);
    a->add(2);
    a->add(3);

    if (a->contains(2)) std::cout << "yes" << std::endl;

    // std::cout << a->to_string() << std::endl;
        
    return 0;
}
