#include "Library.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>

Library::Library() 
{
	//loads all song data to the file
	std::ifstream file ("songs.txt"); // opens file "songs"
	if (file.is_open())
	{
		while(!file.eof())
		{
			char c = file.peek();
			if (c >= 32) //is whitespace
			{
				Song song;
				file >> song;
				all_songs.insert({ song.get_name(), song });
			}
			else
				break;
		}
		file.close();
	}
	else
		std::cout << "Unable to open file \n";
}
Library::~Library() {}//da vika save_songs 

User& Library::get_user() 
{
	return curr_user;
}
Playlist& Library::get_playlist() 
{
	return curr_playlist;
}
std::unordered_map <std::string, Song>& Library::get_songs() 
{
	return all_songs;
}


void Library::all_songs_info()
{
	//search every song's name in the tree and cout info
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	for (auto& i : curr_playlist.get_songs()) //iterate through the playlist
	{
		for (auto& it : all_songs) //iterate through the whole map
		{
			if (it.first == i) //song found!
			{
				std::cout << it.second; //print the data of the song
				break;
			}
		}
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}
}
bool Library::check_playlist(const std::string& name)
{
	return (curr_playlist.get_name() == name);
}
bool Library::is_loaded() //for playlist
{
	return loaded_pl;
}


void Library::set_user(User& other)
{
	curr_user = other;
}
void Library::set_playlist(Playlist& other)
{
	curr_playlist = other;
	//adding to curr_user:
	curr_user.add_playlist(curr_playlist);
	loaded_pl = 1;
}

void Library::add_song(Song& other)
{
	all_songs.insert({other.get_name(), other});
}


//commands
//using cin.ignore() before every getline 
//so the input buffer is cleared of any left over new line characters from the previous input

//--general--
void Library::welcome()
{
	std::cout << "Welcome! Type 1 for list of all commands." << std::endl;
}
void Library::help()
{
	std::cout << "List of all commands: \n"
		<< "0 - exit\n"
		<< "1 - help menu \n"
		<< "--User--\n"
		<< "2 - sign in \n"
		<< "3 - sign up \n"
		<< "4 - change data \n"
		<< "5 - save changes \n"
		<< "--Song--\n"
		<< "6 - add song \n"
		<< "7 - rate song \n"
		<< "--Playlist--\n"
		<< "8 - generate playlist \n"
		<< "9 - change playlist's name \n"
		<< "10 - load playlist\n"
		<< "11 - show info for all songs\n";
}

//--user-- 
void Library::sign_in()
{
	std::string un, pw;

	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;
	//validation
	sign_in_helper(un, pw);
}
void Library::sign_in_helper(const std::string& un, const std::string& pw)
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
				this->set_user(user); 
				file.close();
				std::cout << "You are successfully signed in.\n";
				return;
			}
		}
		file.close();
	}
	std::cout << "Wrong username or password.\n";
}

