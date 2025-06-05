#include <iostream>
#include "core/BinaryTree.hpp"
#include "core/TreeSequence.hpp"
#include "core/Sequence.hpp"

int main() {

    Sequence<int>* a = new TreeSequence<int>();
    
    a->add(1);
    a->add(2);
    a->add(3);

    if (a->contains(2)) std::cout << "yes" << std::endl;

    std::cout << a->to_string() << std::endl;

    a->remove(3);

    std::cout << a->to_string() << std::endl;
        
    delete a;
    return 0;
}
