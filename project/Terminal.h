#pragma once
#include<iostream>
#include "Library.h"

class Terminal
{
public:

	void start()
	{
		Library lib; //create library
		int input = -1;

		lib.welcome();
		while (input != 0)
		{
			std::cout << std::endl << "Enter command: ";
			std::cin >> input;
			std::cout << std::endl;

			switch (input)
			{
			case 0:
			{
				lib.exit();
				break;
			}
			case 1:
			{
				std::cout << "---Help--- \n";

				lib.help();
				break;
			}
			case 2:
			{
				std::cout << "---Sign in---\n";

				lib.sign_in();
				break;
			}
			case 3:
			{
				std::cout << "---Sign up---\n";

				lib.sign_up();
				break;
			}
			case 4:
			{
				std::cout << "---Change data---\n";

				lib.change_data();
				break;
			}
			case 5:
			{
				std::cout << "---Save changes---\n";

				lib.save_user_data();
				break;
			}
			case 6:
			{
				std::cout << "---Log out---\n";

				lib.log_out();
				break;
			}
			case 7:
			{
				std::cout << "---Add song---\n";

				lib.add_song();
				break;
			}
			case 8:
			{
				std::cout << "---Rate song---\n";

				lib.rate_song();
				break;
			}
			case 9:
			{
				std::cout << "---Generate playlist---\n";

				lib.generate_playlist();
				break;
			}
			case 10:
			{
				std::cout << "---Set playlist's name---\n";
				lib.save_playlist();
				break;
			}
			case 11:
			{
				std::cout << "---Load playlist---\n";

				lib.load_playlist();
				break;
			}
			case 12:
			{
				std::cout << "---Show all songs' info---\n";

				lib.show_all_info();
				break;
			}
			}
		}

	}
};

