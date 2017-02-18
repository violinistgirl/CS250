/* Don't modify this file */

#include "System.hpp"

namespace dal
{

void System::CreateDirectory( const string& directory, bool relative )
{
    if ( relative )
    {
        CreateRelativeDirectory( directory );
    }
}

void System::CreateRelativeDirectory( const string& directory )
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        string cmd = "mkdir " + directory;
        system( cmd.c_str() );
    #else
        string cmd = "mkdir " + directory;
        system( cmd.c_str() );
    #endif
}

}
