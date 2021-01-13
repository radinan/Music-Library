#include "Commands.h"
//#include "User.h"
//#include "Library.h"
#include <string>

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
void Commands::sign_in(Library& lib)
{
	std::string un, pw;

	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;
	//validation
	sign_in_helper(lib, un, pw);
}
void Commands::sign_in_helper(Library& lib, const std::string& un, const std::string& pw)
{
	//checks in file
	std::ifstream file("users.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{
			User user;
			file >> user; //load data from file
			if (user.check_username_password(un, pw)) 
			{
				lib.set_user(user); //check?
			}
		}
		//if not found: cout<<"wrong data"; (flag)
		file.close();
	}

}

void Commands::sign_up(Library& lib)
{
	std::string un, pw;  //~~r_pw

	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;
	//~~repeat password
	//validation
	sign_up_helper(lib, un, pw);
}
void Commands::sign_up_helper(Library& lib, const std::string& un, const std::string& pw)
{
	User new_user(un, pw);
	lib.set_user(new_user);
	//no//change in file yet
}

void Commands::change_data(Library& lib)
{
	//may change command to char or string (user may enter 1. not just 1)
	std::string config; //configuration
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
		std::cin >> config;
		//validation
	}
	else if (command == 2)
	{
		//~repeat old
		std::cout << "Enter new password: ";
		std::cin >> config;
		//validation
	}
	else if (command == 3)
	{
		std::cout << "Enter new full name: ";
		std::getline(std::cin, config);
		//validation
	}
	else if (command == 4)
	{
		std::cout << "Enter new birth date: ";
		std::cin >> config;
		//validation
	}
	else if (command == 5) 
	{
		std::cout << "Enter genre you want to add: ";
		std::getline(std::cin, config);
		//validation
	}
	else if (command == 6)
	{
		std::cout << "Enter genre you want to remove: ";
		std::getline(std::cin, config);
		//validation
	}

	//check here for whitespaces(before or after)
	change_data_helper(lib, command, config);
}
void Commands::change_data_helper(Library& lib, int choice, const std::string& config)
{
	//switch case => faster than if else
	switch (choice)
	{
	case 1:
		lib.get_user().set_username(config); break;
	case 2:
		lib.get_user().set_password(config); break;
	case 3:
		lib.get_user().set_full_name(config); break;
	case 4:
		lib.get_user().set_birth_date(config); break;
	case 5:
		lib.get_user().add_fav_genre(config); break;
	case 6:
		lib.get_user().remove_fav_genre(config); break;
	//default?
	}
}

//--song--
void Commands::add_song(Library& lib)
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
	add_song_helper(lib, name, artist, genre, album, release_date);
}
void Commands::add_song_helper(Library& lib, const std::string& name, const std::string& artist, const std::string& genre, const std::string& album, int release_date)
{
	Song song(name, artist, genre, album, release_date);
	lib.add_song(song); //changes the Tree w all songs
}

void Commands::rate_song(Library& lib)
{
	std::string name;
	int rate = 0;
	std::cout << "Enter song: ";
	std::cin >> name;
	std::cout << "Enter rating: ";// 1-6 ? 
	std::cin >> rate;
	//validation
	rate_song_helper(lib, name, rate);
}
void Commands::rate_song_helper(Library& lib, const std::string& name, int rate)
{
	//original all_songs must be always sorted by name!
	lib.get_songs().find(name)->data.set_rating(rate);

}

//--playlist--
void Commands::generate_playlist(Library& lib)
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
	generate_playlist_helper(lib, input);
}
void Commands::generate_playlist_helper(Library& lib, const std::string& input)
{
	//FIX!

	/*Expression expr(input);
	AVLTree playlist = expr.do_expression(lib); //parses the input and creates tree with songs
	playlist.inorder();*/
	//sort by name
	//create DLList and add it to Playlist
}

void Commands::save_playlist(Library& lib)
{
	std::string input;
	std::cout << "Enter new name: ";
	std::cin >> input;
	save_playlist_helper(lib,input);
}
void Commands::save_playlist_helper(Library& lib, const std::string& name)
{
	//ako ima v Library playlist s takova ime
	//vikame loadnitiq 
	//p.change_name(name);
	//ako nqma -> load_playlilst()
}

void Commands::load_playlist(Library& lib)
{
	std::string input;
	std::cout << "Enter name: ";
	std::cin >> input;
	load_playlist_helper(lib, input);
}
void Commands::load_playlist_helper(Library& lib, const std::string& name)
{
	//lib.curr_playlist ?
	//curr_user.playlists ?

	//lib.add_playlist();
	//pl.all_songs_name();
}

void Commands::show_all_info(Library& lib)
{
	lib.get_playlist().all_songs_info();
}
