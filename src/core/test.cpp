#include <iostream>
#include "core/BinaryTree.hpp"
#include "core/TreeSequence.hpp"
#include "core/Sequence.hpp"
#include "core/TraversalAdapter.hpp"


#include <iostream>
#include <cassert>

int arr_int[] = {5, 3, 8, 1, 4, 6, 9};

void test_add_contains_to_string() {
    std::cout << "test_add_contains_to_string(): ";
    TreeSequence<int>* t = new TreeSequence<int>();
    for (int i = 0; i < 7; ++i) {
        t->add(arr_int[i]);
    }

    assert(t->contains(5));
    assert(t->contains(4));
    assert(!t->contains(100));

    std::string str = t->to_string();
    assert(!str.empty());

    std::cout << "Succesfull" << std::endl;
    delete t;
}

void test_map() {
    std::cout << "test_map(): ";
    TreeSequence<int>* t = new TreeSequence<int>();
    for (int i = 0; i < 5; ++i) {
        t->add(i + 1);  
    }

    t->map(2);
    std::string result = t->to_string();
    assert(result.find("2") != std::string::npos); 
    assert(result.find("10") != std::string::npos);

    TreeSequence<std::string>* ts = new TreeSequence<std::string>();
    ts->add("abc");
    ts->add("dEf");
    ts->map(0);
    assert(ts->to_string().find("ABC") != std::string::npos);
    assert(ts->to_string().find("DEF") != std::string::npos);

    std::cout << "Succesfull" << std::endl;
    delete t;
    delete ts;
}

void test_where() {
    std::cout << "test_where(): ";
    TreeSequence<int>* t = new TreeSequence<int>();
    for (int i = 1; i <= 10; ++i)
        t->add(i);  

    t->where("1");  

    std::string result = t->to_string();
    assert(result.find("1") == std::string::npos);
    assert(result.find("10") == std::string::npos);
    assert(result.find("2") != std::string::npos);  

    TreeSequence<std::string>* ts = new TreeSequence<std::string>();
    ts->add("abc1");
    ts->add("xyz");
    ts->add("1hello");

    ts->where("1");
    std::string sresult = ts->to_string();
    assert(sresult.find("abc1") == std::string::npos);
    assert(sresult.find("xyz") != std::string::npos);

    std::cout << "Succesfull" << std::endl;
    delete t;
    delete ts;
}

void test_extract_subtree() {
    std::cout << "test_extract_subtree(): ";
    TreeSequence<int>* t = new TreeSequence<int>();
    for (int i = 0; i < 7; ++i)
        t->add(arr_int[i]);  

    TreeSequence<int>* sub = dynamic_cast<TreeSequence<int>*>(t->extract_subtree(3));
    std::string sub_str = sub->to_string();
    assert(sub_str.find("1") != std::string::npos);
    assert(sub_str.find("4") != std::string::npos);
    assert(sub_str.find("5") == std::string::npos); 

    std::cout << "Succesfull" << std::endl;
    delete t;
    delete sub;
}

int main() {
    test_add_contains_to_string();
    test_map();
    test_where();
    test_extract_subtree();
    return 0;
}
