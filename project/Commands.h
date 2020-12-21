#pragma once
#include <iostream>
//dali prechat na TerminalDialog -> moje bez "_"
class Commands //maham gi da ne sa static
{
public: //pravq sys setteri i getteri, posle shte mislq kak da go opravq
	//user
	 void sign_in(std::string& un, std::string& pw);
	 void sign_up(std::string& un, std::string& pw);
	 void change_data(int choice, std::string& input);

	//song
	 void add_song(std::string& name, std::string& artist, std::string& genre,
					std::string& album, std::string& release_date);
	 void rate_song(std::string& name, int rate);

	//playlist
	 void generate_playlist(std::string& input);
	 void save_playlist(std::string& name);
	 void load_playlist(std::string& name);
	 void show_all_info();
};

