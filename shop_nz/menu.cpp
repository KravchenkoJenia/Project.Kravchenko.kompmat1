#include "shop.h"
#include "Buyer.h"
#include "Seller.h"
#include "Shop_manager.h"






int menu()
{
	system("cls");
	cout << "\n\t\t\t> Welcome to shop <\n";
	cout << "> To become buyer and buy random count of products, press [1] <\n";
	cout << "> To become manager and buy random count of products to vault, press [2] <\n";
	cout << "> To view info about shop, press [3] <\n";
	cout << "> To exit, press [Q] <";

	int choice_of_usr;
	
	while (true)
	{
		choice_of_usr = _getch();

		if (choice_of_usr == 49)
		{
			return 1;
		}
		else if (choice_of_usr == 50)
		{
			return 2;
		}
		else if (choice_of_usr == 51)
		{
			return 3;
		}
		else if (choice_of_usr == 113)
		{
			return 4;
		}
	}
}

