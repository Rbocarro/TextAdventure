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
	Location* location;
	vector<Item*> inventory;

	int steps=0;

public:
	bool hasItem(Item* item)
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

	void TakeItem(Item* item)
	{
		inventory.push_back(item);
	}

	bool dropItem(Item* i)
	{
		//to drop an item at the current location; returns
		//true / false to indicate success / failure(because you may not have the item)
	}

	bool openItem(Item* i)
	{
		//to open an item; returns true / false to indicate
		//success / failure(e.g.because the item is not a container, its open method fails
	}

	void setLocation(Location *l)
	{	
		//cout << "Descriptionx:" << l->GetName() << endl;
		location = l;
		//cout << "Descriptionx:"<<location->GetName() << endl;
	}

	void SetRemoveItemAtInventoryIndex(int value)
	{
		inventory.erase(inventory.begin() + value);
	}

	void PrintStatus()
	{
		/*to display the current location, inventory, and number of steps*/
		system("CLS");
		location->print(); cout << endl;
		cout << "Player Inventory Size: " << this->inventory.size() << endl;
		cout << "Player Inventory: " << this->PrintAllItems() << endl;
		

	}

	string PrintAllItems()
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

	vector<Item*> GetInventory()
	{
		return inventory;
	}


	void SetAddItemVectortoInventory(vector<Item*> items)
	{
		inventory.insert(inventory.end(), items.begin(), items.end());
	}
	Location* GetLocation()
	{
		return location;
	}
	void TestFillInventory()
	{
		inventory.push_back(new Item("Sword"));
		inventory.push_back(new Item("Blunt"));
		inventory.push_back(new Item("Purse"));
		inventory.push_back(new Container("gold box", "A golden box",
										std::vector<Item*>{new Item("Rat box")}));
		string baby = "North";
		string asda = "South";
		location->addConnection(baby, new Location(69, std::vector<Item*>{new Item("Beat box")}, "Wales", "asd"));//DEBUG
		location->addConnection(asda, new Location(420, std::vector<Item*>{new Item("Discount box")}, "ASDA supermarket", "asda"));//debug

	}
};
