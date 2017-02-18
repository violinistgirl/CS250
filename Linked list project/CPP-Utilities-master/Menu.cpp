/* Don't modify this file */

#include "Menu.hpp"
#include "Strings.hpp"

#include <cstdlib>
#include <limits>
using namespace std;

namespace dal
{

void Menu::DrawHorizontalBar( int width, char symbol )
{
    for ( int i = 0; i < width; i++ )
    {
        cout << symbol;
    }
    cout << endl;
}

void Menu::Header( const string& header )
{
    DrawHorizontalBar( 80 );
    string head = "| " + header + " |";
    cout << " " << head << endl << " ";
    DrawHorizontalBar( head.size() );
    cout << endl;
}

void Menu::ShowMenu( const vector<string> options, bool vertical )
{
    if ( vertical )
    {
        for ( unsigned int i = 0; i < options.size(); i++ )
        {
            cout << " " << (i+1) << ".\t" << options[i] << endl;
        }
    }
    else
    {
        for ( unsigned int i = 0; i < options.size(); i++ )
        {
            cout << " " << (i+1) << ". " << options[i] << "\t";
        }
        cout << endl;
    }
}

int Menu::ShowIntMenuWithPrompt( const vector<string> options, bool vertical )
{
    ShowMenu( options, vertical );
    int choice = GetValidChoice( 1, options.size() );
    return choice;
}

string Menu::ShowStringMenuWithPrompt( const vector<string> options, bool vertical )
{
    ShowMenu( options, vertical );
    int choice = GetValidChoice( 1, options.size() );
    string value = options[ choice-1 ];
    return value;
}

string Menu::GetStringChoice( const string& message )
{
    if ( message != "" )
    {
        cout << " " << message << endl;
    }

    cout << endl << " >> ";
    string choice;
    cin >> choice;
    cin.ignore();
    cout << endl;
    return choice;
}

string Menu::GetStringLine( const string& message )
{
    if ( message != "" )
    {
        cout << " " << message << endl;
    }
    string choice;
    cout << endl << " >> ";
    getline( cin, choice );
    cout << endl;
    return choice;
}

int Menu::GetIntChoice( const string& message )
{
    if ( message != "" )
    {
        cout << " " << message << endl;
    }
    cout << endl << " >> ";
    int choice;
    cin >> choice;
    cin.ignore();
    cout << endl;
    return choice;
}

int Menu::GetValidChoice( int min, int max, const string& message )
{
    if ( message != "" )
    {
        cout << endl;
        DrawHorizontalBar( message.size() + 2 );
        cout << " " << message << endl;
    }

    int choice = GetIntChoice();

    while ( choice < min || choice > max )
    {
        cout << "Invalid selection. Try again." << endl;
        choice = GetIntChoice();
    }

    return choice;
}

string Menu::GetValidStringChoice( const vector<string> options, bool caseSensitive )
{
    cout << " (";
    for ( unsigned int i = 0; i < options.size(); i++ )
    {
        if ( i != 0 ) { cout << "/"; }
        cout << options[i];
    }
    cout << "): ";

    string choice = GetStringChoice();

    while ( true )
    {
        for ( unsigned int i = 0; i < options.size(); i++ )
        {
            string option = options[i];
            if ( !caseSensitive )
            {
                choice = Strings::ToUpper( choice );
                option = Strings::ToUpper( option );
            }

            if ( choice == option )
            {
                return choice;
            }
        }

        cout << " Invalid input. Try again." << endl;
        choice = GetStringChoice();
    }
}

void Menu::ClearScreen()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "cls" );
    #else
        system( "clear" );
    #endif
}

void Menu::Pause()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "pause" );
    #else
        cout << endl << " Press ENTER to continue..." << endl;
        cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
    #endif
}

}
