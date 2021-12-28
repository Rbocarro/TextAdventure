#pragma once
#include <string>
using std::string;
using std::vector;
class Item {
private:
	string name;
	string description;


public:

	string getName()
	{
		return name;
	}
	string getDescription()
	{
		return description;
	}

};

class Container :public Item
{	
private:
	vector <Item*> contents;
	Item key_item;
	bool opened;

public:
	bool open()
	{

	}
};

