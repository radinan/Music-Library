#pragma once

class TerminalDialog
{
public:
	//general
	static void welcome();
	static void help();
	//user
	static void sign_in();
	static void sign_up();
	static void change_data();
	//song
	static void add_song();
	static void rate_song();
	//playlist
	static void generate_playlist();
	static void save_playlist();
	static void load_playlist();
	//static void show_all_info();
};

