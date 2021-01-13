#pragma once
#include <iostream>
#include "Library.h"
#include "Parser.h" 

//class with static methods => it doesn't need any attributes => no objects
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
	//-------------song-------------------//
	static void add_song(Library& lib);
	static void rate_song(Library& lib);
	//-------------playlist---------------//
	static void generate_playlist(Library& lib);
	static void save_playlist(Library& lib);
	static void load_playlist(Library& lib);
	static void show_all_info(Library& lib);

private:
	///user helpers///
	static void sign_in_helper(Library& lib, const std::string& un, const std::string& pw);
	static void sign_up_helper(Library& lib, const std::string& un, const std::string& pw);
	static void change_data_helper(Library& lib, int choice, const std::string& config);
	///song helpers///
	static void add_song_helper(Library& lib, const std::string& name, const std::string& artist, const std::string& genre, const std::string& album, int release_date);
	static void rate_song_helper(Library& lib, const std::string& name, int rate);
	///playlist helpers///
	static void generate_playlist_helper(Library& lib, const std::string& input);
	static void save_playlist_helper(Library& lib, const std::string& name);
	static void load_playlist_helper(Library& lib, const std::string& name);
};

