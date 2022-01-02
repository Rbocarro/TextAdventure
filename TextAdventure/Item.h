#pragma once
#include<string>
using std::string;
using std::vector;
class Item {
private:
	string name;
	string description;


public:
	Item(string name="Undefined name", string description="Undefined Description")
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

	virtual bool open()
	{
		return true;
	}

	virtual vector<Item*> GetContents()
	{
		return vector<Item*>{};
	}

	virtual void SetContentsToEmpty(){}

};

class Container :public Item
{	
private:
	vector <Item*> contents;
	Item key_item;
	bool opened;

public:
	Container(string name,string description, vector <Item*> contents):Item(name,description)
	{	
		opened = false;
		this->contents = contents;
	}
	bool open()
	{
		return opened;
	}

	vector<Item*> GetContents()
	{
		return contents;
	}

	void SetContentsToEmpty()
	{
		contents.clear();
		opened = true;
	}
};

