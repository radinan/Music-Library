#pragma once
#include "User.h"
#include "Song.h"
#include "Playlist.h"

#include <iostream>

class Library
{
private:
	/*
	all_users
	all_songs
	all_playlists
	all_albums */

public:

	void help();
	void sign_in();
	void sign_up();

	void change_data();
	int change_data_options();
	void add_song();
	void rate_song();
	void generate_playlist();
	int generate_playlist_choice();
	void save_playlist(); //pod ime
	void load_playlist();
	//void change_playlists_name(); //syshtoto kato save playlist
	void show_info_for_all_songs();


};

