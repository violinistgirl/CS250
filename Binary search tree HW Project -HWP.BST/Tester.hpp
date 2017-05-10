/*
DON'T MODIFY THIS FILE

If this file doesn't compile for you in Code::Blocks,
go to the Build Options (Project > Build options...)
and select the flag for
"Have g++ follow the C++11 ISO C++ language standard"
*/

#ifndef _TESTER_HPP	// Don't allow duplicates
#define _TESTER_HPP	// Don't allow duplicates

#include <iostream>
#include <string>
using namespace std;

#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"
#include "cuTEST/StringUtil.hpp"

#include "BinarySearchTree.hpp"

//! A tester that runs a series of unit tests on the BinarySearchTree object, it will output a **test_result.txt** file with the results.
class Tester : public TesterBase
{
public:
	Tester()
	{
		AddTest(TestListItem("Insert()",            bind(&Tester::Insert, this)));
		AddTest(TestListItem("Contains()",          bind(&Tester::Contains, this)));
		AddTest(TestListItem("FindNode()",          bind(&Tester::FindNode, this)));
		AddTest(TestListItem("FindParentOfNode()",  bind(&Tester::FindParentOfNode, this)));
		AddTest(TestListItem("Delete()",            bind(&Tester::Delete, this)));
		AddTest(TestListItem("GetInOrder()",        bind(&Tester::GetInOrder, this)));
		AddTest(TestListItem("GetPreOrder()",       bind(&Tester::GetPreOrder, this)));
		AddTest(TestListItem("GetPostOrder()",      bind(&Tester::GetPostOrder, this)));
		AddTest(TestListItem("GetMax()",            bind(&Tester::GetMax, this)));
		AddTest(TestListItem("GetCount()",          bind(&Tester::GetCount, this)));
		AddTest(TestListItem("GetHeight()",         bind(&Tester::GetHeight, this)));
	}

private:
	int Insert();
	int Delete();
	int Contains();
	int FindNode();
	int FindParentOfNode();
	int GetInOrder();
	int GetPreOrder();
	int GetPostOrder();
	int GetMax();
	int GetCount();
	int GetHeight();
};


