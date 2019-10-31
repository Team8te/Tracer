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

    NodeList(const std::shared_ptr<NodeList>& otherNext,
             const std::shared_ptr<NodeList>& otherPrev)
        : next(otherNext)
        , priv(otherPrev)
    {}

    virtual ~NodeList()
    {
        priv->next = std::move(next);
        next->priv = std::move(priv);
    }

    std::shared_ptr<NodeList> next;
    std::shared_ptr<NodeList> priv;
};

template<class T>
struct Node : public NodeList
{
    T nodeValue;

    Node(const T& value,
         std::shared_ptr<NodeList> node_ptr)
         : NodeList(node_ptr->next, node_ptr->priv)
         , nodeValue(value)
    {}
};

template<class T>
class ListIteratorBase
{
public:
    ListIteratorBase() = default;

    ListIteratorBase(const std::shared_ptr<NodeList>& node_ptr)
        : _node_ptr(node_ptr)
    {}

    void increment()
    {
        _node_ptr = _node_ptr->next;
    }

    void decrement()
    {
        _node_ptr = _node_ptr->priv;
    }

    T& operator*()
    {
        return std::static_pointer_cast<Node<T>>(_node_ptr)->nodeValue;
    }

protected:
    std::shared_ptr<NodeList> _node_ptr;
};

template <class T>
class TracedList
{
public:
    class Iterator : public ListIteratorBase<T>
    {
    friend class TracedList;

    public:
        Iterator() = default;

        Iterator(const std::shared_ptr<Node<T>>& node_ptr)
            : ListIteratorBase<T>(node_ptr)
        {}

        ~Iterator() = default;

        Iterator next()
        {
            return Iterator(this->_node_ptr->next);
        }

        Iterator &operator++()
        {
            this->increment();
            return *this;
        }

        Iterator &operator--()
        {
            this->decrement();
            return *this;
        }
    };

    using Pointer = T*;
    using Reference = T&;
    using ConstIterator = const Iterator;

    TracedList() = default;

    void push_from(const T& value)
    {
        return insert(begin(), value);
    }

    void push_back(const T& value)
    {
        insert(end(), value);
    }

    Iterator insert(ConstIterator& position, const T& value)
    {
        auto element = std::make_shared<Node<T>>(value, position._node_ptr);
        Iterator itr(std::move(element));
        ++_size;

        return itr;
    }

    bool empty() const
    {
        return _size != 0;
    }

    size_t size() const
    {
        return _size;
    }

    Iterator begin() const
    {
        return _node.next();
    }

    Iterator end() const
    {
        return _node;
    }

private:
    Iterator _node;
    size_t _size;
};

}
}