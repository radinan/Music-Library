#pragma once
//#include "User.h"
//#include "Song.h"
//#include "Playlist.h"
#include "AVLTree.h"
#include <iostream>

//contains elements that are being used or needed
class Library 
{
private: //!!!think about copies and whether you want to change the original user or not!!! wtf?
	User curr_user; //recently logged; current
	Playlist curr_playlist;
	bool loaded_pl = 0;
	AVLTree all_songs; //in the whole library 
					   //the original avl tree with all songs is always sorted by name!
public:
	Library();
	Library(const AVLTree& other); //constructor with the loaded tree
	~Library();

	User& get_user();
	Playlist& get_playlist();
	AVLTree& get_songs();

	void all_songs_info();
	bool check_playlist(const std::string& name);
	bool is_loaded(); //for playlist

	void set_user(const User& other); //loads user
	void set_playlist(Playlist& other); //loads playlist
	void add_song(const Song& other); //adds song to the tree


};

