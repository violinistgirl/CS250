#include "SmartStaticArray.hpp"

#include "cuTEST/Menu.hpp"

SmartStaticArray::SmartStaticArray()
{
	m_itemCount = 0;
}

bool SmartStaticArray::Push( const string& newItem )
{
	if (!IsFull()) {
		m_data[m_itemCount] = newItem;
		m_itemCount++;
		return true;
	}
	else {
		return false;
	}
}


bool SmartStaticArray::Insert( int index, const string& newItem )
{
	if (index < 0 || index >= MAX_SIZE || index > Size() + 1 ) {
		return false; 
	} 
	else {
		for (int i = Size(); i > index; i--) {
			m_data[i] = m_data[i - 1];
		}
		m_data[index] = newItem;
		m_itemCount++;
		return true;
	}
	
}


bool SmartStaticArray::Extend( const SmartStaticArray& other )
{
	int totalLength = Size() + other.Size();
	int counter = 0;
	if ( totalLength <= MAX_SIZE) {
		for (int i = Size(); i < totalLength && counter < other.Size(); i++) {
			m_data[i] = other.m_data[counter];
			counter++;
			m_itemCount++;
		}
		return true;
	}
	else {
		return false;
	}
}


bool SmartStaticArray::Pop()
{
	if (IsEmpty()) {
		return false;
	}
	else {
		m_itemCount--;
		return true;
	}
}


bool SmartStaticArray::Remove( int index )
{
	if (index < 0 || IsEmpty() || index >= MAX_SIZE || index >=Size()) {
		return false;
	}
	else {
		if (index != Size() - 1) {
			for (int i = index; i < Size()-1; i++) {
				m_data[i] = m_data[i + 1];
			}
		}
		m_itemCount--;
		return true;
	}
}


string SmartStaticArray::Get( int index ) const
{
	if (index < 0 || index >= Size()) {
		return "";
	}
	else {
		return m_data[index];
	}
}


int SmartStaticArray::Size() const
{
	return m_itemCount;
}


bool SmartStaticArray::IsFull() const
{
	if (Size() == MAX_SIZE) {
		return true;
	}
	else { 
		return false; 
	}
	
}

bool SmartStaticArray::IsEmpty() const
{
	if (m_itemCount == 0) {
		return true;
	}
	else {
		return false;
	}
}


string SmartStaticArray::operator[]( int index )
{
	return Get(index);
}


SmartStaticArray& SmartStaticArray::operator=( const SmartStaticArray& other )
{
	for (int i = 0; i < other.Size(); i++) {
		m_data[i] = other.m_data[i];
	}
	m_itemCount = other.m_itemCount;
    return *this; 
}

bool SmartStaticArray::operator==( const SmartStaticArray& other )
{
	if (Size() != other.Size()) {
		return false;
	}

	for (int i = 0; i < Size(); i++) {
		if (m_data[i] != other.m_data[i]) {
			return false;
		}
	}
	return true;
}


bool SmartStaticArray::operator!=( const SmartStaticArray& other )
{
	return !( *this == other );
}
