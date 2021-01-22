#pragma once
#include "User.h"
#include <iostream>
#include <unordered_map>

//Let's accept that all songs have unique names!
//This class contains elements that are being used or needed
class Library 
{
private:
	User curr_user; //recently logged; current
	bool logged_u = false; //is any user logged
	Playlist curr_playlist; //loaded playlist
	bool loaded_pl = false; //is any playlist loaded
	std::unordered_map <std::string, Song> all_songs; //all songs in library
public:
	//constructors
	Library();
	~Library();

	//setters
	void set_user(User& other); //loads user
	void set_playlist(Playlist& other); //loads playlist
	void add_song(Song& other); 

	//getters
	User& get_user();
	Playlist& get_playlist();
	std::unordered_map <std::string, Song>& get_songs();

	//informative methods
	void all_songs_info();
	bool check_playlist(const std::string& name);
	bool is_loaded(); //for playlist
	bool is_logged(); //for user
	void is_username_free(const std::string& un);

	//commands
	//-------------general----------------//
	 void welcome();
	 void help();
	 void exit();
	//--------------user------------------//
	 void sign_in();
	 void sign_up();
	 void change_data();
	 void save_user_data(); 
	 void log_out();
	//-------------song-------------------//
	 void add_song();
	 void rate_song();
	//-------------playlist---------------//
	 void generate_playlist();
	 void save_playlist();
	 void load_playlist();
	 void show_all_info();

private:
	///general helpers///
	void exit_helper();

	///user helpers///
	 void sign_in_helper(const std::string& un, const std::string& pw);
	 void sign_up_helper(const std::string& un, const std::string& pw);
	 void change_data_helper(size_t choice, const std::string& config);
	 void save_new_user_helper();
	 void save_username_helper(const std::string& un);
	 void save_user_data_helper();
	 void log_out_helper();

	///song helpers///
	 void add_song_helper(const std::string& name, const std::string& artist, const std::string& genre,
						  const std::string& album, int release_year);
	 void rate_song_helper(const std::string& name, int rate);

	///playlist helpers///
	 void generate_playlist_helper(std::string& input);
	 bool expression(std::string expr, std::set<std::string>& playlist_songs);
	 bool statement(const std::string state, std::unordered_map <std::string, Song>& songs);
	 bool command(const std::string com, std::unordered_map <std::string, Song>& songs);

	 void save_playlist_helper(const std::string& name);
	 void load_playlist_helper(const std::string& name);
	 void show_all_info_helper();

};

