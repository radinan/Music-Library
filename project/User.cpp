#include "User.h"

void User::copy(const User& other)
{
	username = other.username;
	password = other.password;
	full_name = other.full_name;
	birth_date = other.birth_date;
	fav_genres = other.fav_genres;
	playlists = other.playlists;
}
void User::clear()
{
	username.clear();
	password.clear();
	full_name.clear();
	birth_date.clear();
	fav_genres.clear();
	playlists.clear();

	//da se iztrie i ot faila
}

User::User()
{
	//da proverq moga li da mina bez tezi inicializacii
	username = "";
	password = "";
	full_name = "";
	birth_date = "";
	//da proverq vektorite dali sa prazni
} 
User::User(const User& other) //copy
{
	copy(other);
}
User::User(const std::string& user, const std::string& pass)
{
	username = user;
	password = pass;
}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}
User::~User()
{
	clear();
}

void User::set_username(const std::string& _username)
{
	username = _username;
}
void User::set_password(const std::string& _password)
{
	password = _password;
}
void User::set_full_name(const std::string& _full_name)
{
	full_name = _full_name;
}
void User::set_birth_date(const std::string& _birth_date)
{
	birth_date = _birth_date;
}



void User::add_genre(std::string genre)
{
	fav_genres.push_back(genre);
}
void User::remove_genre(std::string genre)
{
	for (size_t i = 0; i < fav_genres.size(); ++i) //ili i<size (se taq)
	{
		if (fav_genres[i] == genre)
			fav_genres.erase(fav_genres.begin() + i);
	}
}