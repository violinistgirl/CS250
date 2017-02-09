#ifndef _SMART_STATIC_ARRAY_HPP
#define _SMART_STATIC_ARRAY_HPP

#include <iostream>
#include <string>
using namespace std;

class SmartDynamicArray
{
    public:
    SmartDynamicArray();
    ~SmartDynamicArray();

    bool Push( const string& newItem );
    bool Insert( int index, const string& newItem );
    bool Extend( const SmartDynamicArray& other );

    bool Pop();
    bool Remove( int index );

    string Get( int index ) const;

    int Size() const;
    int GetMaxSize() const;
    bool IsFull() const;
    bool IsEmpty() const;

    string operator[]( int index );
    SmartDynamicArray& operator=( const SmartDynamicArray& other );
    bool operator==( const SmartDynamicArray& other );
    bool operator!=( const SmartDynamicArray& other );

    private:
    void Free();
    void Resize();
    void Resize( int newSize );

    string* m_data;
    int m_itemCount;
    int m_arraySize;
};

#endif
