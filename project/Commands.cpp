#include "Commands.h"
//#include "User.h"
//#include "Library.h"
#include <string>
#include <fstream>
#include <stdio.h> //for rename func

//using cin.ignore() before every getline 
//so the input buffer is cleared of any left over new line characters from the previous input

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
			if (user.check_username_password(un, pw)) //correct data case
			{
				lib.set_user(user); 
				file.close();
				std::cout << "You are successfully signed in.\n";
				return;
			}
		}
		file.close();
	}
	std::cout << "Wrong username or password.\n";

}

void Commands::sign_up(Library& lib)
{
	std::string un, pw;  

	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;

	//validation
	sign_up_helper(lib, un, pw);
}
void Commands::sign_up_helper(Library& lib, const std::string& un, const std::string& pw) 
{
	std::ifstream file("users.txt");
	if (file.is_open()) //if username is free
	{
		std::string x;
		while (!file.eof())
		{
			std::getline(file, x);
			if (x == un)
			{
				file.close();
				std::cout << "This username is already taken.\n";
				return;
			}
			else
			{
				for (int i = 0; i < 5; ++i) //skip next 5 lines of data
				{
					std::getline(file, x);
				}
			}
		}
		file.close();
	}
	User new_user(un, pw);
	lib.set_user(new_user);
	save_new_user_helper(lib);
}

