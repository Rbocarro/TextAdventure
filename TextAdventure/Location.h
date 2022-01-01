#pragma once
#include<string>
using std::string;
class Location {
private:
	int number;
	string name;
	string description;
	vector<Item*> contents;
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
