/* Don't modify this file */

#ifndef BOOK_PROGRAM_HPP
#define BOOK_PROGRAM_HPP

#include <vector>
using namespace std;

#include "Page.hpp"
#include "LinkedList.hpp"

class BookProgram
{
public:
	BookProgram();
	~BookProgram();

	void Run();

private:
	void LoadBook( const string& filename );
	void SaveBook();

	LinkedList<Page> m_pages;
	string m_filename;
};

#endif