void Commands::change_data(Library& lib)
{
	size_t command = 0; //or char
	std::cout <<
		"Enter number of command: \n" <<
		"1. username \n" <<
		"2. password \n" <<
		"3. full name \n" <<
		"4. birth date \n" <<
		"5. add favourite genres \n" <<
		"6. remove favourite genres \n";
	std::cin >> command;

	std::string config; //configuration
	switch (command)
	{
	case 1:
		std::cout << "Enter new username: ";
		std::cin >> config;
		break;
	case 2:
		std::cout << "Enter new password: ";
		std::cin >> config;
		break;
	case 3:
		std::cout << "Enter new full name: ";
		std::cin.ignore(); 
		std::getline(std::cin, config);
		break;
	case 4:
		std::cout << "Enter new birth date: ";
		std::cin >> config;
		break;
	case 5:
		std::cout << "Enter genre you want to add: ";
		std::cin.ignore(); 
		std::getline(std::cin, config);
		break;
	case 6:
		std::cout << "Enter genre you want to remove: ";
		std::cin.ignore(); 
		std::getline(std::cin, config);
		break;
	}
	/*if (command == 1)
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
	}*/

	//check here for whitespaces(before or after)
	change_data_helper(lib, command, config);
}
void Commands::change_data_helper(Library& lib, size_t choice, const std::string& config)
{
	switch (choice)
	{
	case 1:
		save_username_helper(lib, config); //username is used as a unique identificator!
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

//files:
void Commands::save_new_user_helper(Library& lib)
{
	std::ofstream out("users.txt", std::ios::app); //go at the end of the file
	if (!out.is_open())
	{
		std::cout << "Unable to open file.\n";
		return;
	}
	out << lib.get_user();
	out.close();
	std::cout << "You are successfully signed up.\n";
}

void Commands::save_username_helper(Library& lib, const std::string& un)
{
	//read from user.txt -> write to user1.txt (check if x == old_username)
	//delete user.txt
	//rename user1.txt to user.txt
	std::string x;
	std::ifstream in("users.txt");
	if (!in.is_open())
	{
		std::cout << "Unable to open file1\n";
		return;
	}
	std::ofstream out("users1.txt");
	if (!out.is_open())
	{
		std::cout << "Unable to open file2\n";
		return;
	}
	while (!in.eof())
	{
		std::getline(in, x);
		if (x == lib.get_user().get_name())
		{
			out << un << "\n";
		}
		else
			out << x << "\n"; //does it get the "\n" ? check!!
	}
	in.close();
	out.close();
	remove("users.txt");
	std::rename("users1.txt", "users.txt"); //to remove warning: if(.. == NULL) return;
	std::cout << "Username is successfully changed.\n";
}

void Commands::save_user_data(Library& lib) //not for username!
{
	std::cout << "Saving all changes. Please, don't close the window\n";
	save_user_data_helper(lib);
}
void Commands::save_user_data_helper(Library& lib)
{
	//read from user.txt -> write to user1.txt 
	//delete user.txt
	//rename user1.txt to user.txt
	std::string x;
	std::ifstream in("users.txt");
	if (!in.is_open())
	{
		std::cout << "Unable to open file1\n";
		return;
	}
	std::ofstream out("users1.txt");
	if (!out.is_open())
	{
		std::cout << "Unable to open file2\n";
		return;
	}
	while (!in.eof())
	{
		std::getline(in, x);
		if (x == lib.get_user().get_name()) //found the user we want to update
		{
			out << lib.get_user();
			for (int i = 0; i < 5; ++i) //6 new lines of data, but the first is already read 
			{
				std::getline(in, x);
			}
		}
		else
		{
			out << x <<"\n"; 
		}
	}
	in.close();
	out.close();
	remove("users.txt");
	std::rename("users1.txt", "users.txt"); //to remove warning: if(.. == NULL) return;
	std::cout << "Successfully saved.\n";
}


//--song-- 
void Commands::add_song(Library& lib)
{
	std::string name, artist, genre,
		album;
	size_t release_year;
	//many inputs

	std::cout << "Enter name: ";
	std::getline(std::cin, name);

	std::cout << "Enter artist: ";
	//std::cin.ignore();
	std::getline(std::cin, artist);

	std::cout << "Enter genre: ";
	//std::cin.ignore();
	std::getline(std::cin, genre);

	std::cout << "Enter album: ";
	//std::cin.ignore();
	std::getline(std::cin, album);

	std::cout << "Enter release date: ";
	std::cin >> release_year;
	//validation
	add_song_helper(lib, name, artist, genre, album, release_year);
}
void Commands::add_song_helper(Library& lib, const std::string& name, const std::string& artist, const std::string& genre, 
	const std::string& album, size_t release_year)
{
	Song song(name, artist, genre, album, release_year);
	//possible check here if it's successfully constructed
	//yes =>
	lib.add_song(song); //changes the Tree w all songs
	std::cout << "Song is successfully added.\n";// to the library.\n";
	//no =>
	//std::cout<<"Please enter correct data!\n";
}

void Commands::rate_song(Library& lib)
{
	std::string name;
	size_t rate = 0;

	std::cout << "Enter song: ";
	std::cin.ignore();
	std::getline(std::cin, name);

	std::cout << "Enter rating(1-6): ";// 1-6 ? 
	std::cin >> rate;
	//validation
	rate_song_helper(lib, name, rate);
}
void Commands::rate_song_helper(Library& lib, const std::string& name, size_t rate)
{
	//original all_songs is always sorted by name!
	lib.get_songs().find(name)->data.set_rating(rate);
}

void Commands::save_songs(Library& lib)
{
	std::ofstream file("songs.txt", std::ios::trunc); //delete and replace old content with the new data
	if (!file.is_open())
	{
		std::cout << "Unable to update file.\n";
		return;
	}
	lib.get_songs().save_to_file(file);
}

//--playlist--//only with correct data for now!!!
void Commands::generate_playlist(Library& lib) // .... & ... | ...
{
	//&& ||
	std::string input;
	std::cout << "Choose criteria (more than 1, separated with '&' or '|'): \n" <<
		"1. rating > ... \n" <<
		"2. genre + ... \n" <<
		"3. genre - ... \n" <<
		"4. genre ! \n" <<
		"5. year > \n" <<
		"6. year = \n" <<
		"7. year < \n";

	//std::cin.ignore();
	std::getline(std::cin, input); // [command] (value) & [command] (value) | [command] (value)
	generate_playlist_helper(lib, input);
}
void Commands::generate_playlist_helper(Library& lib, const std::string& input)  //
{
	Expression expr(input);
	AVLTree main(lib.get_songs());
	expr.do_expression(lib, main); //parses the input and creates tree with songs
	//main.inorder(); //to check if it works -> it does ;)

	Song::priority = Priority::name; 
	AVLTree alph(main); //sorted playlist in alphabetical order

	std::list<std::string> list; //empty
	alph.insert_to_list(list);	 //fill with songs' names
	Playlist playlist;			 //creating playlist
	playlist.set_songs(list);   
	lib.set_playlist(playlist); //setting it in the library (auto setting to the curr_user)
	
	save_playlist(lib);
}

void Commands::save_playlist(Library& lib)
{
	std::string input;
	std::cout << "Enter playlist's name: ";
	std::cin >> input;
	save_playlist_helper(lib,input);
}
void Commands::save_playlist_helper(Library& lib, const std::string& name) //fix to be changed in user also(aka check references)
{
	if (lib.is_loaded()) //if it's loaded in library
	{
		std::string old_name = lib.get_playlist().get_name();
		lib.get_user().get_playlist(old_name).set_name(name); //changes name in curr_user
		lib.get_playlist().set_name(name);
	}
	else
		std::cout << "No playlist loaded.\n";
}

void Commands::load_playlist(Library& lib)
{
	std::string input;
	std::cout << "Enter name: ";
	std::cin >> input;
	load_playlist_helper(lib, input);
}
void Commands::load_playlist_helper(Library& lib, const std::string& name) //to work, must fix load-func first
{
	if (!lib.check_playlist(name)) //checks if it's not already loaded
	{
		if (lib.get_user().is_playlist(name)) //seaarch in current user's playlist for name
		{
			lib.set_playlist(lib.get_user().get_playlist(name)); //if found -> add it to lib.curr_playlist
		}
		else
			std::cout << "No playlist found.\n";
	}
	else
		std::cout << "Playlist " << name << " is already loaded.";
}

void Commands::show_all_info(Library& lib)
{
	lib.all_songs_info();
}
