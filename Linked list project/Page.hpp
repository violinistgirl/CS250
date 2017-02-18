/* Don't modify this file */

#ifndef PAGE_HPP
#define PAGE_HPP

#include <string>
#include <iostream>
using namespace std;

const int MAX_LINES_PER_PAGE = 20;

class Page
{
public:
	Page()
	{
		Clear();
	}

	void Clear()
	{
		for (int i = 0; i < MAX_LINES_PER_PAGE; i++)
		{
			lines[i] = "";
		}
		currentLine = 0;
	}

	bool IsFull()
	{
		return (currentLine == MAX_LINES_PER_PAGE);
	}

	bool AddLine(const string& line)
	{
		if (currentLine < MAX_LINES_PER_PAGE)
		{
			lines[currentLine] = line;
			currentLine++;
			return true;
		}
		return false;
	}

	void Display()
	{
		for (int i = 0; i < currentLine; i++)
		{
			cout << lines[i] << endl;
		}
	}

private:
	string lines[MAX_LINES_PER_PAGE];
	int currentLine;
};

#endif
