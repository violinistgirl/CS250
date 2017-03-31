#ifndef _SORTED_LIST_HPP
#define _SORTED_LIST_HPP

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
class SortedList
{
public:
	SortedList() // done
	{
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount = 0;
	}

	~SortedList() // done
	{
		Free();
	}

	void Display() {
		cout << "\n";
		if (!IsEmpty()) {
			for (int i = 0; i < m_itemCount; i++) {
				cout << GetAt(i) << " ";
			}
		}
		cout << "\n";
	}

	void SortedPush(const T& newItem)
	{
		Display();
		cout << "\nInserting " << newItem << endl;
		if (m_ptrFirst == nullptr && m_ptrLast == nullptr) {
			m_ptrFirst = new Node<T>;
			m_ptrFirst->data = newItem;
			m_ptrLast = m_ptrFirst;
			m_itemCount++;
		}
		else {
			Node<T>* ptrNew = new Node<T>;
			ptrNew->data = newItem;

			Node<T>* ptrCurrent = m_ptrFirst;
			
			if (ptrCurrent->data > newItem) {
				ptrNew->ptrNext = m_ptrFirst;
				m_ptrFirst->ptrPrev = ptrNew;
				m_ptrFirst = ptrNew;
			}
			else if (m_ptrLast->data < newItem) {
				m_ptrLast->ptrNext = ptrNew;
				ptrNew->ptrPrev = m_ptrLast;
				m_ptrLast = ptrNew;
			}
			else {
				while (ptrCurrent->data <= newItem) {
					ptrCurrent = ptrCurrent->ptrNext;
				}
				ptrCurrent->ptrPrev->ptrNext = ptrNew;
				ptrNew->ptrPrev = ptrCurrent->ptrPrev;
				ptrNew->ptrNext = ptrCurrent;
				ptrCurrent->ptrPrev = ptrNew;
			}
			m_itemCount++;
		}
		Display();
	}

	T GetAt(int index) const
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
		return (m_ptrFirst == nullptr);
	}

	T operator[](int index) // done
	{
		return GetAt(index);
	}

	SortedList& operator=(const SortedList& other)
	{
		Free();

		Node<T>* ptrCurrent = other.m_ptrFirst;
		for (int i = 0; i < other.Size(); i++) {
			Push(ptrCurrent->data);
			ptrCurrent = ptrCurrent->ptrNext;
		}
		return (*this); // temp
	}

	bool operator==(const SortedList& other)
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

	bool operator!=(const SortedList& other)
	{
		return !((*this) == other);
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

private:
	void Free() // done
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	Node<T>* m_ptrFirst;
	Node<T>* m_ptrLast;
	int m_itemCount;
};

#endif