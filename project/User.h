#pragma once
#include <iostream>
#include <string>
#include <unordered_set> //is it already included?
#include "Playlist.h"


class User //validaciq v setterite?
{
private:
	std::string username; 
	std::string password;
	//-----------------------------------
	std::string full_name;
	std::string birth_date;

	std::unordered_set<std::string> fav_genres; //good for custom el add/remove 
	//std::vector<std::string> playlists;  //choosing type (maybe hash table)

private:
	void copy(const User& other);
	void clear();
public:
	User();
	User(const User& other); //copy
	User(const std::string& _username, const std::string& _password); //username + password
	User& operator=(const User& other);
	~User();

	//setteri i getteri
	void set_username(const std::string& _username);
	void set_password(const std::string& _password);
	void set_full_name(const std::string& _full_name);
	void set_birth_date(const std::string& _birth_date);
	const std::unordered_set<std::string>& get_fav_genres() const; //const& so not being changed

	void add_fav_genre(const std::string& genre);
	void remove_fav_genre(const std::string& genre);

};

