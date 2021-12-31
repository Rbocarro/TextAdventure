#pragma once
#include <string>
using std::vector;
class Item {
private:
	string name;
	string description;


public:
	Item(string name, string description)
	{
		this->SetName(name);
		this->SetDescription(description);
	}
	void SetName(string value)
	{
		name = value;
	}
	string getName()
	{
		return name;
	}
	void SetDescription(string value)
	{
		description = value;
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

