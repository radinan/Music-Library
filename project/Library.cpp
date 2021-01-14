#include "Library.h"
#include <iostream>
#include <string>
#include <fstream>


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
Library::Library(const AVLTree& other) : all_songs(other) {}
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


void Library::all_songs_info()
{
	//search every song's name in the tree and cout info
	for (auto const& i : curr_playlist.get_songs())
	{
		all_songs.find(i)->data.song_info();
	}
}
bool Library::check_playlist(const std::string& name)
{
	return (curr_playlist.get_name() == name);
}
bool Library::is_loaded() //for playlist
{
	return loaded_pl;
}


void Library::set_user(const User& other)
{
	curr_user = other;
}
void Library::set_playlist(Playlist& other)
{
	curr_playlist = other;
	//adding to curr_user:
	curr_user.add_playlist(curr_playlist);
	loaded_pl = 1;
}

void Library::add_song(const Song& other)
{
	all_songs.insert(other);
}


