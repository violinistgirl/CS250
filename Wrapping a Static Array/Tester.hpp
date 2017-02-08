#ifndef _TESTER_HPP
#define _TESTER_HPP

#include "SmartStaticArray.hpp"
#include "cuTEST/StringUtil.hpp"
#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Tester : public TesterBase
{
public:
Tester();

private:
int TestPush()
{
    DisplayTestHeader( "TestPush()" );
    int totalTests = 0;
    int totalSuccess = 0;

    vector<string> values = GetTestItems( MAX_SIZE );

    /*
    Test 1
    Fill array with items and make sure they're inserted properly
    */

    // Setup array
    SmartStaticArray arr1;
    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        arr1.Push( values[i] );
    }

    // Validate
    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        string result = arr1.Get( i );

        totalTests++;
        if ( result != values[i] )
        {
            ReportFailure( "TestPush()",
                "Filled an array with items and using Get() to validate. Expected \"" + values[i] + "\" but got \"" + result + "\" instead." );
            break;
        }
        else
        {
            totalSuccess++;
        }
    }

    /*
    Test 2
    Try to push too many items into the array
    */
    SmartStaticArray arr2;
    for ( int i = 0; i < MAX_SIZE + 2; i++ )
    {
        bool result = arr2.Push( "*" );

        totalTests++;
        if ( i < MAX_SIZE && result == false )
        {
            ReportFailure( "TestPush()",
                "Push() returned false while pushing items to a non-full SmartStaticArray." );
            break;
        }
        else if ( i >= MAX_SIZE && result == true )
        {
            ReportFailure( "TestPush()",
                "Push() returned true while pushing items to a full SmartStaticArray." );
            break;
        }
        else
        {
            totalSuccess++;
        }
    }

    DisplayScore( totalSuccess, totalTests );

    return ( totalSuccess == totalTests );
}

int TestInsert()
{
    DisplayTestHeader( "TestInsert()" );
    int totalTests = 0;
    int totalSuccess = 0;

    vector<string> values = GetTestItems( MAX_SIZE );

    /*
    Test 1
    Test insertion like a push: keep inserting at the last available index
    */
	SmartStaticArray arr1;
	for ( int i = 0; i < MAX_SIZE; i++ )
	{
        totalTests++;
        if ( arr1.Insert( arr1.Size(), "A" ) == false )
        {
            ReportFailure( "TestInsert()",
                "Tried to insert an item to position " + StringUtil::ToString( arr1.Size() ) + " but it failed." );
            break;
        }
        else { totalSuccess++; }
	}

    /*
    Test 2
    Test insert at various positions
    */
	SmartStaticArray arr2, solutionArray;
	arr2.Push( "A" );
	arr2.Push( "B" );
	arr2.Push( "C" );
	arr2.Push( "D" );
	solutionArray.Push( "A" );  // 0
	solutionArray.Push( "B" );  // 1
	solutionArray.Push( "Z" );  // 2
	solutionArray.Push( "C" );  // 3
	solutionArray.Push( "X" );  // 4
	solutionArray.Push( "D" );  // 5

	arr2.Insert( 2, "Z" );
	arr2.Insert( 4, "X" );

    totalTests++;
	if ( arr2.Size() != 6 )
	{
        ReportFailure( "TestInsert()",
            "Inserted 2 items into an array of size 4. Didn't return a Size() of 6." );
	}
	else { totalSuccess++; }

    totalTests++;
    if ( ( arr2 == solutionArray ) == false )
    {
        string message = "Inserted values into array. Expected: ";
        for ( int i = 0; i < solutionArray.Size(); i++ )
        {
            if ( i != 0 ) { message += ", "; }
            message += solutionArray.Get( i );
        }

        message += " but got: ";

        for ( int i = 0; i < arr2.Size(); i++ )
        {
            if ( i != 0 ) { message += ", "; }
            message += arr2.Get( i );
        }

        ReportFailure( "TestInsert()",
            message );
    }
	else { totalSuccess++; }

    /*
    Test 3
    Insert at invalid index
    */
	SmartStaticArray arr3;

    totalTests++;
	if ( arr3.Insert( -1, "A" ) != false ) { ReportFailure( "TestInsert()", "Tried to insert value at -1. Didn't return a false." ); }
	else { totalSuccess++; }

    totalTests++;
    if ( arr3.Insert( MAX_SIZE, "A" ) != false ) { ReportFailure( "TestInsert()", "Tried to insert a value at MAX_SIZE. Didn't return a false." ); }
	else { totalSuccess++; }

    /*
    Test 4
    Insert item at non-continguous point.
    */
	SmartStaticArray arr4;
	arr4.Push( "A" );
	arr4.Push( "B" );
	arr4.Push( "C" );

    totalTests++;
	if ( arr4.Insert( 10, "D" ) != false ) { ReportFailure( "TestInsert()", "Tried to insert an item non-contiugously (at position 10 in an array with 3 items.) Should have returned false." ); }
	else { totalSuccess++; }

    totalTests++;
	if ( arr4.Size() == 4 )	{ ReportFailure( "TestInsert()", "After trying to insert item at non-contiguous index of array, Size() reflects add. Invalid inserts shouldn't modify the array." ); }
    else { totalSuccess++; }

    DisplayScore( totalSuccess, totalTests );

    return ( totalSuccess == totalTests );
}

