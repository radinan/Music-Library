#include "Library.h"
#include <iostream>
#include <string>
#include <fstream>

//added default constructor

//Library::Library(const AVLTree& other) : all_songs(other){}
Library::Library() 
{
	//loads all song data to the file
	std::ofstream file ("songs.txt"); // opens file "songs"
	if (file.is_open())
	{
		while(!file.eof())
		{
			Song song;
			file << song;
			all_songs.insert(song);
		}
		file.close();
	}
	else
		std::cout << "Unable to open file \n";
}
Library::~Library() {}

User& Library::get_user() 
{
	return curr_user;
}
Playlist& Library::get_playlist() 
{
	return curr_playlist;
}
AVLTree& Library::get_songs()
{
	return all_songs;
}



void Library::set_user(const User& other)
{
	curr_user = other;
}
void Library::set_playlist(const Playlist& other)
{
	curr_playlist = other;
}

void Library::add_song(const Song& other)
{
	all_songs.insert(other);
}