void Library::sign_up()
{
	std::string un, pw;

	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;

	//validation
	sign_up_helper(un, pw);
}
void Library::sign_up_helper(const std::string& un, const std::string& pw)
{
	try
	{
		is_username_free(un);
		User new_user(un, pw);
		this->set_user(new_user);
		save_new_user_helper();
	}
	catch (int i)
	{
		std::cout << "This username is already taken.\n";
	}
}
void Library::is_username_free(const std::string& un)
{
	std::ifstream file("users.txt");
	if (file.is_open()) //if username is free
	{
		std::string x;
		while (!file.eof())
		{
			std::getline(file, x); //might move this upwards
			if (x == un)
			{
				file.close();
				throw - 1;
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
}

void Library::change_data()
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
	//check here for whitespaces(before or after)
	change_data_helper(command, config);
}
void Library::change_data_helper(size_t choice, const std::string& config)
{
	switch (choice)
	{
	case 1:
		try
		{
			is_username_free(config);
			save_username_helper(config); //username is used as a unique identificator!
			this->get_user().set_username(config);
		}
		catch (int a)
		{
			std::cout << "This username is already taken.\n";
		}
		break;
	case 2:
		this->get_user().set_password(config); break;
	case 3:
		this->get_user().set_full_name(config); break;
	case 4:
		this->get_user().set_birth_date(config); break;
	case 5:
		this->get_user().add_fav_genre(config); break;
	case 6:
		this->get_user().remove_fav_genre(config); break;
		//default?
	}
}

//files:
//fixed
void Library::save_new_user_helper()
{
	std::ofstream out("users.txt", std::ios::out | std::ios::app); //go at the end of the file
	std::ifstream in("users.txt");
	if (!out.is_open())
	{
		std::cout << "Unable to open file.\n";
		return;
	}
	if (in.peek() != EOF) //if it's not empty
	{
		out << '\n'; //because we are appending to the file
	}
	out << this->get_user();
	in.close();
	out.close();
	std::cout << "You are successfully signed up.\n";
}

void Library::save_username_helper(const std::string& un)
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
	while (std::getline(in, x)) //?????????????????????????????????????????????????????????????????????????????????????????????
	{
		//if (in.peek() != EOF) //if it's not the last element 
		//{
		if (x == this->get_user().get_name())
		{
			out << un << "\n";
		}
		else
			out << x << "\n"; //does it get the "\n" ? check!!

		for (size_t i = 0; i < 5; ++i) //blind copy next data
		{
			std::getline(in, x);
			out << x << '\n';
		}
		//}

	}
	in.close();
	out.close();
	remove("users.txt");
	std::rename("users1.txt", "users.txt"); //to remove warning: if(.. == NULL) return;
	std::cout << "Username is successfully changed.\n";
}

void Library::save_user_data() //not for username!
{
	//std::cout << "Saving all changes. Please, don't close the window\n"; //it's pretty fast as far as I've tested it
	save_user_data_helper();
}
void Library::save_user_data_helper()
{
	//read from user.txt -> write to user1.txt 
	//delete user.txt
	//rename user1.txt to user.txt
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

	for (size_t i = 0; in.peek() != EOF && !in.eof(); ++i)
	{
		User user;
		in >> user;
		if (i != 0) //not the very first element
			out << '\n'; //it's indirectly appending to the file
		if (user.get_name() == this->get_user().get_name()) //found the user we want to update
		{
			out << this->get_user();
		}
		else
		{
			out << user;
		}
	}
	in.close();
	out.close();
	remove("users.txt");
	std::rename("users1.txt", "users.txt"); //to remove warning: if(.. == NULL) return;
	std::cout << "Successfully saved.\n";
}


//--song-- 
void Library::add_song()
{
	std::string name, artist, genre, album;
	size_t release_year;
	//many inputs
	std::cout << "Enter name: ";
	std::cin.ignore();
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
	add_song_helper(name, artist, genre, album, release_year);
}
void Library::add_song_helper(const std::string& name, const std::string& artist, const std::string& genre,
	const std::string& album, size_t release_year)
{
	Song song(name, artist, genre, album, release_year);
	//possible check here if it's successfully constructed
	//yes =>
	all_songs.insert({ name, song });
	std::cout << "Song is successfully added.\n";// to the library.\n";
	//no =>
	//std::cout<<"Please enter correct data!\n";
}

void Library::rate_song()
{
	std::string name;
	size_t rate = 0;

	std::cout << "Enter song: ";
	std::cin.ignore();
	std::getline(std::cin, name);

	std::cout << "Enter rating(1-6): ";// 1-6 ? 
	std::cin >> rate;
	//validation
	rate_song_helper(name, rate);
}
void Library::rate_song_helper(const std::string& name, size_t rate)
{
	//if exists
	all_songs[name].set_rating(rate);
}

void Library::save_songs()
{
	std::ofstream file("songs.txt", std::ios::trunc); //delete and replace old content with the new data
	if (!file.is_open())
	{
		std::cout << "Unable to update file.\n";
		return;
	}
	for (auto& it : all_songs)
	{
		file << it.second;
	}
	file.close();
}

//--playlist--//only with correct data for now!!!
void Library::generate_playlist() // .... & ... | ...
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

	std::cin.ignore();
	std::getline(std::cin, input); // [command] (value) & [command] (value) | [command] (value)
	generate_playlist_helper(input);
}
void Library::generate_playlist_helper(std::string& input)  //
{
	std::set<std::string> playlist_songs; //songs, sorted in alphabetical order
	if (!expression(input, playlist_songs))
	{
		std::cout << "Nope..\n";
		return;
		//throw ...
		//return?
	}

	Playlist playlist;
	playlist.set_songs(playlist_songs);
	set_playlist(playlist); //set into library
	save_playlist();
}
bool Library::expression(std::string expr, std::set<std::string>& playlist_songs)
{
	std::stringstream ss(expr);
	while (std::getline(ss, expr, '|'))
	{
		//clear empty spaces
		std::string expr1 = expr;
		while (expr1.back() == ' ')
		{
			expr1.pop_back();
		}
		while (expr1.front() == ' ')
		{
			expr1.erase(0, 1);
		}

		std::unordered_map <std::string, Song> songs = all_songs; //creates a copy of all_songs //at the beginning of every statement is full
		if (statement(expr1, songs) == true)
		{
			for (auto& itr : songs)
			{
				playlist_songs.insert(itr.first);
			}
			return true;
		}
	}
	return false;
}
bool Library::statement(std::string state, std::unordered_map <std::string, Song>& songs)
{
	std::stringstream ss1(state);
	while (std::getline(ss1, state, '&'))
	{
		//clear empty spaces
		std::string state1 = state;
		while (state1.back() == ' ')
		{
			state1.pop_back();
		}
		while (state1.front() == ' ')
		{
			state1.erase(0, 1);
		}

		if (command(state1, songs) == false)
			return false;
	}
	return true;
}
bool Library::command(std::string com, std::unordered_map <std::string, Song>& songs)
{
	std::string type, op, opt; //type operator option

	std::stringstream ss2(com);
	
	//clear empty spaces
	while (com.back() == ' ')
	{
		com.pop_back();
	}
	while (com.front() == ' ')
	{
		com.erase(0, 1);
	}

	ss2 >> type;
	ss2 >> op;
	ss2.get(); //white space
	std::getline(ss2, opt);

	bool flag = false; //indicator for changes

	if (type == "rating")
	{
		if (op == ">")
		{
			for (auto itr = songs.cbegin(); itr != songs.cend(); ) //iterate through the whole map  //const?
			{
				if (itr->second.get_rating() < stod(opt))
				{
					songs.erase(itr++->first);
					flag = true;
				}
				else
					++itr;
			}
		}
	}
	else if (type == "genre")
	{
		if (op == "+")
		{
			for (auto itr = songs.cbegin(); itr != songs.cend(); ) //iterate through the whole map  //const?
			{
				if (itr->second.get_genre() != opt)
				{
					songs.erase(itr++->first);
					flag = true;
				}
				else
					++itr;
			}
		}
		else if (op == "-")
		{
			for (auto itr = songs.cbegin(); itr != songs.cend(); ) //iterate through the whole map  //const?
			{
				if (itr->second.get_genre() == opt)
				{
					songs.erase(itr++->first);
					flag = true;
				}
				else
					++itr;
			}
		}
		else if (op == "!")
		{
			for (auto& it : curr_user.get_fav_genres()) 
			{
				for (auto itr = songs.cbegin(); itr != songs.cend(); ) //iterate through the whole map  //const?
				{
					if (itr->second.get_genre() != it)
					{
						songs.erase(itr++->first);
						flag = true;
					}
					else
						++itr;
				}
			}
		}
	}
	else if (type == "year")
	{
		if (op == ">")
		{
			//if stoi > 0
			for (auto itr = songs.cbegin(); itr != songs.cend(); ) //iterate through the whole map  //const?
			{
				if (itr->second.get_year() <= stoi(opt))
				{
					songs.erase(itr++->first);
					flag = true;
				}
				else
					++itr;
			}
		}
		else if (op == "<")
		{
			for (auto itr = songs.cbegin(); itr != songs.cend(); ) //iterate through the whole map  //const?
			{
				if (itr->second.get_year() >= stoi(opt))
				{
					songs.erase(itr++->first);
					flag = true;
				}
				else
					++itr;
			}
		}
		else if (op == "=")
		{
			for (auto itr = songs.cbegin(); itr != songs.cend(); ) //iterate through the whole map  //const?
			{
				if (itr->second.get_year() != stoi(opt))
				{
					songs.erase(itr++->first);
					flag = true;
				}
				else
					++itr;
			}
		}
	}

	return (flag == true && !songs.empty());
}


void Library::save_playlist()
{
	if (!this->is_loaded())
	{
		std::cout << "Please, first load a playlist.\n";
		return;
	}
	std::string input;
	std::cout << "Enter playlist's new name: ";
	std::cin >> input;
	save_playlist_helper(input);
}
void Library::save_playlist_helper(const std::string& name)
{
	std::string old_name = this->get_playlist().get_name();
	this->get_user().get_playlist(old_name).set_name(name); //changes name in curr_user
	this->get_playlist().set_name(name); //changes name of the loaded playlist in the library

}

void Library::load_playlist()
{
	std::string input;
	std::cout << "Enter name: ";
	std::cin >> input;
	load_playlist_helper(input);
}
void Library::load_playlist_helper(const std::string& name) //to work, must fix load-func first
{
	if (!this->check_playlist(name)) //checks if it's not already loaded
	{
		if (this->get_user().is_playlist(name)) //seaarch in current user's playlist for name
		{
			this->set_playlist(this->get_user().get_playlist(name)); //if found -> add it to lib.curr_playlist
		}
		else
			std::cout << "No playlist found.\n";
	}
	else
		std::cout << "Playlist " << name << " is already loaded.";
}

void Library::show_all_info()
{
	this->all_songs_info();
}
