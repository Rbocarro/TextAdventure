#pragma once
#include<fstream>
#include<algorithm>
#include<map>
#include"Location.h"
#include"Item.h"//testing only remove afterwards.
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
	vector<Item*> tempItems;//testing only remove afterwards.

public:
	void readData(ifstream& s)
	{	
		string line;
		//while (getline(s, line,':'))
		//{
		//	string tempSrt;
		//	int tempint;
		//	string tempnameSrt;
		//	string tempDescSrt;
		//	if (line == "Item")
		//	{
		//		getline(s, line);
		//		getline(s, tempSrt, ':');
		//		getline(s, tempSrt);
		//		tempItems.push_back(new Item(line, tempSrt));
		//	}
		//	getline(s, tempSrt);
		//	if (line == "Location")
		//	{
		//		tempint = atol(tempSrt.c_str());
		//		getline(s, tempnameSrt,':');
		//		getline(s, tempnameSrt);
		//		getline(s, tempDescSrt, ':');
		//		getline(s, tempDescSrt);
		//		getline(s, tempSrt);
		//		locations.push_back(new Location(tempint,tempnameSrt,tempDescSrt));
		//	}

		while (getline(s, line, ':'))
		{
			string tempSrt;
			int tempint;
			string tempnameStr;
			string tempDescStr;
			string tempItemStr;
			vector<Item*> locationItems;
			vector<string> itemNameString;
			if (line == "Item")
			{
				getline(s, line);
				getline(s, tempSrt, ':');
				getline(s, tempSrt);
				tempItems.push_back(new Item(line, tempSrt));
			}
			getline(s, tempSrt);
			if (line == "Location")
			{
				tempint = atol(tempSrt.c_str());
				getline(s, tempnameStr, ':');
				getline(s, tempnameStr);
				getline(s, tempDescStr, ':');
				getline(s, tempDescStr);
				getline(s, tempItemStr, ':');
				getline(s, tempItemStr);
				string tempItemSubStr = "";
				for (int i = 0; i < tempItemStr.length(); i++)
				{
					if (tempItemStr[i] == ',') {
						itemNameString.push_back(tempItemSubStr);
						tempItemSubStr = "";
					}
					else {
						tempItemSubStr.push_back(tempItemStr[i]);
					}
					
				}
				itemNameString.push_back(tempItemSubStr);
				for (int i = 0; i < itemNameString.size(); i++)
				{
					for (int j = 0; j < tempItems.size(); j++)
					{
						if (itemNameString[i] == tempItems[j]->getName())
						{
							locationItems.push_back(tempItems[j]);
						}
					}
				}
				cout << endl;
				getline(s, tempSrt);
				locations.push_back(new Location(tempint, locationItems, tempnameStr, tempDescStr));
			}
			
		}
		cout << "Item Vector Size:" << tempItems.size()<<endl;
		cout << "Locations vector size:" << locations.size() << endl << endl;
		for (int i = 0; i < tempItems.size(); i++)
		{
			cout << "Item name: " << tempItems[i]->getName() << endl;
			cout << "Item Description: " << tempItems[i]->getDescription() << endl
				<< endl;

		}
		for (int i = 0; i<locations.size(); i++)
		{
			cout << "Location value:" << locations[i]->GetNumber() << endl;
			cout << "Location name:" << locations[i]->GetName() << endl;
			cout << "Location Description:" << locations[i]->GetDescription() << endl;
			cout << "Location Contains Items:" << locations[i]->ListAllItems() << endl;
			cout << "-------------------------------------------------------------------- "<<endl;
		}
		

	}

	bool HasQuit()
	{
		return quit;
	}

	void ExecuteCommand(string input)
	{	
		string verb, noun;
		int spacePos = static_cast<int>(input.find(" "));//not sure why but i need to cast it as a int to avoid some conversion error
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
			cout << "looking around\n";
		}
		if (verb == "take")
		{
			cout << "took : "<< noun<<endl;
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


