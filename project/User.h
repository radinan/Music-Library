#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Playlist.h"

class User
{
private:
	std::string username; 
	std::string password;
	//-----------------------------------
	std::string full_name;
	std::string birth_date;

	std::vector<std::string> fav_genres;
	std::vector<Playlist> playlists;

	bool is_logged;

public:

};

