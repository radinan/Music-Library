#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Song.h"
#include <list>

//adding size_t size
//		 list<string> songs;
//		 load_playlist()
//		 friend ostream operator<<()
//fixing add_song

//to do:
//all_songs_info

class Playlist //validaciq za input(simvoli intervali i tn)
{
private:
	std::string name; 
	size_t size = 0;
	const size_t max_size = 20;

	std::list<std::string> songs; // changes in tree will reflect in playlist without changing any data
								  // also it's easier to read from/write to file
public:
	Playlist();
	~Playlist();

	void add_song(const Song& other);
	void set_name(const std::string& _name);

	void all_songs_info();

	void load_playlist(std::string& playlist);
	friend std::ostream& operator<< (std::ostream& out, Playlist& playlist);

};

