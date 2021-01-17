#include "Playlist.h"
#include <sstream>


void Playlist::copy(const Playlist& other)
{
	name = other.name;
	songs = other.songs;
}
void Playlist::clear()
{
	name.clear();
	songs.clear();
}

//fill:
Playlist::Playlist(){} //add linked list w songs
Playlist& Playlist::operator=(const Playlist& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}
Playlist::~Playlist(){}

void Playlist::add_song(const Song& other) //song's name?
{
	if (get_size() <= max_size  ) //if there is free space in the playlist
	{
		songs.push_back(other.get_name());
	}
	else
		std::cout << "No free space in the playlist \n";
}
std::string& Playlist::get_name() 
{
	return name;
}

void Playlist::set_name(const std::string& _name)
{
	//validation
	name = _name;
}
const std::list<std::string>& Playlist::get_songs()
{
	return songs;
}
void Playlist::set_songs(std::list<std::string> other)
{
	songs = other;
}
size_t Playlist::get_size()
{
	return songs.size();
}



void Playlist::load_playlist(std::string& playlist)
{
	std::istringstream ss(playlist);
	int i = 0;
	while (std::getline(ss, playlist, '|')) // name        song+song
	{
		if (i == 0)//name
		{
			name = playlist;
			++i;
		}
		else //song
		{
			std::string song = playlist;
			std::istringstream ss1(song);
			while (std::getline(ss1, song, '+'))
			{
				songs.push_back(song);
			}
		}
	}
}
std::ostream& operator<< (std::ostream& out, Playlist& playlist)
{
	out << playlist.name; 
	out << "|"; //indicator for ending of "name"

	std::list<std::string>::iterator it = playlist.songs.begin();
	if (it != playlist.songs.end())	//fixed problem: (song+song+song+)
	{
		out << *it;
		++it;
	}
	for (; it != playlist.songs.end(); ++it)
	{
		out << "+" << *it; // + separates different songs' names 
	}
	return out;
}