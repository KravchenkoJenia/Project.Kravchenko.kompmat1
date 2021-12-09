#pragma once
#include "shop.h"
#include "Human.h"
#include "Product.h"

class Shop_manager : public Human
{
public:

	Shop_manager () : Human()
	{
		
	}

	Shop_manager(string name, string position) : Human(name, position)
	{

	}

};