
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
	if (s.is_open())
		cout << "Reading from file " << filename <<
		endl<<"-----------------------------------------------\n";
	else
		cout << "ERROR " << filename << endl;
	g.readData(s);
	
	g.InitialisePlayerWithLocation(1);



	string input;
	while (!g.HasQuit()) {
		cout << ">> ";
		getline(cin, input);
		g.ExecuteCommand(input);
	}


	// End of game: Give a final message based on whether player quit or reached the goal
	if (g.HasQuit())
		cout << "Better luck next time!" << endl;
	else
		cout << "You made it!" << endl;
    return 0;
}
