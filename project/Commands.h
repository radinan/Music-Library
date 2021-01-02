#pragma once
#include <iostream>

//class with static methods => it doesn't need any attributes => no objects
class Commands 
{
public: 
	//-------------general-----------------
	static void welcome();
	static void help();

	//--------------user-------------------
	static void sign_in();
	static void sign_up();
	static void change_data();
	//-------------song--------------------
	static void add_song();
	static void rate_song();
	//-------------playlist-----------------
	static void generate_playlist();
	static void save_playlist();
	static void load_playlist();
	static void show_all_info();

private:
	///user helpers///
	static void sign_in_helper(const std::string& un, const std::string& pw);
	static void sign_up_helper(const std::string& un, const std::string& pw);
	static void change_data_helper(int choice, const std::string& input);
	///song helpers///
	static void add_song_helper(const std::string& name, const std::string& artist, const std::string& genre, const std::string& album, int release_date);
	static void rate_song_helper(const std::string& name, int rate);
	///playlist helpers///
	static void generate_playlist_helper(const std::string& input);
	static void save_playlist_helper(const std::string& name);
	static void load_playlist_helper(const std::string& name);
};

