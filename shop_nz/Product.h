#pragma once
#include "shop.h"

class Product
{
private: 

	string name;

public:

	Product()
	{
		name = "/0";
	}
	Product(string name)
	{
		this->name = name;
	}

	void set_name(string name)
	{
		this->name = name;
	}

	string get_name()
	{
		return name;
	}
};

