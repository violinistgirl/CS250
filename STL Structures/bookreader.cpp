#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "Page.hpp"

void LoadPages(vector<Page>& pages, const string& filename)
{
	ifstream input(filename.c_str());
	string line;
	string pageText = "";
	int lineCount = 0;
	int pageCount = 0;

	while (getline(input, line))
	{
		pageText = pageText + "\n" + line;

		lineCount++;
		if (lineCount == 27)
		{
			// Add page to book now
			Page newPage;
			newPage.text = pageText;
			pages.push_back(newPage);

			pageCount++;

			// Reset the page text
			pageText = "";

			// Reset the line count
			lineCount = 0;
		}

	}

	input.close();
}

void ReadBook(vector<Page>& pages)
{
	int currentPage = 0;
	int totalPages = pages.size();

	bool done = false;

	while (!done)
	{
		pages[currentPage].Display();
		cout << "--- PAGE " << currentPage + 1 << " OF " << totalPages << "---------------------------------" << endl;
		cout << "(N)ext Page, (P)revious Page, (Q)uit" << endl;
		cout << ">> ";
		string choice;
		cin >> choice;

		if (choice == "Q" || choice == "q")
		{
			done = true;
		}
		else if (choice == "N" || choice == "n")
		{
			if (currentPage + 1 < totalPages)
			{
				currentPage++;
			}
		}
		else if (choice == "P" || choice == "p")
		{
			if (currentPage - 1 >= 0)
			{
				currentPage--;
			}
		}
	}
}

int main()
{
	vector<Page> pages;

	string fileName = "Aesop.txt";

	LoadPages(pages, fileName);
	ReadBook(pages);

	return 0;
}
