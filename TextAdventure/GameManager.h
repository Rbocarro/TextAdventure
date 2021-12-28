#pragma once
#include<fstream>
using std::ifstream;
using std::cout;
using std::getline;
using std::string;
class GameManager 
{
private:
	bool running = true;

public:
	void readData(ifstream& s)
	{	
		string line;
		if (s.is_open())
		{
			while (getline(s, line))
			{
				cout << line << '\n';
			}
			s.close();
		}
	}

};
