#pragma once
#include<string>
#include<map>
using std::string;
class Location {
private:
	int number;
	string name;
	string description;
	vector<Item*> contents;

	// For each possible direction, the location reached and item required (if any). Required.
	//map<string, Location*> connections;
	//map<string, Item*> key_items;
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
	void SetAddSpecificItemToContents(Item* item)
	{
		contents.push_back(item);
	}

	void SetremoveItemAtInventoryIndex(int i)
	{
		contents.erase(contents.begin() + i);
	}
	void print()
	{
		std::cout << description<<std::endl;

	}

	bool take_item(Item* i)
	{

	}
	void drop_item(Item* i)
	{

	}

	Item* getKey(string& direction)
	{

	}

	Location* getConnection(string& direction)
	{

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
