#pragma once
#include "core/Adapter.hpp"
#include "core/Sequence.hpp"
#include "core/exceptions.hpp"

class IntAdapter : public Adapter 
{
private:
    Sequence<int>* sequence;

    int from_string(std::string str) {
        try {
            size_t pos;
            int val = std::stoi(str, &pos);
    
            if (pos != str.length()) {
                throw wrong_type();
            }
    
            return val;
    
        } catch (const std::exception&) {
            throw wrong_type();
        }
    }

public:

    IntAdapter(Sequence<int>* seq){
        sequence = seq;
    }

    ~IntAdapter() override {
        delete sequence;
    }

    IntAdapter* add(std::string str_value) override {
        sequence->add(from_string(str_value));
        return this;
    }

    IntAdapter* remove(std::string str_value) override {
        sequence->remove(from_string(str_value));
        return this;
    }

    IntAdapter* set_traversal(ITraversal* new_traversal) override {
        auto* typed = dynamic_cast<TreeTraversalAdapter<int>*>(new_traversal);
        if (!typed) throw wrong_type();
        sequence->set_traversal(typed->get()->clone());
        return this;
    }

    bool contains(std::string str_value) override {
        return sequence->contains(from_string(str_value));
    }

    IntAdapter* map(const double& factor) override {
        sequence->map(factor);
        return this;
    }

    IntAdapter* where(std::string value) override {
        sequence->where(value);
        return this;
    }

    IntAdapter* extract_subtree(std::string str_value) override {
        Sequence<int>* tree = sequence->extract_subtree(from_string(str_value));
        IntAdapter* subtree =  new IntAdapter(tree);
        return this;
    }

    std::string to_string() const {
        return sequence->to_string();
    } 

};