#pragma once
#include "User.h"
#include "Song.h"
#include "Playlist.h"

#include <iostream>
//shte sydyrja elementi, koito v momenta se izpolzvat
class Library 
{
private:
	User logged_user;
	//std::vector<Song> songs;
	Playlist loaded_playlist;
	//std::vector<Album> albums;

public:
	//big 4
	User& get_user();
	Playlist& get_playlist();

	void add_user(const User& other);
	void add_playlist(const Playlist& other);

	void remove_user(const User& element);
	void remove_playlist(const Playlist& element);

};

