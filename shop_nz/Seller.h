#pragma once
#include "shop.h"
#include "Human.h"
#include "Product.h"

class Seller : public Human
{
private:

	int cnt_sold;

public:

	Seller() : Human()
	{
		cnt_sold = 0;
	}
	
	Seller(string name, string position) : Human(name, position)
	{
		this->cnt_sold = 0;
	}

	void set_cnt(int cnt)
	{
		this->cnt_sold = cnt;
	}
};