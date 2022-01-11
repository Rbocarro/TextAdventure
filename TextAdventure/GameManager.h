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
	bool quit = false;						//has the player quit the game. set to false at start
	vector<Location*> locations;			//vector conatinting player locations
	vector<Item*> Items;					//vector containing items read from parsed file which is then placed into locatiion
	map<string, Location*> DirectionLocMap;	//map containg string with corresponding direction
	Player player;							//the player object
	vector<string> directionStrings;		//string vector to temprrarioly store direction strings, north south, etc
	

public:

	void readData(ifstream& s)//read from parsed file data
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
			vector<string> locationDirectionVector;
			string locationDirectionDEBUG;
#pragma endregion
			if (line == "Item")//check if next few lines are for items
			{
				getline(s, line);
				getline(s, tempSrt, ':');
				getline(s, tempSrt);
				Items.push_back(new Item(line, tempSrt));
			}
			getline(s, tempSrt);
			if (line == "Location")//check if next few lines are for locations
			{
				tempint = atol(tempSrt.c_str());
				getline(s, tempnameStr, ':');
				getline(s, tempnameStr);
				getline(s, tempDescStr, ':');
				getline(s, tempDescStr);
				getline(s, tempItemStr, ':');
				getline(s, tempItemStr);
				getline(s, locationDirectionDEBUG);
				for (int i=0;i<2; i++)
				{	
					locationDirectionVector.push_back(locationDirectionDEBUG);
					if (i < 1)//number of lines - 1
						getline(s, locationDirectionDEBUG);
					
				}
				
			 // cout << "Debugldlr lnght:" << locationDirectionVector.size() << endl;
				//cout << "Debugldlr vect conatins:";
				//for (int i = 0; i < locationDirectionVector.size(); i++)
				//{
				//	cout << locationDirectionVector[i] << ",";
				//}cout << endl;


				for (int i = 0; i < locationDirectionVector.size(); i++)		
				{
					/*DirectionLocMap.insert(std::pair<string, Location*>(locationDirectionVector[i].substr(0, locationDirectionVector[i].find(" ")),
						getOrCreateLocation(atoi(locationDirectionVector[i].substr(locationDirectionVector[i].find(" ")+1).c_str()
						) - 1)));*/
					/*directionStrings.push_back(locationDirectionVector[i].substr(0, locationDirectionVector[i].find(" ")));
					DirectionLocMap.insert(std::pair<string, Location*>(locationDirectionVector[i].substr(0, locationDirectionVector[i].find(" ")),
						getOrCreateLocation(1)));*/

					//cout << locationDirectionVector[i].substr(locationDirectionVector[i].find(" ") + 1) << endl;
				}


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
					for (int j = 0; j < Items.size(); j++)
					{
						if (itemNameString[i] == Items[j]->getName())
						{
							locationItems.push_back(Items[j]);
						}
					}
				}
				getline(s, tempSrt);
				locations.push_back(new Location(tempint, locationItems,DirectionLocMap, tempnameStr, tempDescStr));
				DirectionLocMap.clear();

				
				
			}
			
			
		}
		
		


		cout << "Item Vector Size:" << Items.size()<<endl;
		cout << "Locations vector size:" << locations.size() << endl << endl;
		/*for (int i = 0; i < Items.size(); i++)
		{
			cout << "Item name: " << Items[i]->getName() << endl;
			cout << "Item Description: " << Items[i]->getDescription() << endl
				<< endl;

		}
		for (int i = 0; i<locations.size(); i++)
		{
			cout << "Location value:" << locations[i]->GetNumber() << endl;
			cout << "Location name:" << locations[i]->GetName() << endl;
			cout << "Location Description:" << locations[i]->GetDescription() << endl;
			cout << "Location Contains Items:" << locations[i]->ListAllItems() << endl;
			cout << "-------------------------------------------------------------------- "<<endl;
		}*/
		

	}

	bool HasQuit()							//return  quit status of player
	{
		return quit;
	}

	void ExecuteCommand(string input)	//takes in user input and breaks into noun and verb
	{	
		string verb, noun;
		int spacePos = static_cast<int>(input.find(" "));//need to cast it as a int to avoid some conversion error
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

		if (verb == "north")//debug
		{
			player.setLocation( getOrCreateLocation(1));
		}
		if (verb == "south")//debug
		{
			player.setLocation(getOrCreateLocation(0));
		}

		if (VerbDirectionisamongParsedDirection(verb))
		{
			cout << "verb exists among direction" << endl;
		}
	}

	
	Location* getOrCreateLocation(int id) //retruns parsed location
	{
		if (locations[id] == nullptr)
		{
			cout << "Cannot Initialise location" << endl;
		}
		return locations[id];
	}

	void InitialisePlayerWithLocation(int value)//intialise player
	{	
		player.setLocation(getOrCreateLocation(value));
		player.TestFillInventory();//Fill player  inventory 
		player.PrintStatus();
	}
	bool VerbDirectionisamongParsedDirection(string verb)//DEBUG
	{
		for (int i = 0;  i < directionStrings.size(); i++)
		{
			if (to_lower(directionStrings[i]) == verb)
			{
				return true;
			}
		}
		return false;
	}
};


