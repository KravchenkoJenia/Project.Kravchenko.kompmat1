#pragma once
#include "shop.h"
#include "Product.h"

class Human
{
protected:

	string name;
	string position;
	Product list[50];
	
public:

	Human()
	{
		name = "/0";
		position = "/0";
		for (int i = 0; i < 20; i++)
		{
			list[i].set_name("/0");
		}
	}

	Human(string name, string position)
	{
		this->name = name;
		this->position = position;
	}

	void show_info(int cnt) 
	{
		cout << "Name: " << name;
		cout << "\n> Position: " << position;
		cout << "\n> List of products: \n";
		for (int i = 0; i < cnt; i++)
		{
			cout << "> " << list[i].get_name() << "\n";
		}
	}
	
	string get_name()
	{
		return name;
	}

	string get_position()
	{
		return position;
	}

	void set_Product(Product* list, int cnt)
	{
		for (int i = 0; i < cnt; i++)
			this->list[i].set_name(list[i].get_name());
	}
};