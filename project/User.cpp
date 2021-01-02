#include "User.h"

void User::copy(const User& other)
{
	username = other.username;
	password = other.password;
	full_name = other.full_name;
	birth_date = other.birth_date;
	for (int i = 0; other.fav_genres[i] != "\0"; ++i)
		fav_genres[i] = other.fav_genres[i];
	for (int i = 0; other.playlists[i] != "\0"; ++i)
		playlists[i] = other.playlists[i];
}
void User::clear()
{
	username.clear();
	password.clear();
	full_name.clear();
	birth_date.clear();
	for (int i = 0; i < 10; ++i) //max size
		fav_genres[i].clear();
	for (int i = 0; i < 10; ++i)
		playlists[i].clear();

}

User::User()
{
	username.reserve(20);
	username = "";
	password.reserve(20);
	password = "";
	full_name.reserve(30);
	full_name = "";
	birth_date.reserve(11); // XX.YY.ZZZZ \0
	birth_date = "";
	//fav_genres?
	//playlists?

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
	int i = 0;
	for (i; fav_genres[i] != "\0"; ++i) {}
	if (i < 10)
		fav_genres[i] = genre;
		
}
void User::remove_fav_genre(const std::string& genre)
{
	int i = 0;
	for (i; fav_genres[i] != genre; ++i) {} //i=2

	for (int j = i + 1; j < 10; ++j, ++i)
		fav_genres[i] = fav_genres[j];
}