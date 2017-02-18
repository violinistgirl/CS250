#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node
{
    Node()
    {
        ptrNext = nullptr;
        ptrPrev = nullptr;
    }

    Node<T>* ptrNext;
    Node<T>* ptrPrev;

    T data;
};

template <typename T>
class LinkedList
{
    public:
    LinkedList() // done
    {
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount = 0;
    }

    ~LinkedList() // done
    {
        Free();
    }

    void Push( const T& newItem )
    {
		if (m_ptrFirst == nullptr && m_ptrLast == nullptr) {
			m_ptrFirst = new Node<T>;
			m_ptrFirst -> data = newItem;
			m_ptrLast = m_ptrFirst;
			m_itemCount++;
		}
		else {
			Node<T>* ptrNew = new Node<T>;
			ptrNew -> data = newItem;
			ptrNew -> ptrPrev = m_ptrLast;
			m_ptrLast -> ptrNext = ptrNew;
			m_ptrLast = ptrNew;
			m_itemCount++;
		}
    }

    bool Insert( int index, const T& newItem )
    {
		if (index < 0 || index > m_itemCount) {
			return false;
		}
		else if (index == m_itemCount || IsEmpty()) {
			Push(newItem);
			return true;
		}
		else {
			Node<T>* ptrCurrent = m_ptrFirst;
			for (int i = 0; i < index; i++) {
				ptrCurrent = ptrCurrent->ptrNext;
			}
			Node<T>* ptrInsert = new Node<T>;
			ptrInsert->data = newItem;

			if (index == 0) {
				m_ptrFirst = ptrInsert;
			}
			else {				
				ptrCurrent->ptrPrev->ptrNext = ptrInsert;
				ptrInsert->ptrPrev = ptrCurrent->ptrPrev;
			}

			ptrCurrent->ptrPrev = ptrInsert;
			ptrInsert->ptrNext = ptrCurrent;

			m_itemCount++;
			
			return true;
		}
    }

    void Extend( const LinkedList& other )
    {
		Node<T>* ptrCurrent = other.m_ptrFirst;
		for (int i = 0; i < other.Size(); i++) {
			Push(ptrCurrent->data);
			ptrCurrent = ptrCurrent->ptrNext;		
		}
    }

    bool Pop()
    {
		if (m_ptrFirst == nullptr || m_ptrLast == nullptr) {
			return false;
		}
		else if (m_itemCount == 1) {
			delete m_ptrFirst;
			m_ptrFirst = nullptr, m_ptrLast = nullptr;
			m_itemCount--;
			return true;
		}
		else {
			Node<T>* penult = m_ptrLast->ptrPrev;
			delete m_ptrLast;
			m_ptrLast = penult;
			m_ptrLast->ptrNext = nullptr;
			m_itemCount--;
			return true;
		}
    }

    bool Remove( int index )
    {
		if (index < 0 || index >= m_itemCount || IsEmpty()) {
			return false;
		}
		else if (index == (m_itemCount - 1)) {
			Pop();
		}
		else {
			Node<T>* ptrCurrent = m_ptrFirst;
			for (int i = 0; i < index; i++) {
				ptrCurrent = ptrCurrent->ptrNext;
			}
			if (index == 0) {
				ptrCurrent->ptrNext->ptrPrev = nullptr;
				m_ptrFirst = ptrCurrent->ptrNext;
			}
			else {
				ptrCurrent->ptrPrev->ptrNext = ptrCurrent->ptrNext;
				ptrCurrent->ptrNext->ptrPrev = ptrCurrent->ptrPrev;
			}
			delete ptrCurrent;
			m_itemCount--;
			return true;
		}
    }

    T Get( int index ) const
    {
		if (index < 0 || index >= m_itemCount)
		{
			return T();
		}
		else {
			Node<T>* ptrNew = m_ptrFirst;
			for (int i = 0; i < index; i++) {
				ptrNew = ptrNew->ptrNext;
			}
			return ptrNew->data;
		}
    }

    int Size() const // done
    {
        return m_itemCount;
    }

    bool IsEmpty() const // done
    {
        return ( m_ptrFirst == nullptr );
    }

    T operator[]( int index ) // done
    {
        return Get( index );
    }

    LinkedList& operator=( const LinkedList& other )
    {
		Free();

		Node<T>* ptrCurrent = other.m_ptrFirst;
		for (int i = 0; i < other.Size(); i++) {
			Push(ptrCurrent->data);
			ptrCurrent = ptrCurrent->ptrNext;
		}
        return (*this); // temp
    }

    bool operator==( const LinkedList& other )
    {
		if (Size() != other.Size()) {
			return false;
		}
		else {
			Node<T>* ptrCurrent = m_ptrFirst;
			Node<T>* ptrCurrent2 = other.m_ptrFirst;
			for (int i = 0; i < Size(); i++) {
				if (ptrCurrent->data != ptrCurrent2->data) {
					return false;
				}
				ptrCurrent = ptrCurrent->ptrNext;
				ptrCurrent2 = ptrCurrent2->ptrNext;
			}
			return true;
		}
    }

    bool operator!=( const LinkedList& other )
    {
        return !( (*this) == other );
    }

    private:
    void Free() // done
    {
        while ( !IsEmpty() )
        {
            Pop();
        }
    }

    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;
    int m_itemCount;
};

#endif
