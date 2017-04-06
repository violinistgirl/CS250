#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <string>
#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 131;

enum CollisionMethod { LINEAR, QUADRATIC, DOUBLE };

class Student
{
    public:
    int key;
    string value;
};

class StudentTable
{
    public:
    StudentTable();

    void SetCollisionMethod( CollisionMethod cm );
    void Insert( int studentId, const string& name );
    void Output( const string& filename );

    private:
    int HashFunction(int key);

    /* Linear probing */
    // You can use my function prototype or write your own.
    int Linear( int key );

    /* Quadratic probing */
    // You can use my function prototype or write your own.
    int Quadratic( int key, int& addValue );

    /* Double hashing */
    // You can use my function prototype or write your own.
    int Hash2( int key);

    Student m_students[TABLE_SIZE];

    CollisionMethod m_collisionMethod;
};

#endif
