#pragma once
#include "shop.h"
#include "Human.h"
#include "Product.h"

class Buyer : public Human
{
private:

	int cnt_bought;

public:

	Buyer() : Human()
	{
		cnt_bought = 0;
	}

	Buyer(string name, string position) : Human(name, position)
	{
		this->cnt_bought = 0;
	}

	void set_cnt(int cnt)
	{
		this->cnt_bought = cnt;
	}
};