#ifndef _EXPRESSION_HPP
#define _EXPRESSION_HPP

#include <string>
using namespace std;

class ExpNode
{
public:
    char value;
    ExpNode* ptrLeft;
    ExpNode* ptrRight;

    ExpNode()
    {
        ptrLeft = ptrRight = nullptr;
    }

    ExpNode( char v )
    {
        value = v;
        ptrLeft = ptrRight = nullptr;
    }

    ~ExpNode()
    {
        if ( ptrLeft != nullptr )
        {
            delete ptrLeft;
        }
        if ( ptrRight != nullptr )
        {
            delete ptrRight;
        }
    }
};

class Expression
{
public:
    Expression();
    ~Expression();

    void SetPostfixExpression( const string& postfixExp );

    string GetPostfix();
    string GetInfix();

private:
    void ParsePostfixExpression( const string& postfixExp );
    bool IsOperator( char value );

    string GetPostfix( ExpNode* node );
    string GetInfix( ExpNode* node );

private:
    ExpNode* m_ptrRoot;
};

#endif
