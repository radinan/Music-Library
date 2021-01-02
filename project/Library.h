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
	User curr_user; //recently logged; current
	AVLTree<Song> all_songs; //in the whole library
	Playlist curr_playlist;

public:
	//big 4
	User get_user() const;
	Playlist get_playlist() const;

	void add_user(const User& other);
	void add_playlist(const Playlist& other);
	void add_song(const Song& other);

};

