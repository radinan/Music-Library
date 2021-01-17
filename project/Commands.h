#pragma once
#include <iostream>
#include "Library.h"
#include "Parser.h" 

//class with static methods => it doesn't need any attributes => no objects

//change private funcs to return bool value =>otuputs and inputs only in main funcs

class Commands 
{
public: 
	//-------------general----------------//
	static void welcome();
	static void help();
	//--------------user------------------//
	static void sign_in(Library& lib);
	static void sign_up(Library& lib);
	static void change_data(Library& lib);
	static void save_user_data(Library& lib); //not for username!
	//-------------song-------------------//
	static void add_song(Library& lib);
	static void rate_song(Library& lib);
	static void save_songs(Library& lib);
	//-------------playlist---------------//
	static void generate_playlist(Library& lib);
	static void save_playlist(Library& lib);
	static void load_playlist(Library& lib);
	static void show_all_info(Library& lib);

private:
	///user helpers///
	static void sign_in_helper(Library& lib, const std::string& un, const std::string& pw);
	static void sign_up_helper(Library& lib, const std::string& un, const std::string& pw);
	static void change_data_helper(Library& lib, size_t choice, const std::string& config);
	static void save_new_user_helper(Library& lib);
	static void save_username_helper(Library& lib, const std::string& un);
	static void save_user_data_helper(Library& lib);
	///song helpers///
	static void add_song_helper(Library& lib, const std::string& name, const std::string& artist, const std::string& genre, 
							const std::string& album, size_t release_year);
	static void rate_song_helper(Library& lib, const std::string& name, size_t rate);
	//static void save_songs()
	///playlist helpers///
	static void generate_playlist_helper(Library& lib, const std::string& input);
	static void save_playlist_helper(Library& lib, const std::string& name);
	static void load_playlist_helper(Library& lib, const std::string& name);
};

