#include <iostream>
#include <vector>
#include <string>
using namespace std;

void AddIngredients( vector<string>& ingredients )
{
    // Use the push_back function to add "lettuce", "tomato", "mayo", "mustard", and "bread" to the vector.
	ingredients.push_back("lettuce");
	ingredients.push_back("tomato");
	ingredients.push_back("mayo");
	ingredients.push_back("mustard");
	ingredients.push_back("bread");
}

void DisplayIngredients( const vector<string>& ingredients )
{
    // Use a for-loop, going from 0 to the ingredient's size(), to display each of the ingredients
	for (int x = 0; x < ingredients.size(); x++) {
		cout << ingredients[x] << endl;
	}
}

int main()
{    
    // 1. Declare a vector of strings named ingredients.
	vector<string> ingredients;
    
    // 2. Call the AddIngredients function, passing in ingredients as an argument.
	AddIngredients(ingredients);
    
    // 3. Call the DisplayIngredients function, passing in ingredients as an argument.
	DisplayIngredients(ingredients);

	return 0;
}