int TestExtend()
{
    DisplayTestHeader( "TestExtend()" );
    int totalTests = 0;
    int totalSuccess = 0;

    vector<string> values = GetTestItems( MAX_SIZE );

    /*
    Test 1
    Normal extend that should work
    */
	SmartStaticArray arr1, arr2, solutionArray;

	arr1.Push( "1" );
	arr1.Push( "3" );
	arr2.Push( "2" );
	arr2.Push( "4" );
	solutionArray.Push( "1" );
	solutionArray.Push( "3" );
	solutionArray.Push( "2" );
	solutionArray.Push( "4" );


    totalTests++;
	if ( arr1.Extend( arr2 ) != true ) { ReportFailure( "TestExtend()", "Extend function returned false, but it should have returned true." ); }
    else { totalSuccess++; }


	string solution = "1, 2, 3, 4, 1, 2, 3, 4";
	string actual = "";

	for ( int i = 0; i < arr2.Size(); i++ )
	{
        if ( i != 0 ) { actual += ", "; }
        actual += arr2.Get( i );
	}

    totalTests++;
	if ( (arr1 == solutionArray ) == false ) { ReportFailure( "TestExtend()", "Tried to extend an array. Resulting solution wasn't correct. Expected: " + solution + ", received: " + actual ); }
	else { totalSuccess++; }

    /*
    Test 2
    Trying to extend in an array that doesn't have the space
    */
	SmartStaticArray arr3, arr4;
	for ( int i = 0; i < MAX_SIZE - 2; i++ )
	{
        arr3.Push( "hi" );
        arr4.Push( "bye" );
	}

    totalTests++;
	if ( arr3.Extend( arr4 ) != false ) { ReportFailure( "TestExtend()", "Tried to extend past the array size. Should have returned false, but returned true." ); }
	else { totalSuccess++; }


    DisplayScore( totalSuccess, totalTests );

    return ( totalSuccess == totalTests );
}

