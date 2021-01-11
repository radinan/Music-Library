#pragma once
#include "User.h"
#include "Song.h"
#include "Playlist.h"
#include "AVLTree.h"
#include <iostream>

//contains elements that are being used or needed
class Library 
{
private: //!!!think about copies and whether you want to change the original user or not!!!
	User curr_user; //recently logged; current
	//AVLTree all_songs; //in the whole library
	Playlist curr_playlist;

public:
	//big 4
	Library();
	~Library();

	User& get_user();
	Playlist& get_playlist();

	void add_user(const User& other);
	void add_playlist(const Playlist& other);
	//void add_song(const Song& other);

};

