#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

int main(){
	ifstream in("bird.ppm");
	string buffer;
	string header;
	list<int> colors, colors2;
	int headerLines = 4;

	// Save the header:
	for (int i = 0; i < headerLines; i++) {
		getline(in, buffer);
		header += buffer + "\n";
	}

	int choice, percent = 0;
	char color_rem = 'x';
	cout << "Please choose one:\n 1. Copy image  2. Flip image  3. Remove a color  4. Remove half a color " << endl;
	cin >> choice;

	if (choice == 3 || choice == 4) {
		cout << "Remove which color? (r, g, b)";
		cin >> color_rem;
	}

	int r, g, b, counter;
	while (in >> r >> g >> b) {
		switch(choice) {
			case 2:
				colors.push_front(b);
				colors.push_front(g);
				colors.push_front(r);
				break;
			case 3:
				if (color_rem != 'x') {
					switch (color_rem) {
					case 'r':
						r = r;
						break;
					case 'g':
						g = g;
						break;
					case 'b':
						b = b;
						break;
					default:
						break;
					}
				}
			case 4:
				if (color_rem != 'x') {
					switch (color_rem) {
					case 'r':
						r = r / 2;
						break;
					case 'g':
						g = g / 2;
						break;
					case 'b':
						b = b / 2;
						break;
					default:
						break;
					}
				}
			default:
				colors.push_back(r);
				colors.push_back(g);
				colors.push_back(b);
				break;
		}

	}
	in.close();

	ofstream out("bird2.ppm");
	out << header;

	for (list<int>::iterator x = colors.begin(); x != colors.end(); x++) {
		out << *x << endl;
	}
	out.close();

	return 0;
}
