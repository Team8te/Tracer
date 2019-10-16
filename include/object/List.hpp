#pragma once

#include <stdexcept>

namespace lazyant
{
namespace object
{

template <class T>
class TracedList
{
protected:
    struct Element
    {
        T _value;
        Element* next;
    };

public:
    TracedList() = default;

    void push_back(const T& value)
    {
        std::runtime_error("Not implemented");
    }

    bool empty() const
    {
        throw std::runtime_error("Not implemented");
    }

    size_t size() const
    {
        throw std::runtime_error("Not implemented");
    }

private:
    Element* head;
    Element* tail;
};

}
}