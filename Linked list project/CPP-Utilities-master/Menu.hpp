#ifndef _MENU
#define _MENU

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace dal
{

class Menu
{
    public:
    // OUTPUT
    static void Header( const string& header );
    static void DrawHorizontalBar( int width, char symbol = '-' );

    // MENUS and INPUT/OUTPUT
    static void ShowMenu( const vector<string> options, bool vertical = true );
    static int ShowIntMenuWithPrompt( const vector<string> options, bool vertical = true );
    static string ShowStringMenuWithPrompt( const vector<string> options, bool vertical = true );

    static int GetValidChoice( int min, int max, const string& message = "" );
    static string GetValidStringChoice( const vector<string> options, bool caseSensitive = false );
    static string GetStringChoice( const string& message = "" );
    static string GetStringLine( const string& message = "" );
    static int GetIntChoice( const string& message = "" );

    // HANDY TRICKS
    static void ClearScreen();
    static void Pause();
};

}

#endif

