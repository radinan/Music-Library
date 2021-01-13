#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Song.h"
#include <list>

class Playlist //validaciq za input(simvoli intervali i tn)
{
private:
	std::string name; 
	size_t size = 0;
	const size_t max_size = 20;

	std::list<std::string> songs; // changes in tree will reflect in playlist without changing any data
								  // also it's easier to read from/write to file
private:
	void copy(const Playlist& other);
	void clear();
public:
	Playlist();
	Playlist& operator=(const Playlist& other);
	~Playlist();

	void add_song(const Song& other);
	std::string& get_name(); //without const?
	void set_name(const std::string& _name);
	const std::list<std::string>& get_songs();
	void set_songs(std::list<std::string> other);


	void load_playlist(std::string& playlist);
	friend std::ostream& operator<< (std::ostream& out, Playlist& playlist);

};

