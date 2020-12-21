#include "TerminalDialog.h"
#include "Commands.h"
#include "Song.h"
//#include "Album"
#include <iostream>

Commands c; //posle shte gi sleq dvata klasa

void TerminalDialog::welcome()
{
	std::cout << "Welcome! Type 'help' for list of all commands." << std::endl;
}
void TerminalDialog::help()
{
	std::cout << "List of all commands: \n"
		<< "1. ..... \n"
		<< "2. ..... \n"
		<< "3. ..... \n";
}

void TerminalDialog::sign_in()
{
	std::string un, pw;

	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;
	//validaciq
	c.sign_in(un, pw);
}
void TerminalDialog::sign_up()
{
	std::string un, pw;  //~~r_pw

	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;
	//~~repeat password
	//validaciq
	c.sign_up(un, pw);
}
void TerminalDialog::change_data()
{

	std::string input;
	int command = 0; //moje i da ne e int
	std::cout <<
		"Choose: \n" <<
		"1. username \n" <<
		"2. password \n" <<
		"3. full name \n" <<
		"4. birth date \n" <<
		"5. add favourite genres \n" <<
		"6. remove favourite genres \n";
	std::cin >> command; 

	if (command == 1)
	{
		std::cout << "Enter new username: ";
		std::cin >> input;
		//validaciq
	}
	else if (command == 2)
	{
		//~potvyrjdavane na starata
		std::cout << "Enter new password: ";
		std::cin >> input;
		//validaciq
	}
	else if (command == 3)
	{
		std::cout << "Enter new full name: ";
		std::cin >> input;
		//validaciq
	}
	else if (command == 4)
	{
		std::cout << "Enter new bith date: ";
		std::cin >> input;
		//validaciq
	}
	else if (command == 5) //dopis
	{
		std::cout << "Enter genre you want to add: ";
		std::cin >> input;
		//validaciq
	}
	else if (command == 6)
	{
		std::cout << "Enter genre you want to remove: ";
		std::cin >> input;
		//validaciq
	}
	
	c.change_data(command, input);
}

void TerminalDialog::add_song()
{
	std::string name, artist, genre,
		album, release_date;
	//preduprejdenie che tr se popylva :DD
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter artist: ";
	std::cin >> artist;
	std::cout << "Enter genre: ";
	std::cin >> genre;
	std::cout << "Enter album: ";
	std::cin >> album;
	std::cout << "Enter release date: ";
	std::cin >> release_date;
	//validaciq
	c.add_song(name, artist, genre, album, release_date);
}
void TerminalDialog::rate_song()
{
	std::string name;
	int rate = 0;
	std::cout << "Enter song: ";
	std::cin >> name;
	std::cout << "Enter rating: ";
	std::cin >> rate;
	//validaciq
	c.rate_song(name, rate);
}

void TerminalDialog::generate_playlist() 
{
	//&& ||
	std::string input;
	std::cout << "Choose criteria (more than 1, with '&&' or '||'): \n" <<
		"1. rating higher than \n" <<
		"2. icluded genres \n" <<
		"3. excluded genres \n" <<
		"4. only favourite genres \n" <<
		"5. before year \n" <<
		"6. from year \n" <<
		"7. after year \n";
	std::getline(std::cin, input);
	c.generate_playlist(input);
}
void TerminalDialog::save_playlist()
{
	std::string input;
	std::cout << "Enter new name: ";
	std::cin >> input;
	c.save_playlist(input);
}

void TerminalDialog::load_playlist()
{
	std::string input;
	std::cout << "Enter name: ";
	std::cin >> input;
	c.load_playlist(input);
}
//void TerminalDialog::show_all_info(); //tuka tr se pomisli
