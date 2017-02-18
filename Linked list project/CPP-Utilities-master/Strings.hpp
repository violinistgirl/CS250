#ifndef _STRINGS
#define _STRINGS

#include <string>
using namespace std;

namespace dal
{

class Strings
{
    public:
    static string ToString( int num );
    static string ToString( float num );
    static int StringToInt( const string& str );
    static string ToUpper( const string& val );
    static string ToLower( const string& val );
    static string ColumnText( int colWidth, const string& text );
};

}

#endif
