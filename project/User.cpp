#include "User.h"
#include <sstream>

void User::copy(const User& other)
{
	username = other.username;
	password = other.password;
	full_name = other.full_name;
	birth_date = other.birth_date;
	fav_genres = other.fav_genres;
	playlists = other.playlists;
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
	//validation
	username = _username;
}
void User::set_password(const std::string& _password)
{
	//validation
	password = _password;
}
void User::set_full_name(const std::string& _full_name)
{
	//validation
	full_name = _full_name;
}
void User::set_birth_date(const std::string& _birth_date)
{
	//validation
	birth_date = _birth_date;
}
void User::add_fav_genre(const std::string& genre)
{
	fav_genres.insert(genre);
}
void User::add_playlist(Playlist& other)
{
	playlists.push_back(other);
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
	for (auto& i : playlists)
	{
		if (i.get_name() == name)
			return i;
	}

	throw std::invalid_argument("No playlist found.");
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
	for (auto i : playlists)
	{
		if (i.get_name() == name)
			return true;
	}
	return false;
}




std::ostream& operator<< (std::ostream& out, User& user)
{
	out << user.username; out << "\n";
	out << user.password; out << "\n";
	out << user.full_name; out << "\n";
	out << user.birth_date; out << "\n";

	std::unordered_set<std::string>::iterator it = user.fav_genres.begin();
	if (it != user.fav_genres.end()) 	//fixed problem: genre+genre+genre+ 
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


	if (!user.playlists.empty())
	{
		std::vector<Playlist>::size_type sz = user.playlists.size();

		int i = 0;
		for (; i < sz - 1; ++i) //PROBLEM! wtf?
		{
			out << user.playlists[i] << "~";
		}
		out << user.playlists[i];
	}
	else
		out << "#"; //symbol for empty; no '\n'
	return out;
}
std::istream& operator>> (std::istream& in, User& user)
{
	in >> user.username; 
	in.get();

	in >> user.password; 
	in.get();

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

	//playlists
	if (in.peek() != '#')
	{
		std::string line1;// = "name|song+song~name|song+song+song";
		std::getline(in, line1);
		std::istringstream ss1(line1);
		while (std::getline(ss1, line1, '~')) //name|song+song
		{
			//std::string playlist = line1;
			Playlist pl;
			pl.load_playlist(line1);
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