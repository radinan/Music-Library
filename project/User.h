#pragma once
#include <iostream>
#include <string>
#include <unordered_set> //is it already included?
#include <unordered_map>
#include <algorithm>
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
	std::unordered_set<std::string> voted_songs; //user'd already voted for these songs
	std::unordered_map<std::string, Playlist> playlists;		
private:
	void copy(const User& other);
	//validations
	void date_validation(const std::string& date);
	void symbols_validation(const std::string& str);
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

	void add_fav_genre(const std::string& genre);
	void add_playlist(Playlist& other);
	void add_voted_song(const std::string& name);
	void change_playlists_name(const std::string& old_name, const std::string& new_name);

	const std::unordered_set<std::string>& get_fav_genres() const; //const& so not being changed
	std::string get_name(); //by copy
	Playlist& get_playlist(const std::string& name);
	void remove_fav_genre(const std::string& genre);

	//informative methods
	bool check_username_password(const std::string& _username, const std::string& _password);
	bool is_playlist(const std::string& name);


	friend std::ostream& operator<< (std::ostream& out, User& user);
	friend std::istream& operator>> (std::istream& in, User& user);
};

