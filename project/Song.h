#pragma once
#include <iostream>
#include <string>
#include <utility>
//#include "Album.h"

class Song
{
private:
	std::string name;
	std::string artist; //izpylnitel
	std::string genre; //moje da e enum??
	std::string album;
	std::string release_date; //mmoje i da go smenq na int
	std::pair <int, int> rating; //broi glasuvali, sbor ot glasove

public:
	Song();
	Song(std::string& _name, std::string& _artist, std::string& _genre, 
		std::string& _album, std::string& _release_date);

	//setter-i i getter-i
	void set_rating(int rate);
	double get_rating();

	std::string& get_name();
	void song_info();
};

