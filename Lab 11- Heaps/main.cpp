#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

#include "BinaryHeap.hpp"

void ReadTextFile( const string& filename, vector<string>& entries, vector<string>& uniqueEntries, map<string, int>& entriesAndCounts )
{
    string buffer;

    ifstream input( filename );
    while ( input >> buffer )
    {
        entries.push_back( buffer );

        if ( entriesAndCounts.find( buffer ) == entriesAndCounts.end() )
        {
            uniqueEntries.push_back( buffer );
            entriesAndCounts[ buffer ] = 1;
        }
        else
        {
            entriesAndCounts[ buffer ]++;
        }
    }
    input.close();
}

int main()
{
    map<string, int> entriesAndCounts;
    vector<string> uniqueEntries;
    vector<string> entries;
    ReadTextFile( "aesop.txt", entries, uniqueEntries, entriesAndCounts );

    cout << "Total words:        " << entries.size() << endl
         << "Total unique words: " << uniqueEntries.size() << endl;

    ofstream output( "word_analysis.txt" );

    BinaryHeap<string> heap( uniqueEntries );

    output << "DISPLAY LINEAR LIST:" << endl;
    heap.DisplayLinear( output );

    output << endl << endl << "REMOVE IN ORDER: " << endl;
    heap.RemoveInOrder( output );

    output.close();

    return 0;
}