int Tester::Insert()
{
    InitTest( "Insert()", { "Insert()" } );

    StartTest( "Test 1: Insert 1 item" );
    BinarySearchTree<string, string> bst1;
    // We don't care about the data, just the key.
    bst1.Insert( "cow", "" );
    if ( bst1.m_ptrRoot == nullptr )
    {
        TestFail();
        ReportFailure( "Insert Test 1"
            "Inserted one item into tree, but m_ptrRoot is nullptr!" );
    }
    else if ( bst1.m_ptrRoot->key != "cow" )
    {
        TestFail();
        ReportFailure( "Insert Test 1",
            "Inserted one item into tree, but it does not show up as root's value!",
            "cow", bst1.m_ptrRoot->key );
    }
    else if ( bst1.m_nodeCount != 1 )
    {
        TestFail();
        ReportFailure( "Insert Test 1",
            "Inserted one item into tree, but tree m_nodeCount is not 1!",
            StringUtil::ToString( 1 ), StringUtil::ToString( bst1.m_nodeCount ) );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 2: Insert B-A-C" );
    BinarySearchTree<string, string> bst2;
    bst2.Insert( "B", "" );
    bst2.Insert( "A", "" );
    bst2.Insert( "C", "" );

    if ( bst2.m_ptrRoot == nullptr )
    {
        TestFail();
        ReportFailure( "Insert Test 2"
            "Inserted three items into tree, but m_ptrRoot is nullptr!" );
    }
    else if ( bst2.m_ptrRoot->key != "B" )
    {
        TestFail();
        ReportFailure( "Insert Test 2",
            "Inserted B-A-C into tree, but it does not show up as root's value!",
            "B", bst2.m_ptrRoot->key );
    }
    else if ( bst2.m_ptrRoot->ptrLeft == nullptr )
    {
        TestFail();
        ReportFailure( "Insert Test 2",
            "Inserted B-A-C into tree, but root's left pointer is nullptr!" );
    }
    else if ( bst2.m_ptrRoot->ptrRight == nullptr )
    {
        TestFail();
        ReportFailure( "Insert Test 2",
            "Inserted B-A-C into tree, but root's right pointer is nullptr!" );
    }
    else if ( bst2.m_ptrRoot->ptrLeft->key != "A" )
    {
        TestFail();
        ReportFailure( "Insert Test 2",
            "Inserted B-A-C into tree, but root's left node isn't A!",
            "A", bst2.m_ptrRoot->ptrLeft->key );
    }
    else if ( bst2.m_ptrRoot->ptrRight->key != "C" )
    {
        TestFail();
        ReportFailure( "Insert Test 2",
            "Inserted B-A-C into tree, but root's right node isn't C!",
            "C", bst2.m_ptrRoot->ptrLeft->key );
    }
    else if ( bst2.m_nodeCount != 3 )
    {
        TestFail();
        ReportFailure( "Insert Test 2",
            "Inserted three items into tree, but tree m_nodeCount is not 3!",
            StringUtil::ToString( 3 ), StringUtil::ToString( bst2.m_nodeCount ) );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 3: Insert A-B-C" );
    BinarySearchTree<string, string> bst3;
    bst3.Insert( "A", "" );
    bst3.Insert( "B", "" );
    bst3.Insert( "C", "" );

    if ( bst3.m_ptrRoot == nullptr )
    {
        TestFail();
        ReportFailure( "Insert Test 3"
            "Inserted three items into tree, but m_ptrRoot is nullptr!" );
    }
    else if ( bst3.m_ptrRoot->key != "A" )
    {
        TestFail();
        ReportFailure( "Insert Test 3",
            "Inserted A-B-C into tree, but it does not show up as root's value!",
            "B", bst3.m_ptrRoot->key );
    }
    else if ( bst3.m_ptrRoot->ptrLeft != nullptr )
    {
        TestFail();
        ReportFailure( "Insert Test 3",
            "Inserted A-B-C into tree, but root's left pointer isn't nullptr!" );
    }
    else if ( bst3.m_ptrRoot->ptrRight == nullptr )
    {
        TestFail();
        ReportFailure( "Insert Test 3",
            "Inserted A-B-C into tree, but root's right pointer is nullptr!" );
    }
    else if ( bst3.m_ptrRoot->ptrRight->key != "B" )
    {
        TestFail();
        ReportFailure( "Insert Test 3",
            "Inserted A-B-C into tree, but root's right node isn't B!",
            "B", bst3.m_ptrRoot->ptrRight->key );
    }
    else if ( bst3.m_ptrRoot->ptrRight->ptrRight == nullptr )
    {
        TestFail();
        ReportFailure( "Insert Test 3",
            "Inserted A-B-C into tree, but root > right > right pointer is nullptr!" );
    }
    else if ( bst3.m_ptrRoot->ptrRight->ptrRight->key != "C" )
    {
        TestFail();
        ReportFailure( "Insert Test 3",
            "Inserted A-B-C into tree, but root > right > right node isn't C!",
            "C", bst3.m_ptrRoot->ptrRight->ptrRight->key );
    }
    else if ( bst3.m_nodeCount != 3 )
    {
        TestFail();
        ReportFailure( "Insert Test 3",
            "Inserted three items into tree, but tree m_nodeCount is not 3!",
            StringUtil::ToString( 3 ), StringUtil::ToString( bst3.m_nodeCount ) );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 4: Insert C-B-A" );
    BinarySearchTree<string, string> bst4;
    bst4.Insert( "C", "" );
    bst4.Insert( "B", "" );
    bst4.Insert( "A", "" );

    if ( bst4.m_ptrRoot == nullptr )
    {
        TestFail();
        ReportFailure( "Insert Test 4"
            "Inserted three items into tree, but m_ptrRoot is nullptr!" );
    }
    else if ( bst4.m_ptrRoot->key != "C" )
    {
        TestFail();
        ReportFailure( "Insert Test 4",
            "Inserted C-B-A into tree, but it does not show up as root's value!",
            "C", bst4.m_ptrRoot->key );
    }
    else if ( bst4.m_ptrRoot->ptrRight != nullptr )
    {
        TestFail();
        ReportFailure( "Insert Test 4",
            "Inserted C-B-A into tree, but root's right pointer isn't nullptr!" );
    }
    else if ( bst4.m_ptrRoot->ptrLeft == nullptr )
    {
        TestFail();
        ReportFailure( "Insert Test 4",
            "Inserted C-B-A into tree, but root's left pointer is nullptr!" );
    }
    else if ( bst4.m_ptrRoot->ptrLeft->key != "B" )
    {
        TestFail();
        ReportFailure( "Insert Test 4",
            "Inserted C-B-A into tree, but root's left node isn't B!",
            "B", bst4.m_ptrRoot->ptrLeft->key );
    }
    else if ( bst4.m_ptrRoot->ptrLeft->ptrLeft == nullptr )
    {
        TestFail();
        ReportFailure( "Insert Test 4",
            "Inserted C-B-A into tree, but root > left > left pointer is nullptr!" );
    }
    else if ( bst4.m_ptrRoot->ptrLeft->ptrLeft->key != "A" )
    {
        TestFail();
        ReportFailure( "Insert Test 4",
            "Inserted C-B-A into tree, but root > left > left node isn't A!",
            "A", bst4.m_ptrRoot->ptrLeft->ptrLeft->key );
    }
    else if ( bst4.m_nodeCount != 3 )
    {
        TestFail();
        ReportFailure( "Insert Test 4",
            "Inserted three items into tree, but tree m_nodeCount is not 3!",
            StringUtil::ToString( 3 ), StringUtil::ToString( bst4.m_nodeCount ) );
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::Delete()
{
    InitTest( "Delete()", { "Insert()", "Delete()" } );

    int testIndex = 1;
    StartTest( "Delete Test 1: Delete a leaf" );
    BinarySearchTree<int, string> bst1;
    bst1.Insert( 5, "" );
    bst1.Insert( 3, "" );
    bst1.Insert( 7, "" );
    bst1.Delete( 7 );

    if ( bst1.m_nodeCount != 2 )
    {
        TestFail();
        ReportFailure( "Delete Test " + STR( testIndex ),
            "Deleted leaf node 7, but item count is not 2!",
            STR( 2 ), STR( bst1.m_nodeCount ) );
    }
    else if ( bst1.m_ptrRoot->ptrRight != nullptr )
    {
        TestFail();
        ReportFailure( "Delete Test " + STR( testIndex ),
            "Deleted leaf node 7, the item to the right of root is not nullptr!" );
    }
    else
    {
        TestPass();
    }

    testIndex++;
    StartTest( "Delete Test 2: Delete a non-leaf; Insert: 5, 3, 7, 6, 8" );
    BinarySearchTree<int, string> bst2;
    bst2.Insert( 5, "" );
    bst2.Insert( 3, "" );
    bst2.Insert( 7, "" );
    bst2.Insert( 6, "" );
    bst2.Insert( 8, "" );
    bst2.Delete( 7 ); // has two children

    /*  BEFORE:             AFTER:
            5                   5
          /   \               /   \
         3     7             3     8
             /   \                /
            6     8              6
    */

    if ( bst2.m_nodeCount != 4 )
    {
        TestFail();
        ReportFailure( "Delete Test " + STR( testIndex ),
            "Deleted leaf node 7, but item count is not 4!",
            STR( 4 ), STR( bst2.m_nodeCount ) );
    }
    else if ( bst2.m_ptrRoot->ptrRight == nullptr )
    {
        TestFail();
        ReportFailure( "Delete Test " + STR( testIndex ),
            "Deleted leaf node 7, root > right is nullptr!" );
    }
    else if ( bst2.m_ptrRoot->ptrRight->key != 8 )
    {
        TestFail();
        ReportFailure( "Delete Test " + STR( testIndex ),
            "Deleted leaf node 7, root > right is not the expected value!",
            STR( 8 ), STR( bst2.m_ptrRoot->ptrRight->key ) );
    }
    else if ( bst2.m_ptrRoot->ptrRight->ptrLeft == nullptr )
    {
        TestFail();
        ReportFailure( "Delete Test " + STR( testIndex ),
            "Deleted leaf node 7, root > right > left is nullptr!" );
    }
    else if ( bst2.m_ptrRoot->ptrRight->ptrLeft->key != 6 )
    {
        ReportFailure( "Delete Test " + STR( testIndex ),
            "Deleted leaf node 7, root > right > right is not the expected value!",
            STR( 6 ), STR( bst2.m_ptrRoot->ptrRight->ptrLeft->key ) );
    }
	else
	{
		TestPass();//this was missing...
	}


    DisplayScore();
    return TestResult();
}

int Tester::Contains()
{
    InitTest( "Contains()", { "Contains()", "Insert()" } );

    StartTest( "Test 1: Check if an item contained in the list returns true, tree size 1" );
    BinarySearchTree<string, string> bst1;
    bst1.Insert( "cow", "" );
    bool found = bst1.Contains( "cow" );
    if ( found == false )
    {
        TestFail();
        ReportFailure( "Contains Test 1",
            "Inserted \"cow\" into tree at root, but it was not found by Contains()!" );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 2: Check if an item contained in the list returns true, tree size 3" );
    BinarySearchTree<string, string> bst2;
    bst2.Insert( "b", "" );
    bst2.Insert( "a", "" );
    bst2.Insert( "c", "" );
    bst2.Insert( "d", "" );
    found = bst2.Contains( "d" );
    if ( found == false )
    {
        TestFail();
        ReportFailure( "Contains Test 2",
            "Inserted a, b, c, and d into tree, but it was not found by Contains()!" );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 3: Check if an item NOT contained in the list returns false" );
    BinarySearchTree<int, string> bst3;
    bst3.Insert( 4, "" );
    bst3.Insert( 3, "" );
    bst3.Insert( 5, "" );
    bst3.Insert( 2, "" );
    found = bst3.Contains( 0 );
    if ( found == true )
    {
        TestFail();
        ReportFailure( "Contains Test 3",
            "Inserted 4, 3, 5, 2 into tree, tried to find 0 and Contains() returned true!" );
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::FindNode()
{
    InitTest( "FindNode()", { "FindNode()" } );

    StartTest( "Test 1: Check if an item contained in the list returns true, tree size 1" );
    BinarySearchTree<string, string> bst1;
    bst1.Insert( "cow", "" );
    Node<string, string>* found = bst1.FindNode( "cow" );
    if ( found == nullptr )
    {
        TestFail();
        ReportFailure( "FindNode Test 1",
            "Inserted \"cow\" into tree at root, but it was not found by FindNode()!" );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 2: Check if an item contained in the list returns true, tree size 3" );
    BinarySearchTree<string, string> bst2;
    bst2.Insert( "b", "" );
    bst2.Insert( "a", "" );
    bst2.Insert( "c", "" );
    bst2.Insert( "d", "" );
    found = bst2.FindNode( "d" );
    if ( found == nullptr )
    {
        TestFail();
        ReportFailure( "FindNode Test 2",
            "Inserted a, b, c, and d into tree, but it was not found by FindNode()!" );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 3: Check if an item NOT contained in the list returns false" );
    BinarySearchTree<int, string> bst3;
    bst3.Insert( 4, "" );
    bst3.Insert( 3, "" );
    bst3.Insert( 5, "" );
    bst3.Insert( 2, "" );
    Node<int, string>* intFound = bst3.FindNode( 0 );
    if ( intFound != nullptr )
    {
        TestFail();
        ReportFailure( "FindNode Test 3",
            "Inserted 4, 3, 5, 2 into tree, tried to find 0 and FindNode() didn't return nullptr!" );
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::FindParentOfNode()
{
    InitTest( "FindParentOfNode()", { "FindParentOfNode()" } );

    StartTest( "Test 1: Check if an item contained in the list returns true, tree size 1" );
    BinarySearchTree<string, string> bst1;
    bst1.Insert( "cow", "" );
    Node<string, string>* strParent = bst1.FindParentOfNode( "cow" );
    if ( strParent != nullptr )
    {
        TestFail();
        ReportFailure( "FindParentOfNode Test 1",
            "Inserted \"cow\" into tree at root, but FindParentOfNode returned something besides nullptr!" );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 2: Check if an item contained in the list returns true, tree size 3" );
    BinarySearchTree<string, string> bst2;
    bst2.Insert( "b", "" );
    bst2.Insert( "a", "" );
    bst2.Insert( "c", "" );
    bst2.Insert( "d", "" );
    strParent = bst2.FindParentOfNode( "d" );
    if ( strParent == nullptr )
    {
        TestFail();
        ReportFailure( "FindParentOfNode Test 2",
            "Inserted b, a, c, d into tree, parent of d should be c, but it returned nullptr!" );
    }
    else if ( strParent->key != "c" )
    {
        TestFail();
        ReportFailure( "FindParentOfNode Test 2",
            "Inserted b, a, c, d into tree, parent of d should be c, but the parent is wrong!",
            "c", strParent->key );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 3: Check if an item NOT contained in the list doesn't return nullptr" );
    BinarySearchTree<int, string> bst3;
    bst3.Insert( 4, "" );
    bst3.Insert( 3, "" );
    bst3.Insert( 5, "" );
    bst3.Insert( 1, "" );
    Node<int, string>* intParent = bst3.FindParentOfNode( 0 );
    if ( intParent != nullptr )
    {
        TestFail();
        ReportFailure( "FindParentOfNode Test 3",
            "Inserted 4, 3, 5, 1 into tree, tried to find 0 and FindParentOfNode() didn't return nullptr!" );
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::GetInOrder()
{
    InitTest( "GetInOrder()", { "GetInOrder()", "Insert()" } );
    string expectedOut;
    string actualOut;

    StartTest( "Test 1: Insert F, B, G, A, D, I, H, C, E into tree, get back as in-order..." );
    BinarySearchTree<char, string> bst1;
    bst1.Insert( 'F', "" );
    bst1.Insert( 'B', "" );
    bst1.Insert( 'G', "" );
    bst1.Insert( 'A', "" );
    bst1.Insert( 'D', "" );
    bst1.Insert( 'I', "" );
    bst1.Insert( 'H', "" );
    bst1.Insert( 'C', "" );
    bst1.Insert( 'E', "" );

    expectedOut = "A B C D E F G H I ";
    actualOut = bst1.GetInOrder();

    if ( actualOut != expectedOut )
    {
        TestFail();
        ReportFailure( "GetInOrder Test 1",
            "Inserted into tree: F, B, G, A, D, I, H, C, E. Didn't get expected output.",
            "\"" + expectedOut + "\"", "\"" + actualOut + "\"" );
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::GetPreOrder()
{
    InitTest( "GetPreOrder()", { "GetPreOrder()", "Insert()" } );
    string expectedOut;
    string actualOut;

    StartTest( "Test 1: Insert F, B, G, A, D, I, H, C, E into tree, get back as pre-order..." );
    BinarySearchTree<char, string> bst1;
    bst1.Insert( 'F', "" );
    bst1.Insert( 'B', "" );
    bst1.Insert( 'G', "" );
    bst1.Insert( 'A', "" );
    bst1.Insert( 'D', "" );
    bst1.Insert( 'I', "" );
    bst1.Insert( 'H', "" );
    bst1.Insert( 'C', "" );
    bst1.Insert( 'E', "" );

    expectedOut = "F B A D C E G I H ";
    actualOut = bst1.GetPreOrder();

    if ( actualOut != expectedOut )
    {
        TestFail();
        ReportFailure( "GetPreOrder Test 1",
            "Inserted into tree: F, B, G, A, D, I, H, C, E. Didn't get expected output.",
            "\"" + expectedOut + "\"", "\"" + actualOut + "\"" );
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::GetPostOrder()
{
    InitTest( "GetPostOrder()", { "GetPostOrder()", "Insert()" } );
    string expectedOut;
    string actualOut;

    StartTest( "Test 1: Insert F, B, G, A, D, I, H, C, E into tree, get back as post-order..." );
    BinarySearchTree<char, string> bst1;
    bst1.Insert( 'F', "" );
    bst1.Insert( 'B', "" );
    bst1.Insert( 'G', "" );
    bst1.Insert( 'A', "" );
    bst1.Insert( 'D', "" );
    bst1.Insert( 'I', "" );
    bst1.Insert( 'H', "" );
    bst1.Insert( 'C', "" );
    bst1.Insert( 'E', "" );

    expectedOut = "A C E D B H I G F ";
    actualOut = bst1.GetPostOrder();

    if ( actualOut != expectedOut )
    {
        TestFail();
        ReportFailure( "GetPostOrder Test 1",
            "Inserted into tree: F, B, G, A, D, I, H, C, E. Didn't get expected output.",
            "\"" + expectedOut + "\"", "\"" + actualOut + "\"" );
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::GetMax()
{
    InitTest( "GetMax()", { "GetMax()", "Insert()" } );

    StartTest( "Test 1: Insert one item, get max value..." );
    BinarySearchTree<char, string> bst1;
    bst1.Insert( 'B', "" );

    char expectedOut = 'B';
    char* actualOut = bst1.GetMax();

    if ( actualOut == nullptr )
    {
        TestFail();
        ReportFailure( "GetMax Test 1",
            "Inserted one item, but received nullptr from GetMax()!" );
    }
    else if ( *actualOut != expectedOut )
    {
        TestFail();
        ReportFailure( "GetMax Test 1",
            "Inserted one item, got wrong value from GetMax()!",
            expectedOut, *actualOut );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 2: Insert B, A, C, D, E, get max value..." );
    BinarySearchTree<char, string> bst2;
    bst2.Insert( 'B', "" );
    bst2.Insert( 'A', "" );
    bst2.Insert( 'C', "" );
    bst2.Insert( 'D', "" );
    bst2.Insert( 'E', "" );

    expectedOut = 'E';
    actualOut = bst2.GetMax();

    if ( actualOut == nullptr )
    {
        TestFail();
        ReportFailure( "GetMax Test 2",
            "Inserted B, A, C, D, E, but received nullptr from GetMax()!" );
    }
    else if ( *actualOut != expectedOut )
    {
        TestFail();
        ReportFailure( "GetMax Test 2",
            "Inserted B, A, C, D, E, got wrong value from GetMax()!",
            expectedOut, *actualOut );
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::GetCount()
{
    InitTest( "GetCount()", { "GetCount()", "Insert()" } );

    StartTest( "Test 1: Insert nothing into tree, check count..." );
    BinarySearchTree<char, string> bst1;

    int expectedOut = 0;
    int actualOut = bst1.GetCount();

    if ( actualOut != expectedOut )
    {
        TestFail();
        ReportFailure( "GetCount Test 1",
            "Empty tree returned wrong result for GetCount()!",
            expectedOut, actualOut );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 2: Insert five things into tree, check count..." );
    BinarySearchTree<char, string> bst2;
    bst1.Insert( 'B', "" );
    bst1.Insert( 'A', "" );
    bst1.Insert( 'C', "" );
    bst1.Insert( 'D', "" );
    bst1.Insert( 'E', "" );

    expectedOut = 0;
    actualOut = bst2.GetCount();

    if ( actualOut != expectedOut )
    {
        TestFail();
        ReportFailure( "GetCount Test 2",
            "Empty tree returned wrong result for GetCount()!",
            expectedOut, actualOut );
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::GetHeight()
{
    InitTest( "GetHeight()", { "GetHeight()", "Insert()" } );

    int expectedOut;
    int actualOut;

    StartTest( "Test 1: Empty tree..." );
    BinarySearchTree<char, string> bst1;

    expectedOut = 0;
    actualOut = bst1.GetHeight();

    if ( actualOut != expectedOut )
    {
        TestFail();
        ReportFailure( "GetHeight Test 1",
            "Wrong result for GetHeight()!",
            expectedOut, actualOut );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 2: One level..." );
    BinarySearchTree<char, string> bst2;
    bst2.Insert( 'A', "" );

    expectedOut = 1;
    actualOut = bst2.GetHeight();

    if ( actualOut != expectedOut )
    {
        TestFail();
        ReportFailure( "GetHeight Test 2",
            "Wrong result for GetHeight()!",
            expectedOut, actualOut );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 3: Two levels..." );
    BinarySearchTree<char, string> bst3;
    bst3.Insert( 'A', "" );
    bst3.Insert( 'B', "" );

    expectedOut = 2;
    actualOut = bst3.GetHeight();

    if ( actualOut != expectedOut )
    {
        TestFail();
        ReportFailure( "GetHeight Test 3",
            "Wrong result for GetHeight()!",
            expectedOut, actualOut );
    }
    else
    {
        TestPass();
    }

    StartTest( "Test 4: Three levels..." );
    BinarySearchTree<char, string> bst4;
    bst4.Insert( 'B', "" );
    bst4.Insert( 'A', "" );
    bst4.Insert( 'C', "" );
    bst4.Insert( 'D', "" );

    expectedOut = 3;
    actualOut = bst4.GetHeight();

    if ( actualOut != expectedOut )
    {
        TestFail();
        ReportFailure( "GetHeight Test 4",
            "Wrong result for GetHeight()!",
            expectedOut, actualOut );
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}



#endif
