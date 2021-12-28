
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Item.h"
#include "Location.h"
#include "GameManager.h"
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
int main()
{   
    string asa="love is the danger and i want to keep it alive";
    GameManager g;
    string filename = "data.txt";
	ifstream s(filename);
	if (s.is_open())
		cout << "Reading from file " << filename << endl;
	else
		cout << "Could not open file " << filename << endl;

	// Parse game data
	g.readData(s);
    return 0;
}
