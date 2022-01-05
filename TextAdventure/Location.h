#pragma once
#include<string>
#include<map>
using std::string;
using std::map;
using std::cout;
using std::endl;
class Location {
private:
	int number;		//location number
	string name;	//location name
	string description;//location description
	vector<Item*> contents;//location contents

	
	map<string, Location*> connections;//map of the directions string with the location
	map<string, Item*> key_items;//map of the direction with the key item required
public:
	Location(int n, vector<Item*> itemList, map<string, Location*> InputDirectionLocationMap, string name = "Undefined Name", string description = "Undefined Description" )//constructor
	{
		number = n;
		this->name = name;
		this->description = description;
		contents.insert(contents.end(), itemList.begin(), itemList.end());

		map<string, Location*>::iterator it;
		for (it = InputDirectionLocationMap.begin(); it != InputDirectionLocationMap.end(); it++) {
			addConnection(it->first, new Location(69, std::vector<Item*>{new Item("Gold box")}, "Abandonned Workshop", "An old abandonned workshop"));
		}

	}

	Location(int n, vector<Item*> itemList, string name = "Undefined Name", string description = "Undefined Description")//overlloaded constrcutor
	{
		number = n;
		this->name = name;
		this->description = description;
		contents.insert(contents.end(), itemList.begin(), itemList.end());

	}

	int GetNumber()//getter for location number
	{
		return number;
	}
	void SetNumber(int value)//setter for location number
	{
		number = value;
	}

	string GetName()//getter for location name
	{
		return name;
	}

	int GetId()//getter for location id
	{
		return number;
	}

	void SetName(string value)//setter for location name
	{
		name = value;
	}

	string GetDescription()//getter for location name
	{
		return description;
	}

	void SetDescription(string value)//setter for location description
	{
		description = value;
	}

	vector<Item*> GetContents()//getter for location contents
	{
		return contents;
	}

	void SetContents(vector<Item*> inputcontents)//setter for location contents
	{
		contents = inputcontents;
	}
	void drop_item(Item* item)//add items to location contents
	{
		contents.push_back(item);
	}

	void SetremoveItemAtInventoryIndex(int i)//remove item from spcefic location contents
	{
		contents.erase(contents.begin() + i);
	}
	void print()//print location status
	{
		cout << "Location Name: " << name<<endl;
		cout << "Location Description:" << description << std::endl;
		cout << "Location Items: " << ListAllItems() << endl;
		cout << "Possible directions:" << ListAllPossibleDirections();
	}

	bool take_item(Item* i)//add item to contents
	{
		contents.push_back(i);
	}


	Item* getKey(string& direction)
	{

	}

	Location* getConnection(string& direction)//get connection from string
	{	
		map<string, Location*>::iterator it;
		for (it = connections.begin(); it != connections.end(); it++) {
			if (it->first == direction)
			{
				return it->second;
			}
			
		}
	}
	void addConnection(string direction, Location* destination)//add connection
	{
		connections.insert(std::pair<string, Location*>(direction,destination));
	}

	string ListAllPossibleDirections()//get sring fo all directions
	{
		string output = "";
		map<string, Location*>::iterator it;
		for (it = connections.begin(); it != connections.end(); it++) {
			output.append(it->first); output.append(",");
		}

		return output;
	}

	string ListAllItems()//list all possible items
	{	
		string output="";
		for (int i = 0; i < contents.size(); i++)
		{
			output.append(contents[i]->getName());
			output.append(", ");
		}
		return output;
	}

	void Additem(Item* item)//add item to contents
	{
		contents.push_back(item);
	}


};