int TestPop()
{
    DisplayTestHeader( "TestPop()" );
    int totalTests = 0;
    int totalSuccess = 0;

    vector<string> values = GetTestItems( MAX_SIZE );

    /*
    Test 1
    Pop empty array
    */
    SmartStaticArray arr1;

    totalTests++;
    if ( arr1.Pop() != false ) { ReportFailure( "TestPop()", "Tried to pop from an empty array. Should have returned false, but returned true." ); }
    else { totalSuccess++; }

    /*
    Test 2
    Fill the array and pop each item off
    */
    SmartStaticArray arr2;
    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        arr2.Push( values[i] );
    }

    totalTests++;
    if ( arr2.Size() != MAX_SIZE ) { ReportFailure( "TestPop()", "Array's size after pushing MAX_SIZE items is not MAX_SIZE." ); }
    else { totalSuccess++; }

    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        totalTests++;
        if ( arr2.Pop() != true )
        {
            ReportFailure( "TestPop()", "A Pop failed while emptying out a full array, even though it shouldn't have." );
            break;
        }
        else { totalSuccess++; }
    }

    totalTests++;
    if ( arr2.IsEmpty() == false ) { ReportFailure( "TestPop()", "Popped all items from an array. IsEmpty is false, but should be true." ); }
    else { totalSuccess++; }


    DisplayScore( totalSuccess, totalTests );

    return ( totalSuccess == totalTests );
}

int TestRemove()
{
    DisplayTestHeader( "TestRemove()" );
    int totalTests = 0;
    int totalSuccess = 0;

    vector<string> values = GetTestItems( MAX_SIZE );

    /*
    Test 1
    Remove at an invalid index
    */
	SmartStaticArray arr1;

    totalTests++;
	if ( arr1.Remove( 0 ) != false ) { ReportFailure( "TestRemove()", "Tried to remove an item at position 0 of an empty array. Should have returned false, but returned true." ); }
	else { totalSuccess++; }

	arr1.Push( "A" );
	arr1.Push( "B" );

    totalTests++;
	if ( arr1.Remove( 2 ) != false ) { ReportFailure( "TestRemove()", "Tried to remove an item at position 2 for an array with items 0 and 1. Should have returned false, but returned true." ); }
	else { totalSuccess++; }

    totalTests++;
	if ( arr1.Remove( -1 ) != false ) { ReportFailure( "TestRemove()", "Tried to remove an item at position -1. Should have returned false, but returned true." ); }
	else { totalSuccess++; }

    totalTests++;
    if ( arr1.Remove( MAX_SIZE ) != false ) { ReportFailure( "TestRemove()", "Tried to remove an item at position MAX_SIZE. Should have returned false, but returned true." ); }
    else { totalSuccess++; }

    /*
    Test 2
    Fill array and remove each item
    */
	SmartStaticArray arr2;

	for ( int i = 0; i < MAX_SIZE; i++ )
	{
        arr2.Push( values[i] );
	}

    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        arr2.Remove( 0 );
    }

    totalTests++;
	if (arr2.Size() != 0) { ReportFailure("TestRemove()", "Removed all items in an array, using position 0, but result is not an array of size 0."); }
    else { totalSuccess++; }

    /*
    Test 3
    Remove an item and compare
    */
    SmartStaticArray arr3, arr4;

    arr3.Push( "A" );
    arr3.Push( "B" );
    arr3.Push( "C" );
    arr3.Push( "D" );

    arr4.Push( "A" );
    arr4.Push( "C" );
    arr4.Push( "D" );

    arr3.Remove( 1 );

    totalTests++;
    if ( arr3 != arr4 ) { ReportFailure( "TestRemove()", "Removed an item at position 1 in an array and the resulting array was wrong." ); }
    else { totalSuccess++; }

    DisplayScore( totalSuccess, totalTests );

    return ( totalSuccess == totalTests );
}

