#include "User.h"
#include <sstream>
#include <unordered_map>


void User::copy(const User& other)
{
	username = other.username;
	password = other.password;
	full_name = other.full_name;
	birth_date = other.birth_date;
	fav_genres = other.fav_genres;
	voted_songs = other.voted_songs;
	playlists = other.playlists;
}

void User::date_validation(const std::string& date)
{
	std::stringstream ss(date);
	std::string x; //temporary to save separated sections of the string

	std::getline(ss, x, '.');
	int day = stoi(x);
	std::getline(ss, x, '.');
	int month = stoi(x);
	std::getline(ss, x, '\n');
	int year = stoi(x);

	if (year < 1 || year > 2020)
		throw std::invalid_argument("Invalid date.");
	switch (month)
	{
	case 1: case 3:case 5: case 7: case 8: case 10:case 12:
		if (day < 1 || day > 31)
			throw std::invalid_argument("Invalid date.");
		break;
	case 4: case 6: case 9: case 11:
		if (day < 1 || day > 30)
			throw std::invalid_argument("Invalid date.");
		break;
	case 2:
		if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) //leap
		{
			if (day < 1 || day > 29)
				throw std::invalid_argument("Invalid date.");
			break;
		}
		else if (day < 1 || day > 28)
			throw std::invalid_argument("Invalid date.");
		break;
	default:
		throw std::invalid_argument("Invalid date.");
		break;
	}
}
void User::symbols_validation(const std::string& str)
{
	if (str.find('#') != std::string::npos)
		throw std::invalid_argument("Invalid symbol.");
	if (str.find('+') != std::string::npos)
		throw std::invalid_argument("Invalid symbol.");
	if (str.find('|') != std::string::npos)
		throw std::invalid_argument("Invalid symbol.");
	if (str.find('~') != std::string::npos)
		throw std::invalid_argument("Invalid symbol.");
}


User::User() //they have their own default constructors;
{
	username = "#";
	password = "#";
	full_name = "#";
	birth_date = "00.00.0000";
} 
User::User(const User& other) //copy
{
	copy(other);
}
User::User(const std::string& _username, const std::string& _password) 
{
	symbols_validation(_username);
	symbols_validation(_password);

	username = _username;
	password = _password;
	full_name = "#";
	birth_date = "00.00.0000";
}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}
User::~User()
{
}

void User::set_username(const std::string& _username)
{
	symbols_validation(_username);
	username = _username;
}
void User::set_password(const std::string& _password)
{
	symbols_validation(_password);
	password = _password;
}
void User::set_full_name(const std::string& _full_name)
{
	symbols_validation(_full_name);
	full_name = _full_name;
}
void User::set_birth_date(const std::string& _birth_date)
{
	date_validation(_birth_date);
	birth_date = _birth_date;
}

void User::add_fav_genre(const std::string& genre)
{
	symbols_validation(genre);
	fav_genres.insert(genre);
}
void User::add_playlist(Playlist& other)
{
	//if (is_playlist(other.get_name())) //if playlist with the same name already exist for this user
		//throw std::invalid_argument("Name is already used.");
	//else
		playlists.insert({other.get_name(), other});
}
void User::add_voted_song(const std::string& name)
{
	if (voted_songs.find(name) != voted_songs.end())
		throw std::invalid_argument("Already voted for this song.");
	else
		voted_songs.insert(name);
}
void User::change_playlists_name(const std::string& old_name, const std::string& new_name)
{
	Playlist pl = playlists[old_name]; //copies old playlist
	pl.set_name(new_name); //updates name ?????
	playlists.insert({ new_name, pl }); //creates new key with this data
	playlists.erase(old_name);
}


const std::unordered_set<std::string>& User::get_fav_genres() const
{
	return fav_genres;
}
std::string User::get_name() //by copy
{
	return username;
}
Playlist& User::get_playlist(const std::string& name)
{
	if (!is_playlist(name))
		throw std::invalid_argument("No playlist found.");
	else
		return playlists.find(name)->second;
}
void User::remove_fav_genre(const std::string& genre)
{
	fav_genres.erase(genre);
}



bool User::check_username_password(const std::string& _username, const std::string& _password)
{
	return (username == _username && password == _password);
}
bool User::is_playlist(const std::string& name)
{
	return playlists.find(name) != playlists.end(); //does it exist within "playlists:
}



std::ostream& operator<< (std::ostream& out, User& user)
{
	out << user.username; out << "\n";
	out << user.password; out << "\n";
	out << user.full_name; out << "\n";
	out << user.birth_date; out << "\n";
	//genres
	std::unordered_set<std::string>::iterator it = user.fav_genres.begin();
	if (it != user.fav_genres.end()) //fixed problem: genre+genre+genre+ 
	{
		out << *it; //first
		++it;
		for (; it != user.fav_genres.end(); ++it)
		{
			out << "+" << *it;  //first + second ...
		}
		out << "\n";
	}
	else //empty set
	{
		out << "#" << '\n'; //symbol for empty
	}
	//voted_songs
	std::unordered_set<std::string>::iterator it1 = user.voted_songs.begin();
	if (it1 != user.voted_songs.end()) //fixed problem: genre+genre+genre+ 
	{
		out << *it1; //first
		++it1;
		for (; it1 != user.voted_songs.end(); ++it1)
		{
			out << "^" << *it1;  //first + second ...
		}
		out << "\n";
	}
	else //empty set
	{
		out << "#" << '\n'; //symbol for empty
	}
	
	//playlist
	std::unordered_map<std::string, Playlist>::iterator it2 = user.playlists.begin();
	if (it2 != user.playlists.end())
	{
		out << it2->second;
		++it2;
		for (; it2 != user.playlists.end(); ++it2)
		{
			out << "~" << it2->second;
		}
	}
	else
	{
		out << "#"; //no \n
	}


	return out;
}
std::istream& operator>> (std::istream& in, User& user)
{
	in >> user.username; in.get();
	in >> user.password; in.get();
	std::getline(in, user.full_name);
	in >> user.birth_date; in.get();
	//genres:
	if (in.peek() != '#')
	{
		std::string line;
		std::getline(in, line); //saving the whole line into a string
		std::istringstream ss(line);
		while (std::getline(ss, line, '+')) //splitting
		{
			user.fav_genres.insert(line);
		}
	}
	else
	{
		in.get(); // #
		in.get(); // \n
	}
	//voted_songs
	if (in.peek() != '#')
	{
		std::string line1;
		std::getline(in, line1); //saving the whole line into a string
		std::istringstream ss1(line1);
		while (std::getline(ss1, line1, '^')) //splitting
		{
			user.voted_songs.insert(line1);
		}
	}
	else
	{
		in.get(); // #
		in.get(); // \n
	}
	//playlists
	if (in.peek() != '#')
	{
		std::string line2;// = "name|song+song~name|song+song+song";
		std::getline(in, line2);
		std::istringstream ss2(line2);
		while (std::getline(ss2, line2, '~')) //name|song+song
		{
			Playlist pl;
			pl.load_playlist(line2);
			user.add_playlist(pl);
		}
	}
	else
	{
		in.get(); // #
		in.get(); // \n		//or without?
	}

	return in;
}