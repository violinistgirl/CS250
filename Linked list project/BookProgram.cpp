/* Don't modify this file */

#include "BookProgram.hpp"

#include "CPP-Utilities-master/Menu.hpp"
#include "CPP-Utilities-master/Strings.hpp"

#include <iostream>
#include <fstream>
using namespace std;

BookProgram::BookProgram()
{
	LoadBook("fairytales.txt");
}

BookProgram::~BookProgram()
{
}

void BookProgram::Run()
{
	bool done = false;
	int currentPage = 0;
	int pageCount = m_pages.Size();
	int choice;
	while (!done)
	{
		dal::Menu::ClearScreen();
		dal::Menu::Header(m_filename + " page " + dal::Strings::ToString(currentPage) + " of " + dal::Strings::ToString(pageCount));
		m_pages[currentPage].Display();

		dal::Menu::DrawHorizontalBar(80);

		choice = dal::Menu::ShowIntMenuWithPrompt({ "PREV", "NEXT" }, false);

		if (choice == 1 && currentPage > 0)
		{
			// Prev
			currentPage--;
		}
		else if (choice == 2 && currentPage < m_pages.Size() - 1 )
		{
			// Next
			currentPage++;
		}
	}
}

void BookProgram::LoadBook(const string& filename)
{
	m_filename = filename;
	ifstream input(filename.c_str());

	Page tempPage;

	string line;
	while (getline(input, line))
	{
		tempPage.AddLine(line);

		if (tempPage.IsFull())
		{
			// Push onto vector
			m_pages.Push(tempPage);
			tempPage.Clear();
		}
	}

	// Put last page in book
	m_pages.Push(tempPage);

	input.close();
}

void BookProgram::SaveBook()
{
}
