#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include <stdexcept>
using namespace std;

template <typename T>
class Node
{
    public:
    Node()
    {
        m_ptrNext = nullptr;
        m_ptrPrev = nullptr;
    }

    T m_data;

    Node<T>* m_ptrNext;
    Node<T>* m_ptrPrev;
};

template <typename T>
class DoublyLinkedList
{
    public:
    DoublyLinkedList()
    {
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount = 0;
    }

    virtual ~DoublyLinkedList()
    {
        while ( m_ptrFirst != nullptr )
        {
            PopBack();
        }
    }

    /*
    Pure virtual functions:
    Interfaces for children, to be
    implemented by child classes.
    */
    virtual void Push( T data ) = 0;
    virtual void Pop() = 0;
    virtual T Take() = 0;

    /*
    Inherited public functions
    */

    void Display()
    {
        Node<T>* ptrCurrent = m_ptrFirst;
        while ( ptrCurrent != nullptr )
        {
            cout << ptrCurrent->m_data;

            if ( ptrCurrent == m_ptrFirst )
            {
                cout << "\t FIRST";
            }
            if ( ptrCurrent == m_ptrLast )
            {
                cout << "\t LAST";
            }

            cout << endl;

            ptrCurrent = ptrCurrent->m_ptrNext;
        }
    }

    int GetSize()
    {
        return m_itemCount;
    }

    protected:
    int m_itemCount;
    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;

    /*
    Behind-the-scenes inner-workings
    */

    void PushFront( T data )
    {
        Node<T>* newNode = new Node<T>();
        newNode->m_data = data;

        if ( m_ptrFirst = nullptr )
        {
            // Empty list
            m_ptrFirst = newNode;
            m_ptrLast = newNode;
        }
        else
        {
            // Not empty, new node is the new first
            newNode->m_ptrNext = m_ptrFirst;
            m_ptrFirst->m_ptrPrev = newNode;

            // Update pointer
            m_ptrFirst = newNode;
        }

        m_itemCount++;
    }

    void PushBack( T data )
    {
        Node<T>* newNode = new Node<T>();
        newNode->m_data = data;

        if ( m_ptrFirst == nullptr )
        {
            // Empty list
            m_ptrFirst = newNode;
            m_ptrLast = newNode;
        }
        else
        {
            // Not empty, new node is the new last
            m_ptrLast->m_ptrNext = newNode;
            newNode->m_ptrPrev = m_ptrLast;

            // Update pointer
            m_ptrLast = newNode;
        }

        m_itemCount++;
    }

    void Insert( T data, int index )
    {
        if ( index > m_itemCount || index < 0 )
        {
            throw out_of_range( "Invalid index!" );
        }

        Node<T>* newNode = new Node<T>();
        newNode->m_data = data;

        if ( m_ptrFirst = nullptr )
        {
            // Empty list
            m_ptrFirst = newNode;
            m_ptrLast = newNode;
        }
        else
        {
            // Traverse list to find position
            int counter = 0;
            Node<T>* ptrCurrent = m_ptrFirst;

            while ( counter != index )
            {
                counter++;
            }

            // Add item in list
            newNode->m_ptrPrev = ptrCurrent->m_ptrPrev;
            newNode->m_ptrNext = ptrCurrent;

            ptrCurrent->m_ptrPrev->m_ptrNext = newNode;
            ptrCurrent->m_ptrPrev = newNode;
        }

        m_itemCount++;
    }


    void PopFront()
    {
        if ( m_ptrFirst == nullptr )
        {
            return;
        }

        if ( m_ptrFirst == m_ptrLast )
        {
            delete m_ptrLast;
            m_ptrFirst = nullptr;
            m_ptrLast = nullptr;
            m_itemCount--;
            return;
        }

        // Keep track of 2nd item
        Node<T>* ptrSecond = m_ptrFirst->m_ptrNext;

        // Update the 2nd element's prev pointer
        ptrSecond->m_ptrPrev = nullptr;

        // Clear out the data at m_ptrFirst
        delete m_ptrFirst;

        // Update first pointer
        m_ptrFirst = ptrSecond;

        m_itemCount--;
    }

    void PopBack()
    {
        if ( m_ptrLast == nullptr )
        {
            return;
        }

        if ( m_ptrFirst == m_ptrLast )
        {
            delete m_ptrLast;
            m_ptrFirst = nullptr;
            m_ptrLast = nullptr;
            m_itemCount--;
            return;
        }

        // Keep track of 2nd-to-last item
        Node<T>* ptrPenultimate = m_ptrLast->m_ptrPrev;

        // Update 2nd-to-last item's next ptr
        ptrPenultimate->m_ptrNext = nullptr;

        // Clear out data at last element
        delete m_ptrLast;

        // Update last pointer
        m_ptrLast = ptrPenultimate;

        m_itemCount--;
    }

    void Remove( int index )
    {
        if ( index > m_itemCount || index < 0 )
        {
            throw out_of_range( "Invalid index!" );
        }

        // Locate item
        Node<T>* ptrCurrent = m_ptrFirst;

        int counter = 0;
        while ( counter != index )
        {
            counter++;
        }

        Node<T>* ptrPrev = ptrCurrent->m_ptrPrev;
        Node<T>* ptrNext = ptrCurrent->m_ptrNext;

        // Update previous item's pointer
        ptrPrev->m_ptrNext = ptrNext;

        // Update next item's pointer
        ptrNext->m_ptrPrev = ptrPrev;

        // Free this item
        delete ptrCurrent;

        m_itemCount--;
    }

    T& GetFront()
    {
        if ( m_ptrFirst == nullptr )
        {
            throw out_of_range( "First pointer is nullptr" );
        }

        return m_ptrFirst->m_data;
    }

    T& GetBack()
    {
        if ( m_ptrLast == nullptr )
        {
            throw out_of_range( "Last pointer is nullptr" );
        }

        return m_ptrLast->m_data;
    }

    T& Get( int index )
    {
        if ( index > m_itemCount || index < 0 )
        {
            throw out_of_range( "Invalid index!" );
        }

        // Locate item
        Node<T>* ptrCurrent = m_ptrFirst;

        int counter = 0;
        while ( counter != index )
        {
            ptrCurrent = ptrCurrent->m_ptrNext;
            counter++;
        }

        return ptrCurrent->m_data;
    }
};

template <typename T>
using List = DoublyLinkedList<T>;

#endif
