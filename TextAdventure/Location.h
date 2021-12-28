#pragma once

class Location {
private:
	int number;
	string name;
	string description;
	vector<Item*> contents;
public:

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
