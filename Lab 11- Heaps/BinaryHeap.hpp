/*
    Based on BinaryHeap from
    Data Structures and Algorithm Analysis in C++, 3rd Ed,
    Mark Allen Weiss / Pearson
*/

#ifndef _BINARY_HEAP_HPP
#define _BINARY_HEAP_HPP

#include <vector>
#include <exception>
#include <fstream>
using namespace std;

template <typename T>
class BinaryHeap
{
    public:

    /**
    @param items <const vector<T>&> the initial items to put in the heap.

    First, copy the items from the items vector into the m_arrays vector.
    However, we do not put anything at position 0 in m_array, so make sure you're
    storing items in i+1 for m_array, when it is item i from the items vector.
    Then, call the BuildHeap function.
    */
    BinaryHeap( const vector<T> & items )
        : m_array( items.size() + 10 ),
        m_size( items.size() )
    {
		for (int i = 1; i < items.size(); i++) {
			m_array[i] = items[i];
		}

		BuildHeap();
    }

    /**
    @return bool    true if m_array is empty, or false otherwise.
    */
    bool IsEmpty() const
    {
		if (m_size == 0) { 
			return true;
		}
		return false;
		
    }

    /**
    @return T&      the minimum item in the heap (at index 1).
    */
    const T& FindMin() const
    {
		return m_array[1]; 
    }

    /**
    @param newItem <const T&>       The new item to insert

    If m_size is one less than the size of the m_array, then
    tell m_array to resize to double its current size (use the vector's resize() function.)

    Afterward:
    1. Create an integer called *hole*, and assign it to the current value of m_size.

    2. Increment m_size by one

    3. Create a loop. It will continue looping WHILE
        hole > 1 && newItem < m_array[ hole / 2 ]
        And at the end of each cycle, it should EXECUTE
        hole /= 2

        3a. Within the loop, set the element of m_array at position hole
        to the value of the element of m_array at position hole/2.

    4. After the loop, set the element of m_array at position hole equal to the newItem.
    */
    void Insert( const T& newItem )
    {
		if ((m_array.size() - 1) == m_size) {
			m_array.resize(m_array.size());
		}

		int hole = m_size;
		m_size++;

		while (hole > 1 && newItem < m_array[hole / 2]) {
			hole /= 2;
		}

		m_array[hole] = newItem;
    }

    /**
    If the heap is empty, just return.
    Otherwise, set the value of the min item of the heap
    (the element at position 1) to the value of the *last* item
    in the heap (position m_size).
    Then, decrement m_size, and call PercolateDown on index 1.
    */
    void DeleteMin()
    {
		if (IsEmpty()) {
			return;
		}
		else {
			m_array[1] = m_array[m_size];
			m_size--;
			PercolateDown(1);
		}
    }

    void DisplayLinear( ofstream& output ) // done
    {
        for ( unsigned int i = 0; i < m_array.size(); i++ )
        {
            output << i << ":\t" << m_array[i] << endl;
        }
    }

    void RemoveInOrder( ofstream& output ) // done
    {
        int counter = 0;
        while ( !IsEmpty() )
        {
            output << counter++ << ":\t" << FindMin() << endl;
            DeleteMin();
        }
    }

    private:
    unsigned int m_size;
    vector<T> m_array;

    /**
    Iterate through indexes from [m_size/2, 0), decrementing your counter by 1 each time.
    Within the loop, call PercolateDown on the current value of the counter.
    */
    void BuildHeap()
    {
		for (int x = m_size / 2; 0 < x; x--) {
			PercolateDown(x);
		}

    }

    /**
    @param holeIndex <int>  The position in the heap to percolate down.

    1. Create an integer called child
    2. Create a temp T item, and assign it to the value of the element of m_array at the holeIndex.

    3. Loop while holeIndex * 2 <= m_size:
        3a. Set child to holeIndex * 2.

        3b. If the child is not m_size, and the element of m_array at child+1 is less than the element of m_array at child:
            Increment child by 1.

        3c. If the element of m_array at child is less than the temp value:
            Set the element of m_array at position holeIndex to the element of m_array at position child.
            OTHERWISE break.

        3d. At the end of the loop cycle, set holeIndex to the child.

    4. Set the element of m_array at position holeIndex to the temp value.
    */
    void PercolateDown( int holeIndex )
    {
		int child;
		T item = m_array[holeIndex];

		while (holeIndex * 2 <= m_size) {
			child = holeIndex * 2;

			if (child != m_size && (m_array[child + 1] < m_array[child])) {
				child++;
			}

			if (m_array[child] < item) {
				m_array[holeIndex] = m_array[child];
			}
			else {
				break;
			}

			holeIndex = child;
		}

		m_array[holeIndex] = item;
    }
};

#endif
