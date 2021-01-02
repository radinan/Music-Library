#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Song.h"

const int max_size = 20; //fixed max size

class Playlist //validaciq za input(simvoli intervali i tn)
{
private:
	std::string name; 
	int size = 0; //count of songs
	Song songs[max_size]; //maximum 20 songs

public:
	void add_song(const Song& other);
	void remove_song(const std::string& _name); //moje i da go promenq na const Song&
	void change_name(const std::string& _name);
	void all_songs_name() const;
	void all_songs_info() const;
};

