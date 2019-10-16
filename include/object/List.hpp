#pragma once

#include <stdexcept>
#include <memory>

namespace lazyant
{
namespace object
{

struct NodeList
{
    NodeList() = default;

    virtual ~NodeList()
    {
        priv->next = std::move(next);
        next->priv = std::move(priv);
    }

    std::unique_ptr<NodeList> next;
    std::unique_ptr<NodeList> priv;
};

template<class T>
struct Node
{
    T value;
    std::unique_ptr<Node<T>> next;
    std::unique_ptr<Node<T>> priv;
};

template<class T>
class ListIteratorBase
{
public:
    ListIteratorBase() = default;

    ListIteratorBase(std::uniquer<Node<T>> node_ptr)
        : _node_ptr(std::move(node_ptr))
    {}

    void insrement()
    {
        _node_ptr->next;
    }

private:
    std::unique_ptr<Node<T>> _node_ptr;
};

template <class T>
class TracedList
{
public:
    TracedList() = default;

    void push_back(const T& value)
    {
        insert()
    }

    Iterator<T> insert(Position position, const T& value)
    {
        
    }

    bool empty() const
    {
        return _size != 0;
    }

    size_t size() const
    {
        return _size;
    }

    Iterator<T> begin() const
    {

    }

private:
    Iterator<T> begin;
    Iterator<T> end;
};

}
}