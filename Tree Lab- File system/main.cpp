#include <iostream>
#include <string>
using namespace std;

#include "Filesystem.hpp"

int main()
{
    Filesystem fs;
    cout << "Find file1.txt ..." << endl;
    File* find1 = fs.Find( "file-1.txt" );
    cout << "File: " + find1->name
        << ", Parent: " << find1->ptrParent->name
        << ", \n\t Path: " << fs.GetPath( find1 )
        << endl << endl;
	//this said file2.txt as the cout, but file-E.txt in the function call. 
	//Edited cout rather than function call
    cout << "Find file-E.txt ..." << endl;
    File* find2 = fs.Find( "file-E.txt" );
    cout << "File: " + find2->name
        << ", Parent: " << find2->ptrParent->name
        << ", \n\t Path: " << fs.GetPath( find2 )
        << endl << endl;

    cout << "Get file ROOT / folder-0 / folder-D / file-D.txt ..." << endl;
    File* getFile1 = fs.GetFile( { "ROOT", "folder-0", "folder-D" }, "file-D.txt" );

    if ( getFile1 == nullptr )
    {
        cout << "It's null, Jim." << endl;
    }
    else
    {
        cout << getFile1->name << endl;
    }

	return 0;
}
