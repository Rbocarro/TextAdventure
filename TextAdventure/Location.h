#pragma once
#include<string>
class Location {
private:
	int number;
	string name;
	string description;
	vector<Item*> contents;
public:
	Location(int n,string name="Undefined Name",string description= "Undefined Description")
	{
		number = n;
		this->name = name;
		this->description = description;
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
};
