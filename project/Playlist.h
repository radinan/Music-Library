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
	Song songs[max_size]; //maximum 20 songs
	int size = 0;

public:
	void add_song(const Song& other);
	void remove_song(std::string& _name); //moje i da go promenq na const Song&
	void change_name(std::string& _name);
	void all_songs_name();
	void all_songs_info();
};

