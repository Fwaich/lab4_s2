#pragma once
#include "core/Adapter.hpp"
#include "core/Sequence.hpp"
#include "core/exceptions.hpp"

class DoubleAdapter : public Adapter 
{
private:
    Sequence<double>* sequence;

    double from_string(std::string str) {
        try {
            size_t pos;
            double val = std::stod(str, &pos);
    
            if (pos != str.length()) {
                throw wrong_type();
            }
    
            return val;
    
        } catch (const std::exception&) {
            throw wrong_type();
        }
    }

public:

    DoubleAdapter(Sequence<double>* seq){
        sequence = seq;
    }

    ~DoubleAdapter() override {
        delete sequence;
    }

    DoubleAdapter* add(std::string str_value) override {
        sequence->add(from_string(str_value));
        return this;
    }

    DoubleAdapter* remove(std::string str_value) override {
        sequence->remove(from_string(str_value));
        return this;
    }

    DoubleAdapter* set_traversal(ITraversal* new_traversal) override {
        auto* typed = dynamic_cast<TreeTraversalAdapter<double>*>(new_traversal);
        if (!typed) throw wrong_type();
        sequence->set_traversal(typed->get()->clone());
        return this;
    }

    bool contains(std::string str_value) override {
        return sequence->contains(from_string(str_value));
    }

    DoubleAdapter* map(const double& factor) override {
        sequence->map(factor);
        return this;
    }

    DoubleAdapter* where(std::string value) override {
        sequence->where(value);
        return this;
    }

    DoubleAdapter* extract_subtree(std::string str_value) override {
        Sequence<double>* tree = sequence->extract_subtree(from_string(str_value));
        DoubleAdapter* subtree =  new DoubleAdapter(tree);
        return this;
    }

    std::string to_string() const {
        return sequence->to_string();
    } 

};