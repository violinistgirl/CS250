#ifndef _PAGE_HPP
#define _PAGE_HPP

#include <iostream>
#include <string>
using namespace std;

struct Page
{
	string text;
	int pageNumber;

	void Display()
	{
		cout << text << endl;
	}
};

#endif