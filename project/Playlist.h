#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Song.h"

const int max_size = 10; //primerno

class Playlist //validaciq za input(simvoli intervali i tn)
{
private:
	std::string name;
	std::vector<Song> songs;
	int size; //< opredelen maks razmer

	
public:
	void add_song(const Song& other);
	void remove_song(std::string& _name); //moje i da go promenq na const Song&
	void change_name(std::string& _name);
	void all_songs_name();
	void all_songs_info();

};

