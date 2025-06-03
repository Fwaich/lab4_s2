#include <iostream>
#include "core/BinaryTree.hpp"
#include "core/TreeSequence.hpp"

int main() {

    TreeSequence<int>* a = new TreeSequence<int>();
    
    a->add(1);
    a->add(2);
    a->add(3);

    std::cout << a->to_string() << std::endl;
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