int TestGet()
{
    DisplayTestHeader( "TestGet()" );
    int totalTests = 0;
    int totalSuccess = 0;

    vector<string> values = GetTestItems( MAX_SIZE );

    /*
    Test 1
    Invalid index
    */
    SmartStaticArray arr1;

    totalTests++;
    if ( arr1.Get( -1 ) != "" ) { ReportFailure( "TestGet()", "Created array. Tried to access -1. Result wasn't default value of empty string." ); }
    else { totalSuccess++; }

    totalTests++;
    if ( arr1.Get( MAX_SIZE ) != "" ) { ReportFailure( "TestGet()", "Created array. Tried to access index MAX_SIZE. Result wasn't the default value of empty string." ); }
    else { totalSuccess++; }

    /*
    Test 2
    Empty array
    */
    totalTests++;
    if ( arr1.Get( 0 ) != "" ) { ReportFailure( "TestGet()", "Created empty array and tried to access item at position 0. This should be an empty string because this is an empty array, but it was not." ); }
    else { totalSuccess++; }

    /*
    Test 3
    Fill array and check each item
    */
    SmartStaticArray arr2;
    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        arr2.Push( values[i] );
    }

    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        totalTests++;
        if ( arr2.Get( i ) != values[i] ) { ReportFailure( "TestGet()", "Get failed; expected a value of \"" + values[i%3] + "\" but instead got values of \"" + arr2.Get(i) + "\"" ); break; }
        else { totalSuccess++; }
    }


    DisplayScore( totalSuccess, totalTests );

    return ( totalSuccess == totalTests );
}

int TestSize()
{
    DisplayTestHeader( "TestSize()" );
    int totalTests = 0;
    int totalSuccess = 0;

    vector<string> values = GetTestItems( MAX_SIZE );

    /*
    Test 1
    Empty array
    */
    SmartStaticArray arr1;

	totalTests++;
    if ( arr1.Size() != 0 ) { ReportFailure( "TestSize()", "Created empty array. Expected Size() to return 0, but it did not." ); }
	else { totalSuccess++; }

    /*
    Test 2
    Not full, not empty
    */
    SmartStaticArray arr2;
    arr2.Push( "A" );
    arr2.Push( "B" );
    arr2.Push( "C" );

	totalTests++;
    if ( arr2.Size() != 3 ) { ReportFailure( "TestSize()", "Created array with 3 items. Expected Size() to return 3, but it did not." ); }
	else { totalSuccess++; }

    /*
    Test 3
    Full array
    */
    SmartStaticArray arr3;
    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        arr3.Push( "asdf" );
    }

	totalTests++;
    if ( arr3.Size() != MAX_SIZE ) { ReportFailure( "TestSize()", "Created full array. Expected Size() to return MAX_SIZE, but it did not." );  }
	else { totalSuccess++; }

    /*
    Test 4
    Tried to insert too many items
    */
    SmartStaticArray arr4;
    for ( int i = 0; i < MAX_SIZE + 2; i++ )
    {
        arr4.Push( "jkl" );
    }

	totalTests++;
    if ( arr4.Size() != MAX_SIZE ) { ReportFailure( "TestSize()", "Tried to over-fill array. Expected Size() to return MAX_SIZE, but it did not." ); }
	else { totalSuccess++; }

    DisplayScore( totalSuccess, totalTests );

    return ( totalSuccess == totalTests );
}

int TestIsFull()
{
    DisplayTestHeader( "TestIsFull()" );
    int totalTests = 0;
    int totalSuccess = 0;

    vector<string> values = GetTestItems( MAX_SIZE );

    /*
    Test 1
    Check empty array
    */
    SmartStaticArray arr1;

    totalTests++;
    if ( arr1.IsFull() == true ) { ReportFailure( "TestIsFull()", "Created new array, and it is marked as full, but it's a new array!" ); }
    else { totalSuccess++; }

    /*
    Test 2
    Fill array and check
    */
    SmartStaticArray arr2;
    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        arr2.Push( "item" );
    }

    totalTests++;
    if ( arr2.IsFull() == false ) { ReportFailure( "TestIsFull()", "Filled up array, expected it to be marked as full, but it wasn't." ); }
    else { totalSuccess++; }

    /*
    Test 3
    Fill array, remove one, check
    */
    arr2.Pop();

    totalTests++;
    if ( arr2.IsFull() == true ) { ReportFailure( "TestIsFull()", "Popped one off full array, should be marked as not full, but returned full." ); }
	else { totalSuccess++; }

    DisplayScore( totalSuccess, totalTests );

    return ( totalSuccess == totalTests );
}

