#include "Library.h"
#include <iostream>
#include <string>

void Library::help()
{
	std::cout << "List of all commands:" << std::endl;
	//da se dopishat komandite
}

void Library::sign_in()
{
	std::string un, pw;
	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;

	//proverqva un/pw na vs zapisani user-i
}

void Library::sign_up()
{
	std::string un, pw, pw1;
	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;
	std::cout << "Repeat password: ";
	std::cin >> pw1;

	// user correct? pw == pw1?
	// user constructor
	// dobavq go v library-to ni
}

void Library::change_data()
{
	int choice = change_data_options(); //izkarvam cout-ovete v dr f-q
	if (choice == 1)
	{
		//vika setter 
	}
	else if (choice == 2)
	{
		//vika setter
	}
	else if (choice == 3)
	{
		//vika setter
	}
	else if (choice == 4)
	{
		//vika setter
	}
}
int Library::change_data_options()
{
	std::cout << "Choose option: " << "\n"
		<< "1. full name" << "\n"
		<< "2. birth date" << "\n"
		<< "3. fav genres" << "\n";
	int option;
	std::cin >> option;

	if (option == 3)
	{
		std::cout << "Choose between: " << "\n"
			<< "1. add" << "\n"
			<< "2. remove" << "\n";
		int option1;
		std::cin >> option1;
		if (option1 == 1)
		{
			return 3;
		}
		else if (option1 == 2)
		{
			return 4;
		}
		else std::cout << "Wrong" << "\n";
	}
	else return option;

}

void Library::add_song()
{
	//vyvejdame vs elementi za Song
	//validaciq
	//vikame konstruktora na Song (koito vika setteri!)
	//dobavqme kym Libraryto ni
}

void Library::rate_song()
{
	std::cout << "Enter the song's name: ";
	std::string sname;
	std::cin >> sname;
	//proverqva ima li Song sys "sname" v Library-to
	std::cout << "Enter the rating: ";
	int rate = 0;
	std::cin >> rate;
	//vika setter za rate
}

void Library::generate_playlist()
{
	int choice = generate_playlist_choice();
	//v zavisimost ot izbora vika f-ii ot Playlist
}
int Library::generate_playlist_choice() //po-skoro da e char* i pri vseki izbor da se dobavq
{ // chislo kym masiva; generate_playlist shte chete i izpylnqva dokato ima simvoli
	std::cout << "Choose a criteria: " << "\n";
		/*
		Rating >
		included genres
		excluded genres
		only fav genres
		from year
		before year
		after year
		*/
	//cin
	//return 
	
}

void Library::save_playlist()
{
	//za "loaded" playlist-a
	//ako nqma -> load()
	std::cout << "Save playlist under name: ";
	std::string p_name;
	std::cin >> p_name;
	//vika setter
}

void Library::load_playlist()
{
	std::cout << "Enter name of playlist: ";
	std::string p_name;
	std::cin >> p_name;
	//set loaded s p_name
}

//void change_playlists_name();

void Library::show_info_for_all_songs()
{
	//proverqva koi e loadnatiqt playlist
	//vika playlist.info
	//koito vika song.info
}

