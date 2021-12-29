#pragma once
#include<fstream>
#include<algorithm>
#include"Location.h"
using std::ifstream;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::ios;


enum validVerbs  {look,take,drop,open,quit};
string to_lower(string s)
{
	std::for_each(s.begin(), s.end(), [](char& c) {
		c = ::tolower(c);
		});
	return s;
}

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
		string verb, noun;
		int spacePos = input.find(" ");
		verb = to_lower(input.substr(0, spacePos));
		if (spacePos > -1)
			noun = to_lower(input.substr(spacePos + 1));
		else
			noun.clear();
		
		cout << "Verb:" << verb<<"\n";
		cout << "Noun:" << noun << "\n";
		
		switch (verb)
		{

		}
	}

};


