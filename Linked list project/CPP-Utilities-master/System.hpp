#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>
using namespace std;

namespace dal
{

class System
{
    public:
    static void CreateDirectory( const string& directory, bool relative = true );

    private:
    static void CreateRelativeDirectory( const string& directory );
};

}

#endif
