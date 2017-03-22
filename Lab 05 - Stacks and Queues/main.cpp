#include <iostream>
#include <string>
using namespace std;

#include "Queue/Queue.hpp"
#include "Stack/Stack.hpp"

int main()
{
    bool done = false;
    while ( !done )
    {
        List<string>* listObj = nullptr;

        cout << endl << "--------------------------------" << endl;
        cout << "1. Queue or 2. Stack, or anything else to quit." << endl << ">> ";
        int choice;
        cin >> choice;

        // POLYMORPHISM!!
        if ( choice == 1 )
        {
            cout << endl << "Create queue" << endl;
            // Initialize as queue
            listObj = new Queue<string>;
        }
        else if ( choice == 2 )
        {
            cout << endl << "Create stack" << endl;
            // Initialize as stack
            listObj = new Stack<string>;
        }
        else
        {
            break;
        }

        cout << "Add A, B, C, D" << endl;
        listObj->Push( "A" );
        listObj->Push( "B" );
        listObj->Push( "C" );
        listObj->Push( "D" );

        cout << "Size: " << listObj->GetSize() << endl;
        cout << "Take: " << listObj->Take() << endl;

        cout << endl << "Current list:" << endl;
        listObj->Display();

        cout << endl << "Pop 1" << endl;
        listObj->Pop();

        cout << "Size: " << listObj->GetSize() << endl;
        cout << "Take: " << listObj->Take() << endl;

        cout << endl << "Current list:" << endl;
        listObj->Display();

        if ( listObj != nullptr )
        {
            delete listObj; // free up memory
        }
    }

    return 0;
}
