#pragma once
#include<string>
#include<map>
using std::string;
using std::map;
using std::cout;
using std::endl;
class Location {
private:
	int number;
	string name;
	string description;
	vector<Item*> contents;

	//For each possible direction, the location reached and item required (if any). Required.
	map<string, Location*> connections;
	map<string, Item*> key_items;
public:
	Location(int n, vector<Item*> itemList, string name = "Undefined Name", string description = "Undefined Description" )
	{
		number = n;
		this->name = name;
		this->description = description;
		contents.insert(contents.end(), itemList.begin(), itemList.end());
	}

	int GetNumber()
	{
		return number;
	}
	void SetNumber(int value)
	{
		number = value;
	}

	string GetName()
	{
		return name;
	}

	int GetId()
	{
		return number;
	}

	void SetName(string value)
	{
		name = value;
	}

	string GetDescription()
	{
		return description;
	}

	void SetDescription(string value)
	{
		description = value;
	}

	vector<Item*> GetContents()
	{
		return contents;
	}

	void SetContents(vector<Item*> inputcontents)
	{
		contents = inputcontents;
	}
	void drop_item(Item* item)
	{
		contents.push_back(item);
	}

	void SetremoveItemAtInventoryIndex(int i)
	{
		contents.erase(contents.begin() + i);
	}
	void print()
	{
		cout << "Location Name: " << name<<endl;
		cout << "Location Description:" << description << std::endl;
		cout << "Location Contents Size DEBUG: " <<GetContents().size() << endl;
		cout << "Location Items: " << ListAllItems() << endl;
		cout << "Possible directions:" << ListAllPossibleDirections();



	}

	bool take_item(Item* i)
	{

	}


	Item* getKey(string& direction)
	{

	}

	Location* getConnection(string& direction)
	{

	}
	void addConnection(string& direction, Location* destination)
	{
		connections.insert(std::pair<string, Location*>(direction,destination));
	}

	string ListAllPossibleDirections()
	{
		string output = "";
		map<string, Location*>::iterator it;
		for (it = connections.begin(); it != connections.end(); it++) {
			output.append(it->first); output.append(",");
		}

		return output;
	}

	string ListAllItems()
	{	
		string output="";
		for (int i = 0; i < contents.size(); i++)
		{
			output.append(contents[i]->getName());
			output.append(", ");
		}
		return output;
	}

	void Additem(Item* item)
	{
		contents.push_back(item);
	}


};
