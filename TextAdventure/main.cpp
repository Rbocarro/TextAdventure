
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Item.h"
#include "Location.h"
#include "GameManager.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
int main()
{   
    string asa="love is the danger and i want to keep it alive";
    GameManager g;
    string filename = "data.txt";
	ifstream s(filename);
	if (s.is_open())
		cout << "Reading from file " << filename << endl;
	else
		cout << "ERROR " << filename << endl;
	g.readData(s);


	string input;
	while (!g.HasQuit()) {
		cout << ">> ";
		getline(cin, input);
		g.ExecuteCommand(input);
	}
    return 0;
}
