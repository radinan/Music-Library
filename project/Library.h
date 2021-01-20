#pragma once
//#include "User.h"
//#include "Song.h"
//#include "Playlist.h"
//#include "AVLTree.h"
#include "Song.h"
#include "Playlist.h"
#include "User.h"
#include <iostream>
#include <unordered_map>

//Let's accept that all songs have unique names!

//contains elements that are being used or needed
class Library 
{
private: //!!!think about copies and whether you want to change the original user or not!!! wtf?
	User curr_user; //recently logged; current
	Playlist curr_playlist;
	bool loaded_pl = 0;
	std::unordered_map <std::string, Song> all_songs; //without references?
public:
	Library();
	~Library();

	User& get_user();
	Playlist& get_playlist();
	std::unordered_map <std::string, Song>& get_songs();

	void all_songs_info();
	bool check_playlist(const std::string& name);
	bool is_loaded(); //for playlist

	void set_user(User& other); //loads user
	void set_playlist(Playlist& other); //loads playlist
	void add_song(Song& other); //adds song to the tree


	//commands
public:
	//-------------general----------------//
	 void welcome();
	 void help();
	//--------------user------------------//
	 void sign_in();
	 void sign_up();
	 void change_data();
	 void save_user_data(); //not for username!
	//-------------song-------------------//
	 void add_song();
	 void rate_song();
	 void save_songs();
	//-------------playlist---------------//
	 void generate_playlist();
	 void save_playlist();
	 void load_playlist();
	 void show_all_info();

private:
	///user helpers///
	 void sign_in_helper(const std::string& un, const std::string& pw);
	 void sign_up_helper(const std::string& un, const std::string& pw);
	 void is_username_free(const std::string& un);
	 void change_data_helper(size_t choice, const std::string& config);
	 void save_new_user_helper();
	 void save_username_helper(const std::string& un);
	 void save_user_data_helper();
	///song helpers///
	 void add_song_helper(const std::string& name, const std::string& artist, const std::string& genre,
		const std::string& album, size_t release_year);
	 void rate_song_helper(const std::string& name, size_t rate);
	// void save_songs()
	///playlist helpers///
	 void generate_playlist_helper(std::string& input);

	 bool expression(std::string expr, std::set<std::string>& playlist_songs);
	 bool statement(const std::string state, std::unordered_map <std::string, Song>& songs);
	 bool command(const std::string com, std::unordered_map <std::string, Song>& songs);


	 void save_playlist_helper(const std::string& name);
	 void load_playlist_helper(const std::string& name);

};

