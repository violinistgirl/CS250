#include <iostream>
using namespace std;

#include "List.hpp"

int main()
{
	List myList;

	string menu[] = { "Insert", "Delete", "Get Item" };

	while (true)
	{
		cout << endl << "-------------------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << i << ". " << menu[i] << endl;
		}

		int choice;
		cout << "Which? ";
		cin >> choice;

		if (choice == 0)
		{
			int position;
			string newItem;

			cout << "Index: ";
			cin >> position;

			cout << "New value: ";
			cin >> newItem;
			try {
				myList.Insert(newItem, position);
			}
			catch (const out_of_range& e) {
				cout << "Invalid position" << endl;
			}
		}
		else if (choice == 1)
		{
			int position;

			cout << "Index: ";
			cin >> position;

			try{
				myList.Delete(position);
			}
			catch (const out_of_range& e) {
				cout << "Invalid position" << endl;
			}
		}
		else if (choice == 2)
		{
			int position;

			cout << "Index: ";
			cin >> position;
			try {
				string item = myList.GetItem(position);
				cout << "Item is " << item << endl;
			} 
			catch (const out_of_range& e) {
				cout << "Invalid position";
			}
		}
	}

	return 0;
}