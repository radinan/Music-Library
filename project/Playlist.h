#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Song.h"

class Playlist //validaciq za input(simvoli intervali i tn)
{
private:
	std::string name;
	std::vector<Song> songs;
	int size; //opredelen maks razmer

	bool is_loaded;
	
public:
	void add_song(const Song& other);
	void remove_song(const Song& element);
	void change_name(std::string& _name);
	void load();
	void unload();
};