int TestIsEmpty()
{
    DisplayTestHeader( "TestIsEmpty()" );
    int totalTests = 0;
    int totalSuccess = 0;

    vector<string> values = GetTestItems( MAX_SIZE );

    /*
    Test 1
    A new array should be empty
    */
    SmartStaticArray arr1;

    totalTests++;
    if ( arr1.IsEmpty() == false ) { ReportFailure( "TestIsEmpty()", "Created new array, expected it to be empty, but it isn't!" ); }
    else { totalSuccess++; }

    /*
    Test 2
    Create an array, push an item, remove an item, see if empty
    */
    SmartStaticArray arr2;
    arr2.Push( "test" );
    arr2.Pop();

    totalTests++;
    if ( arr2.IsEmpty() == false ) { ReportFailure( "TestIsEmpty()", "Created array, pushed and popped item, expected it to be empty, but it isn't!" ); }
    else { totalSuccess++; }

    DisplayScore( totalSuccess, totalTests );

    return ( totalSuccess == totalTests );
}

int TestSubscriptOperator()
{
    DisplayTestHeader( "TestSubscriptOperator()" );
    int totalTests = 0;
    int totalSuccess = 0;

    vector<string> values = GetTestItems( MAX_SIZE );

    /*
    Test 1
    Invalid subscripts
    */

	SmartStaticArray arr1;

	totalTests++;
	if ( arr1.Get( MAX_SIZE - 2 ) != "" ) { ReportFailure( "TestSubscriptOperator()", "Tried to use Get() on empty array, and it didn't return an empty string!" ); }
    else { totalSuccess++; }

	totalTests++;
	if ( arr1.Get( MAX_SIZE + 2 ) != "" ) { ReportFailure( "TestSubscriptOperator()", "Tried to use Get() for out-of-bounds index, and it didn't return an empty string!" ); }
    else { totalSuccess++; }

	/*
	Test 2
	Fill array and test all subscripts
	*/
    SmartStaticArray arr2;
	for ( int i = 0; i < MAX_SIZE; i++ )
	{
        arr2.Push( values[i] );
	}

	// Try to access
	for ( int i = 0; i < MAX_SIZE; i++ )
	{
        string result = arr2.Get( i );

        totalTests++;
        if ( result != values[i] )
        {
            ReportFailure( "TestSubscriptOperator()", "Used Get() to access an item. Expected \"" + values[i%5] + "\" but received value \"" + result + "\"!" );
        }
        else { totalSuccess++; }
	}


    DisplayScore( totalSuccess, totalTests );

    return ( totalSuccess == totalTests );
}

int TestAssignmentOperator()
{
    DisplayTestHeader( "TestAssignmentOperator()" );
    int totalTests = 0;
    int totalSuccess = 0;

    vector<string> values = GetTestItems( MAX_SIZE );

    /*
    Test 1
    Set one array to another and validate
    */
	SmartStaticArray arr1, arr2;

	for ( int i = 0; i < MAX_SIZE; i++ )
	{
        arr1.Push( values[i] );
	}

	// Assign
	arr2 = arr1;

	// Validate
	for ( int i = 0; i < MAX_SIZE; i++ )
	{
        totalTests++;
        if ( arr1.Get( i ) != arr2.Get( i ) ) {
            ReportFailure( "TestAssignmentOperator()",
            "Used assignment operator to set arr2 to arr1. Element mismatch: arr1 at "
            + StringUtil::ToString( i ) + " = "
            + arr1.Get( i ) + ", arr 2 at "
            + StringUtil::ToString( i ) + " = " + arr2.Get( i ) );
            break; }
        else { totalSuccess++; }
	}

	// Test 2: Assign one array to an empty array
	SmartStaticArray arr3, arr4;

	arr3 = arr4;

    totalTests++;
	if ( arr3.IsEmpty() == false ) { ReportFailure( "TestAssignmentOperator()", "Used assignment operator to set arr3 to the empty arr4. arr3 is not being reported as empty, but should be." ); }
	else { totalSuccess++; }

    DisplayScore( totalSuccess, totalTests );

    return ( totalSuccess == totalTests );
}

