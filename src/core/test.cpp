#include <iostream>
#include "core/BinaryTree.hpp"
#include "core/TreeSequence.hpp"
#include "core/Sequence.hpp"
#include "core/TraversalAdapter.hpp"
#include "core/IntAdapter.hpp"
#include "core/DoubleAdapter.hpp"

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

    ITraversal* tr = new TreeTraversalAdapter(new PostOrderTraversal<double>);
    std::cout << tr << std::endl;
    Adapter* ad = new DoubleAdapter(new TreeSequence<double>());
    std::string str = "21.3";
    ad->add(str);
    ad->add("23.5");
    ad->set_traversal(tr);
    std::cout << ad->to_string() << std::endl;
        
    delete a;
    return 0;
}
