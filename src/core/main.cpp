#include <iostream>
#include "core/BinaryTree.hpp"
#include "core/TreeSequence.hpp"
#include "core/Sequence.hpp"

int main() {

    Sequence<int>* a = new TreeSequence<int>();
    
    a->add(5);
    a->add(1);
    a->add(2);
    a->add(3);
    a->add(4);
    a->add(6);
    a->add(7);
    a->add(8);
    a->add(9);
    a->add(10);

    if (a->contains(2)) std::cout << "yes" << std::endl;

    std::cout << a->to_string() << std::endl;

    Sequence<int>* b = a->extract_subtree(1);
    std::cout << b->to_string() << std::endl;
        
    delete a;
    return 0;
}
