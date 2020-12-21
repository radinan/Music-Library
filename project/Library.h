#pragma once
#include "User.h"
#include "Song.h"
#include "Playlist.h"

#include <iostream>
//shte sydyrja elementi, koito v momenta sa neobhodimi/izpolzvani na/ot potrebitelq
//da pushvame elementi koito sa s bool == 1
//posle da gi popvame
//predi  izhod ot programata da se zapazvat danni ot v-rite vyv file-a
class Library 
{
private:
	std::vector<User> users;
	std::vector<Song> songs;
	std::vector<Playlist> playlists;
	std::vector<Album> albums;

public:
	//big 4
	void add_user(const User& other);
	void add_song(const Song& other);
	void add_playlist(const Playlist& other);
	void add_album(const Album& other);

	void remove_user(const User& element);
	void remove_song(const Song& element);
	void remove_playlist(const Playlist& element);
	void remove_album(const Album& element);

};

