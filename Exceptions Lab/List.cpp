#include "List.hpp"

List::List()
{
	m_itemCount = 0;
	m_arraySize = 3;
}

void List::Insert(string newItem, int position)
{
	if (position < 0 || position >= m_arraySize) {
		throw out_of_range("Position out of range!");
	}
	m_data[position] = newItem;
}

void List::Delete(int position)
{
	if (position < 0 || position >= m_arraySize) {
		throw out_of_range("Position out of range!");
	}
	m_data[position] = "";
}

string List::GetItem(int position)
{
	if (position < 0 || position >= m_arraySize) {
		throw out_of_range("Position out of range!");
	}
	return m_data[position];
}