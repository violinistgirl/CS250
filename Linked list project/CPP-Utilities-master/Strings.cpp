/* Don't modify this file */

#include "Strings.hpp"

#include <cstdlib>
#include <sstream>
#include <iostream>
using namespace std;

namespace dal
{

string Strings::ToString( int num )
{
    stringstream ss;
    ss << num;
    return ss.str();
}

string Strings::ToString( float num )
{
    stringstream ss;
    ss << num;
    return ss.str();
}

int Strings::StringToInt( const string& str )
{
    istringstream ss( str );
    int val;
    ss >> val;
    return val;
}

string Strings::ToUpper( const string& val )
{
    string upper = "";
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        upper += toupper( val[i] );
    }
    return upper;
}

string Strings::ToLower( const string& val )
{
    string upper = "";
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        upper += tolower( val[i] );
    }
    return upper;
}

string Strings::ColumnText( int colWidth, const string& text )
{
    string adjusted = text;
    for ( int i = 0; i < colWidth - text.size(); i++ )
    {
        adjusted += " ";
    }
    return adjusted;
}

}
