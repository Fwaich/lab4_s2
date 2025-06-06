#pragma once
#include "core/Adapter.hpp"
#include "core/Sequence.hpp"
#include "core/exceptions.hpp"

class StringAdapter : public Adapter 
{
private:
    Sequence<std::string>* sequence;

public:

    StringAdapter(Sequence<std::string>* seq){
        sequence = seq;
    }

    ~StringAdapter() override {
        delete sequence;
    }

    StringAdapter* add(std::string str_value) override {
        sequence->add(str_value);
        return this;
    }

    StringAdapter* remove(std::string str_value) override {
        sequence->remove(str_value);
        return this;
    }

    StringAdapter* set_traversal(ITraversal* new_traversal) override {
        auto* typed = dynamic_cast<TreeTraversalAdapter<std::string>*>(new_traversal);
        if (!typed) throw wrong_type();
        sequence->set_traversal(typed->get()->clone());
        return this;
    }

    bool contains(std::string str_value) override {
        return sequence->contains(str_value);
    }

    StringAdapter* map(const double& factor) override {
        sequence->map(0);
        return this;
    }

    StringAdapter* where(std::string value) override {
        sequence->where(value);
        return this;
    }

    StringAdapter* extract_subtree(std::string str_value) override {
        Sequence<std::string>* tree = sequence->extract_subtree(str_value);
        StringAdapter* subtree =  new StringAdapter(tree);
        return this;
    }

    std::string to_string() const {
        return sequence->to_string();
    } 

};