/*
You don't need to modify this file!
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "StudentTable.hpp"

void LoadStudents( StudentTable& table );

int main()
{
    cout << "Program start" << endl << endl;

    StudentTable table_linear;
    table_linear.SetCollisionMethod( LINEAR );
    LoadStudents( table_linear );
    table_linear.Output( "out_linear.txt" );

    StudentTable table_quadratic;
    table_quadratic.SetCollisionMethod( QUADRATIC );
    LoadStudents( table_quadratic );
    table_quadratic.Output( "out_quadratic.txt" );

    StudentTable table_double;
    table_double.SetCollisionMethod( DOUBLE );
    LoadStudents( table_double );
    table_double.Output( "out_double.txt" );

    return 0;
}

void LoadStudents( StudentTable& table )
{
    int key;
    string value;

    ifstream input( "students.csv" );

    // Skip header:
    input >> value >> value;

    while ( input >> key >> value )
    {
        table.Insert( key, value );
    }

    input.close();
}
