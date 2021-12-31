#pragma once
#include<fstream>
#include<algorithm>
#include<map>
#include"Location.h"
using std::ifstream;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::ios;
using std::map;


enum validVerbs { look, take, drop, open, quit };




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
	vector<Location*> locations;

public:
	void readData(ifstream& s)
	{	
		string line;
		//while (getline(s, line, ':'))
		//{	
		//	int temp;
		//	s >> temp;
		//	locations.push_back(new Location(temp));
		//}

		//for (; getline(s, line, ':'); )
		//{
		//		int tempint;
		//		string tempnameSrt;
		//		string tempDescSrt;
		//		s >> tempint;
		//		getline(s, tempnameSrt,'\n');
		//		locations.push_back(new Location(tempint,tempnameSrt));
		//		s.get();
		//}
		while (getline(s, line,':'))
		{	
			int tempint;
			string tempnameSrt;
			string tempDescSrt;
			s >> tempint;
			getline(s, tempnameSrt,':');
			getline(s, tempnameSrt);
			getline(s, tempDescSrt, ':');
			getline(s, tempDescSrt);
			locations.push_back(new Location(tempint,tempnameSrt,tempDescSrt));
		}




		//s.read(line, 3);
		//cout << "Locations vector size:" << locations.size() << endl<<endl;
		//for (int i = 0; i<locations.size(); i++)
		//{
		//	cout << "Location value:" << locations[i]->GetNumber() << endl;
		//	cout << "Location name:" << locations[i]->GetName() << endl;
		//	cout << "Location Description:" << locations[i]->GetDescription() << endl;
		//	cout << endl;
		//}
		

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
		
		if (verb == "quit")
		{
			quit = true;
		}
		if (verb == "look")
		{
			cout << "looking around";
		}
		if (verb == "take")
		{
			cout << "take item";
		}
	}


	// Returns the location with the given id, creating it if necessary.
	Location* getOrCreateLocation(int id) 
	{
		if (locations[id] == nullptr)
		{
			cout << "Cannot Initialise location" << endl;
		}
		return locations[id-1];
	}

};


