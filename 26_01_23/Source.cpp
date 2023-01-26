#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Character
{
public:
	virtual void info() = 0;
	virtual ~Character() {}
};


////////////////////////////////
class Woman : public Character
{
public:
	void info()
	{
		cout << "create woman charecter" << endl;
	}
};

class Man : public Character
{
public:
	void info()
	{
		cout << "create man charecter" << endl;
	}
};
////////////////////////////////



////////////////////////////////
class Factory
{
public:
	virtual vector<string> createClothes() = 0;
	virtual vector<string> createShoes() = 0;
	virtual Character* createCharacter() = 0;
	virtual ~Factory() {}
};

class ManFactory : public Factory
{
public:
	Character* createCharacter()
	{
		return new Man;
	}
	/*vector<string> delstr(string line)
	{
		vector<string> s;
		string ln;
		for (char chr : line)
		{
			switch (chr)
			{
			case ',':
				s.push_back(ln);
				ln.clear();
				break;

			case '\n':
				break;

			default:
				ln += chr;
				break;
			}
		}
		s.push_back(line);
		return s;
	}*/

	vector<string> createClothes()
	{
		string line;
		vector<string> str;
		ifstream file("C:\\Users\\Взрослая академия\\Desktop\\одежда.txt");
		if (file.is_open())
		{
			
			while (getline(file,line))
			{
				vector<string> s;
				string ln;
				for (char chr : line)
				{
					switch (chr)
					{
					case ',':
						s.push_back(ln);
						ln.clear();
						break;

					case '\n':
						break;

					default:
						ln += chr;
						break;
					}
				}
				s.push_back(line);
				str.push_back(s[0]);

				vector<string> s;
				string ln;
				for (char chr : line)
				{
					switch (chr)
					{
					case ',':
						s.push_back(ln);
						ln.clear();
						break;

					case '\n':
						break;

					default:
						ln += chr;
						break;
					}
				}
				s.push_back(line);
				str.push_back(s[1]);

			}
		}
		return str;
	}



	vector<string> createShoes()
	{
		string line;
		vector<string> str;
		ifstream file("C:\\Users\\Взрослая академия\\Desktop\\обувь.txt");
		if (file.is_open())
		{
			while (getline(file, line))
			{
				str.push_back(line);
			}
		}
		return str;
	}

};


class WomanFactory : public Factory
{
public:
	Character* createCharacter()
	{
		return new Woman;
	}

	vector<string> createClothes()
	{
		string line;
		vector<string> str;
		ifstream file("C:\\Users\\Взрослая академия\\Desktop\\одежда.txt");
		if (file.is_open())
		{
			int i = 0;
			while (getline(file, line))
			{
				str.push_back(line);
			}
		}
		return str;
	}
	vector<string> createShoes()
	{
		string line;
		vector<string> str;
		ifstream file("C:\\Users\\Взрослая академия\\Desktop\\обувь.txt");
		if (file.is_open())
		{
			while (getline(file, line))
			{
				str.push_back(line);
			}
		}
		return str;
	}

};


////////////////////////////////



int main()
{
	setlocale(LC_ALL, "Russian");
	ManFactory* man1 = new ManFactory;
	vector <Character*> character;
	vector <string> clothes, clothesGen;
	clothes = man1->createClothes();
	clothesGen = man1->createClothesGen();
	for (int i = 0; i < clothes.size(); i++)
	{
		cout << clothes[i] << endl;
	}
	
	character.push_back(man1->createCharacter());
}