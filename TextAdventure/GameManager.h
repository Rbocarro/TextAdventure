#pragma once
#include<fstream>
#include<algorithm>
#include<map>
#include"Location.h"
#include"Item.h"//testing only remove afterwards.
#include"Player.h"
using std::ifstream;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::ios;
using std::map;

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
	Player player;

public:

	void readData(ifstream& s)
	{	
		string line;
//		while (getline(s, line, ':'))
//		{
//#pragma region Variables
//			string tempSrt;
//			int tempint;
//			string tempnameStr;
//			string tempDescStr;
//			string tempItemStr;
//			vector<Item*> locationItems;
//			vector<string> itemNameString;
//			string locationDirectionDEBUG;
//			vector<string> locationDirectionVector;
//#pragma endregion
//
//
//			if (line == "Item")
//			{
//				getline(s, line);
//				getline(s, tempSrt, ':');
//				getline(s, tempSrt);
//				tempItems.push_back(new Item(line, tempSrt));
//			}
//			getline(s, tempSrt);
//			if (line == "Location")
//			{
//				tempint = atol(tempSrt.c_str());
//				getline(s, tempnameStr, ':');
//				getline(s, tempnameStr);
//				getline(s, tempDescStr, ':');
//				getline(s, tempDescStr);
//				getline(s, tempItemStr, ':');
//				getline(s, tempItemStr);
//				string tempItemSubStr = "";
//				for (int i = 0; i < tempItemStr.length(); i++)
//				{
//					if (tempItemStr[i] == ',') {
//						itemNameString.push_back(tempItemSubStr);
//						tempItemSubStr = "";
//					}
//					else {
//						tempItemSubStr.push_back(tempItemStr[i]);
//					}
//					
//				}
//				itemNameString.push_back(tempItemSubStr);
//				for (int i = 0; i < itemNameString.size(); i++)
//				{
//					for (int j = 0; j < tempItems.size(); j++)
//					{
//						if (itemNameString[i] == tempItems[j]->getName())
//						{
//							locationItems.push_back(tempItems[j]);
//						}
//					}
//				}
//				cout << endl;
//				getline(s, tempSrt);
//				locations.push_back(new Location(tempint, locationItems, tempnameStr, tempDescStr));
//			}
//			
//		}


		while (getline(s, line, ':'))
		{
#pragma region Variables
			string tempSrt;
			int tempint;
			string tempnameStr;
			string tempDescStr;
			string tempItemStr;
			vector<Item*> locationItems;
			vector<string> itemNameString;
			string locationDirectionDEBUG;
			vector<string> locationDirectionVector;
#pragma endregion


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
				getline(s, locationDirectionDEBUG);
				getline(s, tempSrt);//NUll termination waht????

				for (int i=0;i<3; i++)
				{	
					
					//cout << "Dir" << locationDirectionDEBUG << endl;
					locationDirectionVector.push_back(locationDirectionDEBUG);
					
					
					if (i < 2)//number of lines - 1
					{	
						
						getline(s, locationDirectionDEBUG);
					}
					
				}
				
				cout << "Debugldlr lnght:" << locationDirectionVector.size() << endl;
				cout << "Debugldlr vect conatins:";
				for (int i = 0; i < locationDirectionVector.size(); i++)
				{
					cout << locationDirectionVector[i] << ",";
				}cout << endl;
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
		
		//cout << "Verb:" << verb<<"\n";
		//cout << "Noun:" << noun << "\n";
		
		if (verb == "quit")
		{
			quit = true;
		}
		if (verb == "look")
		{
			player.PrintStatus();
		}
		if (verb == "take")
		{
			for (int i = 0; i < player.GetLocation()->GetContents().size(); i++)
			{
				if (to_lower(player.GetLocation()->GetContents()[i]->getName()) == noun)
				{
					player.TakeItem(player.GetLocation()->GetContents()[i]);
					player.GetLocation()->SetremoveItemAtInventoryIndex(i);
				}
			}
		}
		if (verb == "drop")
		{	
			for (int i = 0; i < player.GetInventory().size(); i++)
			{
				if (to_lower(player.GetInventory()[i]->getName()) == noun)
				{	
					player.GetLocation()->drop_item(player.GetInventory()[i]);
					cout << "Dropped " << noun << " at " << player.GetLocation()->GetName() << endl;
					player.SetRemoveItemAtInventoryIndex(i);
					break;
				}
				else if(i== player.GetInventory().size()-1)
				{
					cout << "Dont have a " << noun << " in your pockets" << endl;
				}
			}
		}

		if (verb=="open")
		{
			for (int i = 0; i < player.GetInventory().size(); i++)
			{
				if (to_lower(player.GetInventory()[i]->getName()) == noun&&
					player.GetInventory()[i]->open()==false)
				{	
					player.SetAddItemVectortoInventory(player.GetInventory()[i]->GetContents());
					player.GetInventory()[i]->SetContentsToEmpty();
					cout << "opened " << noun<<" and recived a "<<player.GetInventory()[i+1]->getName() << endl;
					break;
				}
				else if (i == player.GetInventory().size() - 1)
				{
					cout << "Cannot open " << noun << endl;
				}
			}
		}

		if (verb == "northy")//debug
		{
			player.setLocation( getOrCreateLocation(2));
		}
		if (verb == "southy")//debug
		{
			player.setLocation(getOrCreateLocation(1));
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

	void InitialisePlayerWithLocation(int value)
	{	
		//player = new Player();
		player.setLocation(getOrCreateLocation(value));
		player.TestFillInventory();//test fill the inventory .remove afterwards
		player.PrintStatus();
	}

};


