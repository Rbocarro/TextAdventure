#pragma once
#include<string>
#include<vector>
#include"Item.h"
#include"Location.h"
#include "GameManager.h"
using std::string;
using std::vector;

class Player{
private:

	static Location* location;
	static vector<Item*> inventory;
	static int steps;
public:
	static bool hasItem(Item* item)
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

	static bool takeItem(Item* item)
	{
		// to add an item to the inventory; returns true/false to
		//indicate success / failure(because the item may not be here)
		// inventory.push_back(item);?? 
	}

	static bool dropItem(Item* i)
	{
		//to drop an item at the current location; returns
		//true / false to indicate success / failure(because you may not have the item)
	}

	static bool openItem(Item* i)
	{
		//to open an item; returns true / false to indicate
		//success / failure(e.g.because the item is not a container, its open method fails
	}

	static void setLocation(Location* l)
	{
		/*cout << "Location value:" <<l->GetNumber() << endl;
		cout << "Name:" << l->GetName() << endl;
		cout << "Description:" << l->GetDescription() << endl;*/
		
		location = l;
	}
	static void PrintStatus()
	{
		/*to display the current location, inventory, and number of steps*/
		
		cout << "Location value:" << location->GetNumber()<<endl;
		cout << "Name:" << location->GetName() << endl;
		cout << "Description:" << location->GetDescription() << endl;
		

	}
};
