#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Song.h"
#include <list>
#include <set>

class Playlist //validaciq za input(simvoli intervali i tn)
{
private:
	std::string name; 
	const size_t max_size = 20;

	std::list<std::string> songs; // changes in tree will reflect in playlist without changing any data
								  // also it's easier to read from/write to file
private:
	void copy(const Playlist& other);
public:
	Playlist();
	Playlist& operator=(const Playlist& other);
	~Playlist();

	//setters and getters
	void set_name(const std::string& _name);
	void set_songs(std::set<std::string>& other_songs);
	void add_song(Song& other);
	std::string& get_name(); //without const?
	std::list<std::string>& get_songs();	
	size_t get_size();


	void load_playlist(std::string& line);
	friend std::ostream& operator<< (std::ostream& out, Playlist& playlist);

};

