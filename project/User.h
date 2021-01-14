#pragma once
#include <iostream>
#include <string>
#include <unordered_set> //is it already included?
#include "Playlist.h"


class User //validation inside setters?
{
private:
	std::string username; 
	std::string password;
	//-----------------------------------
	std::string full_name;
	std::string birth_date;

	std::unordered_set<std::string> fav_genres; //good for custom el add/remove 
	std::vector<Playlist> playlists;		

private:
	void copy(const User& other);
	void clear();
public:
	User();
	User(const User& other); //copy
	User(const std::string& _username, const std::string& _password); //username + password
	User& operator=(const User& other);
	~User();

	//setters and getters
	void set_username(const std::string& _username);
	void set_password(const std::string& _password);
	void set_full_name(const std::string& _full_name);
	void set_birth_date(const std::string& _birth_date);

	const std::unordered_set<std::string>& get_fav_genres() const; //const& so not being changed
	
	bool check_username_password(const std::string& _username, const std::string& _password);

	void add_fav_genre(const std::string& genre);
	void remove_fav_genre(const std::string& genre);
	void add_playlist(Playlist& other);

	bool is_playlist(const std::string & name);
	Playlist& get_playlist(const std::string& name);

	friend std::ostream& operator<< (std::ostream& out, User& user);
	friend std::istream& operator>> (std::istream& in, User& user);
};

