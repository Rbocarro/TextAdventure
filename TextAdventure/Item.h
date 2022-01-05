#pragma once
#include<string>
using std::string;
using std::vector;
class Item {
private:
	string name;//name of item
	string description;//description of item


public:
	Item(string name="Undefined name", string description="Undefined Description")//constructor
	{
		this->SetName(name);
		this->SetDescription(description);
	}
	void SetName(string value)//setter for name
	{
		name = value;
	}
	string getName()//getter for name
	{
		return name;
	}
	void SetDescription(string value)//setter for description
	{
		description = value;
	}
	string getDescription() // getter for descirtption
	{
		return description;
	}

	virtual bool open()//virtual fuction(not used). Overridden in base class method
	{
		return true;
	}

	virtual vector<Item*> GetContents()//virtual fuction(not used). Overridden in base class method
	{
		return vector<Item*>{};
	}

	virtual void SetContentsToEmpty(){}//virtual fuction(not used). Overridden in base class method

};

class Container :public Item
{	
private:
	vector <Item*> contents;//conetents of vector
	Item key_item;//key item neede to open
	bool opened;//boolean if item was opened

public:
	Container(string name,string description, vector <Item*> contents):Item(name,description)//constructor
	{	
		opened = false;
		this->contents = contents;
	}
	bool open()
	{
		return opened;
	}

	vector<Item*> GetContents()//getter for container contents
	{
		return contents;
	}

	void SetContentsToEmpty() // setter for container contents to empty
	{
		contents.clear();
		opened = true;
	}
};

