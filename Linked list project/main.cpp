/* Don't modify this file */

#include <iostream>
#include <string>
using namespace std;

#include "BookProgram.hpp"
#include "Tester.hpp"

int main()
{
    bool done = false;
    while ( !done )
    {
        cout << "1. Run program" << endl;
        cout << "2. Run tests" << endl;
        cout << "3. Quit" << endl;
        cout << ">> ";
        string choice;
        cin >> choice;

        if ( choice == "1" )
        {
            BookProgram program;
            program.Run();
        }
        else if ( choice == "2" )
        {
            Tester tester;
            tester.Start();
        }
        else if ( choice == "3" )
        {
            done = true;
        }
    }

    return 0;
}
