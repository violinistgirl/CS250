#ifndef STACK_HPP
#define STACK_HPP

#include "DoublyLinkedList.hpp"

template <typename T> 
class Stack : public DoublyLinkedList<T>
{
    public:
    Stack()
        : DoublyLinkedList<T>()
    {
    }

     ~Stack()
    {
    }

    void Push( T data )
    {
		DoublyLinkedList<T>::PushBack(data);
    }

    void Pop()
    {
		DoublyLinkedList<T>::PopBack();
    }

    T Top()
    {
		return DoublyLinkedList<T>::GetBack();
    }

	int GetSize() {
		return DoublyLinkedList<T>::GetSize();
	}
};

#endif
