#include "SmartDynamicArray.hpp"

#include "cuTEST/Menu.hpp"

SmartDynamicArray::SmartDynamicArray()
{
	m_itemCount = 0;
	m_arraySize = 0;
	m_data = nullptr;
}

SmartDynamicArray::~SmartDynamicArray()
{
	Free();
}

bool SmartDynamicArray::Push( const string& newItem )
{
	if (IsFull()) {
		Resize();
	}
	m_data[m_itemCount] = newItem;
	m_itemCount++;
	return true;
}


bool SmartDynamicArray::Insert( int index, const string& newItem )
{
	if (IsFull()) {
		Resize();
	}
	if (index < 0 || index >= m_arraySize ) {
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


bool SmartDynamicArray::Extend( const SmartDynamicArray& other )
{
	int totalLength = Size() + other.Size();
	int counter = 0;

	Resize(totalLength);

	if (totalLength == m_arraySize) {
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


bool SmartDynamicArray::Pop()
{
	if (IsEmpty()) {
		return false;
	}
	else {
		m_itemCount--;
		return true;
	}
}


bool SmartDynamicArray::Remove( int index )
{
	if (index < 0 || IsEmpty() || index >= GetMaxSize()		 || index >= Size()) {
		return false;
	}
	else {
		if (index != Size() - 1) {
			for (int i = index; i < Size() - 1; i++) {
				m_data[i] = m_data[i + 1];
			}
		}
		m_itemCount--;
		return true;
	}
}


string SmartDynamicArray::Get( int index ) const
{
	if (index < 0 || index >= Size()) {
		return "";
	}
	else {
		return m_data[index];
	}
}


int SmartDynamicArray::Size() const
{
	return m_itemCount;
}

int SmartDynamicArray::GetMaxSize() const
{
	return m_arraySize;
}

bool SmartDynamicArray::IsFull() const
{
	if (m_itemCount == m_arraySize) {
		return true;
	}
	else {
		return false;
	}
}

bool SmartDynamicArray::IsEmpty() const
{
	if (m_itemCount == 0) {
		return true;
	}
	else {
		return false;
	}
}

string SmartDynamicArray::operator[]( int index )
{
	return Get(index);
}

SmartDynamicArray& SmartDynamicArray::operator=( const SmartDynamicArray& other )
{
	Free();
	Resize(other.Size());

	for (int i = 0; i < other.Size(); i++) {
		m_data[i] = other.m_data[i];
	}
	m_itemCount = other.m_itemCount;
	return *this;
}

bool SmartDynamicArray::operator==( const SmartDynamicArray& other )
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


bool SmartDynamicArray::operator!=( const SmartDynamicArray& other )
{
	return !(*this == other);
}

void SmartDynamicArray::Free()
{
	if (m_data != nullptr) {
		delete [] m_data;
		m_data = nullptr;
	}
}

void SmartDynamicArray::Resize()
{
	Resize(m_arraySize + 10);
}


void SmartDynamicArray::Resize( int newSize )
{
	string* newArray = new string[newSize];

	for (int i = 0; i < m_itemCount; i++) {
		newArray[i] = m_data[i];
	}

	delete [] m_data;

	m_data = newArray;

	m_arraySize = newSize;
}




