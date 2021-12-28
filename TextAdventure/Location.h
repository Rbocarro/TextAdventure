#pragma once

class Location {
private:
	int number;
	string name;
	string description;
	vector<Item*> contents;
public:
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
