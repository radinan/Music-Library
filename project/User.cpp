#include "User.h"

void User::copy(const User& other)
{
	username = other.username;
	password = other.password;
	full_name = other.full_name;
	birth_date = other.birth_date;
	fav_genres = other.fav_genres;
	//playlist
}
void User::clear()
{
	username.clear();
	password.clear();
	full_name.clear();
	birth_date.clear();
	fav_genres.clear();
	//playlist
}

User::User() //they have their own default constructors; should I initialize them?
{
	//or without reserve?

	username.reserve(20);
	//username = "";
	password.reserve(20);
	//password = "";
	full_name.reserve(30);
	//full_name = "";
	birth_date.reserve(11); // XX.YY.ZZZZ \0
	//birth_date = "";
	//fav_genres?
	//playlists?

} 
User::User(const User& other) //copy
{
	copy(other);
}
User::User(const std::string& _username, const std::string& _password) 
	: username(_username), password(_password)
{}
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
	fav_genres.insert(genre);
}
void User::remove_fav_genre(const std::string& genre)
{
	//if(fav_genres.find(genre) != fav_genres.end())
	fav_genres.erase(genre);
}