#pragma once
#include<string>
#include<vector>
#include"Item.h"
#include"Location.h"
using std::string;
using std::vector;

class Player{
private:

	static Location* location;
	static vector<Item*> inventory;
	static int steps;
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

	bool takeItem(Item* item)
	{
		// to add an item to the inventory; returns true/false to
		//indicate success / failure(because the item may not be here)
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
	void PrintStatus()
	{
		/*to display the current location, inventory, and number of steps*/
	}
};
