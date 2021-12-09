#include "shop.h"
#include "File_checker.h"



int File_checker::buyer()
{
	ifstream in("buyer_assortment.txt");
	if (!in)
	{
		cout << "> Cannot open file!";
		return 666;
	}
	else
	{
		int j = 0;
		string str;
		while (getline(in, str))
		{
			j++;
		}
		in.close();
		return j;
	}
}

int File_checker::seller()
{
	ifstream in("seller_assortment.txt");
	if (!in)
	{
		cout << "> Cannot open file!";
		return 666;
	}
	else
	{
		int j = 0;
		string str;
		while (getline(in, str))
		{
			j++;
		}
		in.close();
		return j;
	}
}

int File_checker::manager()
{
	ifstream in("shop_assortment.txt");
	if (!in)
	{
		cout << "> Cannot open file!";
		return 666;
	}
	else
	{
		int j = 0;
		string str;
		while (getline(in, str))
		{
			j++;
		}
		in.close();
		return j;
	}
}
