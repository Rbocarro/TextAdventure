#pragma once
#include<fstream>
#include"Location.h"
using std::ifstream;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::ios;
class GameManager 
{
private:
	bool quit = false;

public:
	void readData(ifstream& s)
	{	
		string line;
		Location l;
		while (s)
		{
			getline(s, line,':');
			int temp;
			s >> temp;
			s.get();
			l.SetNumber(temp);
			cout << temp;
		}

		//s.read(line, 3);
		
		cout <<"test loc num:" <<l.GetNumber()<<endl;

	}

	bool HasQuit()
	{
		return quit;
	}

	void ExecuteCommand(string input)
	{
		if (input == "quit")
			quit = true;
	}

};
