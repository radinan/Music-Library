#pragma once
#include "User.h"
#include "Song.h"
#include "Playlist.h"
#include "AVLTree.h"

#include <iostream>
//contains elements that are being used or needed
class Library 
{
private:
	User logged_user; //recently logged; current
	AVLTree<Song> all_songs; //in the whole library
	Playlist loaded_playlist;

public:
	//big 4
	User& get_user();
	Playlist& get_playlist();

	void add_user(const User& other);
	void add_playlist(const Playlist& other);
	void add_song(const Song& other);

	void remove_user(const User& element);
	void remove_playlist(const Playlist& element);

};

