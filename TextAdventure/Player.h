#pragma once
#include<string>
#include<vector>
#include"Item.h"
#include"Location.h"
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Player{
private:
	Location* location;//the current location of the player
	vector<Item*> inventory;//vector of the player's inventory

	int steps=0;//number of steps taken

public:
	bool hasItem(Item* item)//return true if player has item;
	{
		//go through players inventory to find item
		for (int i = 0; i < inventory.size(); i++)
		{
			if (inventory[i] == item)
			{
				return true;
			}
		}
		return false;

	}

	bool TakeItem(Item* item)//add item to inventory
	{
		inventory.push_back(item);
		return true;
	}

	bool dropItem(Item* i)//add item to current location contents
	{
		location->GetContents().push_back(i);
		return true;
	}

	bool openItem(Item* i)//open conatiner type items
	{
		i->open();
		return true;
	}

	void setLocation(Location *l)//set player location
	{	
		location = l;
	}

	void SetRemoveItemAtInventoryIndex(int value)//remove item a t specified index
	{
		inventory.erase(inventory.begin() + value);
	}

	void PrintStatus()//print player status
	{
		/*to display the current location, inventory, and number of steps*/
		//system("CLS");
		location->print(); cout << endl;
		cout << "Steps Taken:" << steps << endl;
		cout << "Player Inventory: " << this->PrintAllItems() << endl;
		

	}
	

	string PrintAllItems()//renturn string of all items;
	{
		string output="Nothing in ya pockets";
		for (int i = 0; i < inventory.size(); i++)
		{	
			if (i == 0)
			{
				output = "";
			}
			output.append(inventory[i]->getName());
			output.append(", ");
		}
		return output;
		
	}

	vector<Item*> GetInventory()//get player inventory
	{
		return inventory;
	}


	void SetAddItemVectortoInventory(vector<Item*> items)// add vector of items to inventory
	{
		inventory.insert(inventory.end(), items.begin(), items.end());
	}
	Location* GetLocation()//get player location
	{
		return location;
	}
	void TestFillInventory()
	{
		inventory.push_back(new Item("Sword"));
		inventory.push_back(new Item("Purse"));
		inventory.push_back(new Container("gold box", "A golden box",
										std::vector<Item*>{new Item("Gold Ring")}));
		//string foo = "North";
		//string bar = "South";
		//location->addConnection(foo, new Location(7, std::vector<Item*>{new Item("Silver box")}, "Wales", "asd"));//DEBUG
		//location->addConnection(bar, new Location(8, std::vector<Item*>{new Item("Discount box")}, "ASDA supermarket", "asda"));//debug

	}
};
