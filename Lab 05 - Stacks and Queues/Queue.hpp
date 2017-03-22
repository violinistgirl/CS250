#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../DoublyLinkedList.hpp"

template <typename T>
class Queue : public DoublyLinkedList<T>
{
    public:
    Queue()
        : DoublyLinkedList<T>()
    {
    }

    virtual ~Queue()
    {
    }

    virtual void Push( T data )
    {
		DoublyLinkedList<T>::PushBack(data);
    }

    virtual void Pop()
    {
		DoublyLinkedList<T>::PopFront();
    }

    virtual T Take()
    {
		return DoublyLinkedList<T>::GetFront();
    }
};

#endif
