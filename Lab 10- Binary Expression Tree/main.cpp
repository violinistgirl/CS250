#include "Expression.hpp"

#include <iostream>
using namespace std;

int main()
{
    Expression exp;
    string expString = "ab+ef*g*-";
    exp.SetPostfixExpression( expString );

    cout << "Infix:   " << exp.GetInfix() << endl;
    cout << "Postfix: " << exp.GetPostfix() << endl;

    exp.SetPostfixExpression( "A B + C * D E F G * + / + H -" );

    cout << "Infix:   " << exp.GetInfix() << endl;
    cout << "Postfix: " << exp.GetPostfix() << endl;

	while (true) { ; /* pause before exit */ }

    return 0;
}
