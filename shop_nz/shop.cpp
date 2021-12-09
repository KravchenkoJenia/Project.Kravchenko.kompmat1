
#include "shop.h"
#include "Buyer.h"
#include "Seller.h"
#include "Shop_manager.h"

int menu();

int main()
{
	srand(time(0));

	File_checker fcheck;
	int cnt_b;
	int cnt_s; 
	int cnt_m; 

	string bn;
	string bp;
	string sn;
	string sp;
	string mn;
	string mp;

	Product list_b[30];
	Product list_s[30];
	Product list_m[50];

	char buff[25];

	// names
	ifstream f("names.txt");
	f.getline(buff, 24);
	bn = buff;
	f.getline(buff, 24);
	bp = buff;
	f.getline(buff, 24);
	sn = buff;
	f.getline(buff, 24);
	sp = buff;
	f.getline(buff, 24);
	mn = buff;
	f.getline(buff, 24);
	mp = buff;

	Buyer b(bn, bp);
	Seller s(sn, sp);
	Shop_manager m(mn, mp);

	int choice;

	int exit = false;

	while (exit == 0)
	{
		cnt_b = fcheck.buyer();
		cnt_s = fcheck.seller();
		cnt_m = fcheck.manager();

		// BUYER
		ifstream in1("buyer_assortment.txt");

		for (int i = 0; i < cnt_b; i++)
		{
			in1.getline(buff, 24);
			list_b[i].set_name(buff);
		}
		in1.close();
		// === \\


		// SELLER
		ifstream in2("seller_assortment.txt");

		for (int i = 0; i < cnt_s; i++)
		{
			in2.getline(buff, 24);
			list_s[i].set_name(buff);
		}
		in2.close();
		// === \\


		// MANAGER
		ifstream in3("shop_assortment.txt");

		for (int i = 0; i < cnt_m; i++)
		{
			in3.getline(buff, 24);
			list_m[i].set_name(buff);
		}
		in3.close();
		// === \\

		b.set_Product(list_b, cnt_b);
		s.set_Product(list_s, cnt_s);
		m.set_Product(list_m, cnt_m);


		choice = menu();
		if (choice == 1)
		{
			system("cls");

			if (cnt_b >= 29)
			{
				cout << "\n > Vault of buyer if full!\n > Press [Q] to return to menu.";
				int choice_of_usr;
				do
				{
					choice_of_usr = _getch();
				} while (choice_of_usr == 113);
			}
			else if (cnt_s <= 1 || cnt_s <= 2)
			{
				cout << "\n > The seller has no product. Inform the manager!\n > Press [Q] to return to menu.";
				int choice_of_usr;
				choice_of_usr = _getch();
			}
			else if (cnt_s > 1)
			{
				Product list[30];
				Product temp_list[30];
				int j = 0;
				int k = 0;

				ifstream in("seller_assortment.txt");
				if (!in)
				{
					cout << "> Cannot open file!";
				}
				else
				{
					int rand_number = 1 + rand() % cnt_s;
					char buff[25];

					for (int i = 0; i < cnt_s; i++)
					{
						if (i < rand_number)
						{
							in.getline(buff, 24);
							list[j].set_name((string)buff);
							j++;
						}
						else
						{
							in.getline(buff, 24);
							temp_list[k].set_name((string)buff);
							k++;
						}
					}
				}
				in.close();

				fstream out1("buyer_assortment.txt", ios::app);
				if (!out1)
				{
					cout << "> Cannot open file";
				}
				else
				{
					for (int i = 0; i < j; i++)
						out1 << list[i].get_name() << "\n";
				}
				out1.close();

				ofstream out("seller_assortment.txt");
				if (!out)
				{
					cout << "> Cannot open file";
				}
				else
				{
					for (int i = 0; i < cnt_s - j; i++)
					{
						out << temp_list[i].get_name() << "\n";
					}
				}
				out.close();

				cout << "\n > Buyer vault succesfully replenished!";
				cout << "\n > Press [Q] to return to menu.";
				int choice_of_usr1;
				choice_of_usr1 = _getch();
			}
		}
		else if (choice == 2)
		{
			system("cls");

			if (cnt_s >= 29)
			{
				cout << "\n > Vault of seller if full!\n > Press [Q] to return to menu.";
				int choice_of_usr;
				choice_of_usr = _getch();
			}
			else if (cnt_m <= 1 || cnt_m <= 2)
			{
				cout << "\n > The shop vault is empty! Congrats!\n > Press [Q] to return to menu.";
				int choice_of_usr;
				choice_of_usr = _getch();
			}
			else if (cnt_m > 1)
			{
				Product list[30];
				Product temp_list[30];
				int j = 0;
				int k = 0;

				ifstream in("shop_assortment.txt");
				if (!in)
				{
					cout << "> Cannot open file!";
				}
				else
				{
					int rand_number = 1 + rand() % cnt_m;
					char buff[25];

					for (int i = 0; i < cnt_m; i++)
					{
						if (i < rand_number)
						{
							in.getline(buff, 24);
							list[j].set_name((string)buff);
							j++;
						}
						else
						{
							in.getline(buff, 24);
							temp_list[k].set_name((string)buff);
							k++;
						}
					}
				}
				in.close();

				fstream out1("seller_assortment.txt", ios::app);
				if (!out1)
				{
					cout << "> Cannot open file";
				}
				else
				{
					for (int i = 0; i < j; i++)
						out1 << list[i].get_name() << "\n";
				}
				out1.close();

				ofstream out("shop_assortment.txt");
				if (!out)
				{
					cout << "> Cannot open file";
				}
				else
				{
					for (int i = 0; i < cnt_m - j; i++)
						out << temp_list[i].get_name() << "\n";
				}
				out.close();

				cout << "\n > Seller vault succesfully replenished!";
				cout << "\n\n > Press [Q] to return to menu.";
				int choice_of_usr1;
				choice_of_usr1 = _getch();
			}
		}
		else if (choice == 3)
		{
			int exit2 = false;
			int choice_of_usr3;
			while (exit2 == 0)
			{
				system("cls");
				cout << "\n\n> To view buyer vault, press [1] <";
				cout << "\n> To view seller vault, press [2] <";
				cout << "\n> To view shop vault, press [3] <";
				cout << "\n> To return to prev. menu, press [Q] <";

				choice_of_usr3 = _getch();

				if (choice_of_usr3 == 49)
				{
					system("cls");

					cout << "\n\n> ";
					b.show_info(cnt_b);
					cout << "\n\n > Press [Q] to return to menu.";
					int choice_of_usr1;
					choice_of_usr1 = _getch();
				}
				else if (choice_of_usr3 == 50)
				{
					system("cls");

					cout << "\n\n> ";
					s.show_info(cnt_s);
					cout << "\n\n > Press [Q] to return to menu.";
					int choice_of_usr1;
					choice_of_usr1 = _getch();
				}
				else if (choice_of_usr3 == 51)
				{
					system("cls");

					cout << "\n\n> ";
					m.show_info(cnt_m);
					cout << "\n\n > Press [Q] to return to menu.";
					int choice_of_usr1;
					choice_of_usr1 = _getch();
				}
				else if (choice_of_usr3 == 113)
				{
					exit2 = true;
				}
			}

		}
		else if (choice == 4)
		{
			system("cls");
			exit = true;
			return 0;
		}
	}
}