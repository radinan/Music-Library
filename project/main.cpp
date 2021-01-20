#include <iostream>
#include <string>
#include "Library.h"



int main()
{
	Library lib;//created library
	int input = -1;
	lib.welcome();
	while(input != 0)
	{
		std::cout << std::endl << "Enter your command: ";
		std::cin >> input;
		std::cout << std::endl;
		switch (input)
		{
		case 0:
		{
			break; 
		}
		case 1:
		{
			lib.help();
			break;
		}
		case 2:
		{
			lib.sign_in();
			break;
		}
		case 3:
		{
			lib.sign_up();
			break;
		}
		case 4:
		{
			lib.change_data();
			break;
		}
		case 5:
		{
			lib.save_user_data();
			break;
		}
		case 6:
		{
			lib.add_song();
			break;
		}
		case 7:
		{
			lib.rate_song();
			break;
		}
		case 8:
		{
			lib.generate_playlist();
			break;
		}
		case 9:
		{
			lib.save_playlist();
			break;
		}
		case 10:
		{
			lib.load_playlist();
			break;
		}
		case 11:
		{
			lib.show_all_info();
			break;
		}
		}
	}


	lib.save_songs();
	std::cout << "END\n";
}