int TestEqualityOperator()
{
    DisplayTestHeader( "TestEqualityOperator()" );
    int totalTests = 0;
    int totalSuccess = 0;

    vector<string> values = GetTestItems( MAX_SIZE );

    /*
    Test 1
    Test on empty arrays
    */
    SmartStaticArray arr1, arr2;
    bool isSame = ( arr1 == arr2 );

    totalTests++;
    if ( !isSame ) { ReportFailure( "TestEqualityOperator()", "Tried to compare two empty arrays with == but returned false. Expected true." ); }
    else { totalSuccess++; }

    /*
    Test 2
    Test on equal arrays
    */
    SmartStaticArray arr3, arr4;

    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        arr3.Push( values[i] );
        arr4.Push( values[i] );
    }

    isSame = ( arr3 == arr4 );
    totalTests++;
    if ( isSame == false ) { ReportFailure( "TestEqualityOperator()", "Tried to compare two equal arrays with == but returned false. Expected true." ); }
    else { totalSuccess++; }

    /*
    Test 3
    Test on two arrays that have same elements, up until some point; size is unequal.
    */
    arr3.Pop();

    totalTests++;
    if ( arr3 == arr4 ) { ReportFailure( "TestEqualityOperator()", "Tried to compare two unequal arrays with similar values with == but returned true. Expected false." ); }
    else { totalSuccess++; }

    /*
    Test 4
    Test on unequal arrays
    */
    string values2[3] = { "1", "2", "5" };
    SmartStaticArray arr5, arr6;

    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        arr5.Push( values[i] );
        arr6.Push( values2[i%3] );
    }

    totalTests++;
    if ( arr5 == arr6 ) { ReportFailure( "TestEqualityOperator()", "Tried to compare two unequal arrays with == but returned true. Expected false." ); }
    else { totalSuccess++; }

    DisplayScore( totalSuccess, totalTests );

    return ( totalSuccess == totalTests );
}


vector<string> GetTestItems( int size )
{
    vector<string> arr;
    for ( int i = 0; i < size; i++ )
    {
        string blah = "";

        for ( int j = 1; j < ( rand() % 10 + 3 ); j++ )
        {
            int ascii = ( rand() % 25 ) + 65;
            blah += char( ascii );
        }

        arr.push_back( blah );
    }

    return arr;
}

};


Tester::Tester()
{
    AddTest( TestListItem( "Push",          bind( &Tester::TestPush, this ) ) );
    AddTest( TestListItem( "Insert",        bind( &Tester::TestInsert, this ) ) );
    AddTest( TestListItem( "Extend",        bind( &Tester::TestExtend, this ) ) );
    AddTest( TestListItem( "Pop",           bind( &Tester::TestPop, this ) ) );
    AddTest( TestListItem( "Remove",        bind( &Tester::TestRemove, this ) ) );
    AddTest( TestListItem( "Get",           bind( &Tester::TestGet, this ) ) );
    AddTest( TestListItem( "Size",          bind( &Tester::TestSize, this ) ) );
    AddTest( TestListItem( "IsFull",        bind( &Tester::TestIsFull, this ) ) );
    AddTest( TestListItem( "IsEmpty",       bind( &Tester::TestIsEmpty, this ) ) );
    AddTest( TestListItem( "operator[]",    bind( &Tester::TestSubscriptOperator, this ) ) );
    AddTest( TestListItem( "operator=",     bind( &Tester::TestAssignmentOperator, this ) ) );
    AddTest( TestListItem( "operator==",    bind( &Tester::TestEqualityOperator, this ) ) );
//    AddTest( TestListItem( "operator!=",    bind( &Tester::TestInequalityOperator, this ) ) );
}

#endif