#include <iostream>
#include <string>
using namespace std;

#include "SortedList.hpp"

bool TestSize()
{
	// Test 1
	SortedList<int> s1;
	if (s1.Size() != 0)
	{
		cout << "Test failed: Size is not 0." << endl;
		return false;
	}

	// Test 2
	SortedList<int> s2;
	s2.SortedPush(3);
	if (s2.Size() != 1)
	{
		cout << "Test failed: Size is not 1." << endl;
		return false;
	}

	// Test 3
	SortedList<int> s3;
	s3.SortedPush(3);
	s3.SortedPush(4);
	s3.SortedPush(5);
	if (s3.Size() != 3)
	{
		cout << "Test failed: Size is not 3." << endl;
		return false;
	}

	cout << "All tests passed" << endl;
	return true;
}

bool TestPush()
{
	// Test 1
	SortedList<int> s1;
	s1.SortedPush(1);
	s1.SortedPush(2);
	s1.SortedPush(4);
	s1.SortedPush(3);
	if (s1[2] != 3)
	{
		cout << "Test failed: 3 not in correct place." << endl;
		return false;
	}

	// Test 2
	SortedList<int> s2;
	s2.SortedPush(3);
	s2.SortedPush(1);
	if (s2[0]!= 1)
	{
		cout << "Test failed: Index 0 is not 1." << endl;
		return false;
	}

	// Test 3
	SortedList<int> s3;
	s3.SortedPush(1);
	s3.SortedPush(4);
	s3.SortedPush(2);
	s3.SortedPush(3);
	if (s3[3] != 4)
	{
		cout << "Test failed: Last index is not 4." << endl;
		return false;
	}

	cout << "All tests passed" << endl;
	return true;
}

bool TestGet()
{
	// Test 1
	SortedList<int> s1;
	s1.SortedPush(1);
	s1.SortedPush(2);
	s1.SortedPush(4);
	s1.SortedPush(3);
	if (s1.GetAt(2) != 3)
	{
		cout << "Test failed: Did not return 3." << endl;
		return false;
	}

	// Test 2
	SortedList<int> s2;
	s2.SortedPush(3);
	s2.SortedPush(1);
	if (s2.GetAt(0) != 1)
	{
		cout << "Test failed: Index 0 did not return 1." << endl;
		return false;
	}

	// Test 3
	SortedList<int> s3;
	s3.SortedPush(1);
	s3.SortedPush(4);
	s3.SortedPush(2);
	s3.SortedPush(3);
	if (s3.GetAt(3) != 4)
	{
		cout << "Test failed: Last index did not return 4." << endl;
		return false;
	}

	cout << "All tests passed" << endl;
	return true;
}

int main()
{
	bool done = false;
	while (!done)
	{
		cout << "1. Test Size" << endl;
		cout << "2. Test Push" << endl;
		cout << "3. Test Get" << endl;
		cout << "4. Quit" << endl;
		cout << ">> ";
		string choice;
		cin >> choice;

		if (choice == "1")
		{
			cout << "TestSize result: " << TestSize() << endl;

		}
		else if (choice == "2") {
			cout << "TestPush result: " << TestPush() << endl;
		}
		else if (choice == "3") {
			cout << "TestGet result: " << TestGet() << endl;
		}
		else if (choice == "4")
		{
			done = true;
		}
	}

	return 0;
}
