#include "Commands.h"
#include "User.h"
#include "Library.h"
#include <string>

Library lib;

//--general--
void Commands::welcome()
{
	std::cout << "Welcome! Type 'help' for list of all commands." << std::endl;
}
void Commands::help()
{
	std::cout << "List of all commands: \n"
		<< "1. ..... \n"
		<< "2. ..... \n"
		<< "3. ..... \n";
}

//--user--
void Commands::sign_in()
{
	std::string un, pw;

	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;
	//validation
	sign_in_helper(un, pw);
}
void Commands::sign_in_helper(const std::string& un, const std::string& pw)
{
	//checks in file
	User user;//func load_user() -> set data from file
	lib.add_user(user);
}

void Commands::sign_up()
{
	std::string un, pw;  //~~r_pw

	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;
	//~~repeat password
	//validation
	sign_up_helper(un, pw);
}
void Commands::sign_up_helper(const std::string& un, const std::string& pw)
{
	User new_user(un, pw);
	lib.add_user(new_user);
	//change file
}

void Commands::change_data()
{
	std::string input;
	int command = 0; //may not be int
	std::cout <<
		"Enter number of command: \n" <<
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
		//validation
	}
	else if (command == 2)
	{
		//~repeat old
		std::cout << "Enter new password: ";
		std::cin >> input;
		//validation
	}
	else if (command == 3)
	{
		std::cout << "Enter new full name: ";
		std::getline(std::cin, input);
		//validation
	}
	else if (command == 4)
	{
		std::cout << "Enter new birth date: ";
		std::cin >> input;
		//validation
	}
	else if (command == 5) 
	{
		std::cout << "Enter genre you want to add: ";
		std::getline(std::cin, input);
		//validation
	}
	else if (command == 6)
	{
		std::cout << "Enter genre you want to remove: ";
		std::getline(std::cin, input);
		//validation
	}

	change_data_helper(command, input);
}
void Commands::change_data_helper(int choice, const std::string& input)
{
	Playlist playlist;
	if (choice == 1)
	{
		lib.get_user().set_username(input);
	}
	else if(choice == 2)
	{
		lib.get_user().set_password(input);
	}
	else if (choice == 3)
	{ 
		lib.get_user().set_full_name(input);
	}
	else if (choice == 4)
	{ 
		lib.get_user().set_birth_date(input);
	}
	else if (choice == 5) 
	{
		lib.get_user().add_fav_genre(input);
	}
	else if (choice == 6)
	{
		lib.get_user().remove_fav_genre(input);
	}
}

//--song--
void Commands::add_song()
{
	std::string name, artist, genre,
		album;
	int release_date;
	//many inputs
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
	//validation
	add_song_helper(name, artist, genre, album, release_date);
}
void Commands::add_song_helper(const std::string& name, const std::string& artist, const std::string& genre, const std::string& album, int release_date) 
{
	Song song(name, artist, genre, album, release_date);
	lib.add_song(song); //changes the Tree w all songs
}

void Commands::rate_song()
{
	std::string name;
	int rate = 0;
	std::cout << "Enter song: ";
	std::cin >> name;
	std::cout << "Enter rating: ";
	std::cin >> rate;
	//validation
	rate_song_helper(name, rate);
}
void Commands::rate_song_helper(const std::string& name, int rate)
{
	//finds in tree
	//song.set_rating(rate);
}


//--playlist--
void Commands::generate_playlist()
{
	//&& ||
	std::string input;
	std::cout << "Choose criteria (more than 1, with '&&' or '||'): \n" <<
		"1. rating higher than \n" <<
		"2. included genres \n" <<
		"3. excluded genres \n" <<
		"4. only favourite genres \n" <<
		"5. before year \n" <<
		"6. from year \n" <<
		"7. after year \n";
	std::getline(std::cin, input); // [command] (value) && [command] (value) || [command] (value)
	generate_playlist_helper(input);
}
void Commands::generate_playlist_helper(const std::string& input) 
{
	//f-q koqto da prerabotva inputa (returnva string[])
	//vector ot dvoiki <comanda,value> ->string

	//cikyl za obhojdane na vsichki komandi
	//za 1va komanda vzima ot faila podhodqshti elementi i gi dobavq v array
	//za dr komandi filtrira Tree

	//save_playlist(..) po default "<username>'s playlist"

}

void Commands::save_playlist()
{
	std::string input;
	std::cout << "Enter new name: ";
	std::cin >> input;
	save_playlist_helper(input);
}
void Commands::save_playlist_helper(const std::string& name)
{
	//ako ima v Library playlist s takova ime
	//vikame loadnitiq 
	//p.change_name(name);
	//ako nqma -> load_playlilst()
}

void Commands::load_playlist()
{
	std::string input;
	std::cout << "Enter name: ";
	std::cin >> input;
	load_playlist_helper(input);
}
void Commands::load_playlist_helper(const std::string& name)
{
	//lib.curr_playlist ?
	//curr_user.playlists ?

	//lib.add_playlist();
	//pl.all_songs_name();
}

void Commands::show_all_info()
{
	lib.get_playlist().all_songs_info();
}
