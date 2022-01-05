//Text Adventure Game by Reuben Bocarro
//Student number w1786801
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
	GameManager g;
    string filename = "data.txt";
	ifstream s(filename);
	if (s.is_open())								//Reaading file
		cout << "Reading from file " << filename <<
		endl<<"-----------------------------------------------\n";
	else
		cout << "ERROR " << filename << endl;
	g.readData(s);									//pass file data to gameManager for parsing
	g.InitialisePlayerWithLocation(0);				//set player at the first location in the game


	string input;
	while (!g.HasQuit()) {
		cout << ">> ";
		getline(cin, input);
		g.ExecuteCommand(input);
	}


													// Game end message
	if (g.HasQuit())
		cout << "Better luck next time!" << endl;
	else
		cout << "You made it!" << endl;
    return 0;
}
