#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Playlist.h"

class User //validaciq v setterite?
{
private:
	//da gi napravq pairs?
	std::string username; 
	std::string password;
	//-----------------------------------
	std::string full_name;
	std::string birth_date;

	std::vector<std::string> fav_genres;
	std::vector<Playlist> playlists;

	bool is_logged;
private:
	void copy(const User& other);
	void clear();
public:
	User();
	User(const User& other); //copy
	User(const std::string& user, const std::string& pass);
	User& operator=(const User& other);
	~User();

	//setteri i getteri
	void set_username(const std::string& _username);
	void set_password(const std::string& _password);
	void set_full_name(const std::string& _full_name);
	void set_birth_date(const std::string& _birth_date);
	void set_is_logged(bool _is_logged); //shte vidim dali shte go ostavq taka

	void add_genre(std::string genre);
	void remove_genre(std::string genre);

};

