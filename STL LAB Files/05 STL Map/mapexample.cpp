#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    // Create a map that uses two strings. Name it colors.
	map<string, string> colors;
    
    // Populate several colors and their hex codes
    // red = FF0000, green = 00FF00, blue = 0000FF
    // magenta = FF00FF, yellow = FFFF00, cyan = 00FFFF
	colors["red"] = "FF0000";
	colors["green"] = "00FF00";
	colors["blue"] = "0000FF";
	colors["magenta"] = "FF00FF";
	colors["yellow"] = "FFFF00";
	colors["cyan"] = "00FFFF";
    
    string color;
    cout << "Enter a color: ";
    cin >> color;
    
    // Display the hex value of the color, using the user's input as a key.
	cout << "Hex: " << colors[color] << endl;
    
    return 0;
}
