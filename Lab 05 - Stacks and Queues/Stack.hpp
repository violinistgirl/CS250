#ifndef STACK_HPP
#define STACK_HPP

#include "../DoublyLinkedList.hpp"

template <typename T>
class Stack : public DoublyLinkedList<T>
{
    public:
    Stack()
        : DoublyLinkedList<T>()
    {
    }

    virtual ~Stack()
    {
    }

    virtual void Push( T data )
    {
		DoublyLinkedList<T>::PushBack(data);
    }

    virtual void Pop()
    {
		DoublyLinkedList<T>::PopBack();
    }

    virtual T Take()
    {
		return DoublyLinkedList<T>::GetBack();
    }
};

#endif
