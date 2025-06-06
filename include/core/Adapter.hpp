#pragma once
#include <string>
#include "core/TraversalAdapter.hpp"

class Adapter 
{
public:

    virtual ~Adapter() = default; 

    virtual Adapter* add(std::string str_value) = 0;
    virtual Adapter* remove(std::string str_value) = 0;
    virtual Adapter* set_traversal(ITraversal* new_traversal) = 0;
    
    virtual bool contains(std::string str_value) = 0;
    virtual Adapter* map(const double& factor) = 0;
    virtual Adapter* where(std::string value) = 0;
    virtual Adapter* extract_subtree(std::string str_value) = 0;
    
    virtual std::string to_string() const = 0;


};
