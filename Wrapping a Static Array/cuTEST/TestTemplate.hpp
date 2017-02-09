#ifdef STANDALONE

#ifndef _TEST_TEMPLATE_HPP
#define _TEST_TEMPLATE_HPP

#include "TesterBase.hpp"

class TestTemplate : public TesterBase
{
public:
TestTemplate();

private:
int Test1();
};


TestTemplate::TestTemplate()
{
    AddTest( TestListItem( "Test1", bind( &TestTemplate::Test1, this ) ) );
}

int TestTemplate::Test1()
{
    cout << "Test 1 \t";
    int a = 2, b = 2;
    if ( a + b == 4 )
    {
        cout << "Pass" << endl;
        return 1;
    }
    cout << "Fail" << endl;
    return 0;
}

#endif

#endif
