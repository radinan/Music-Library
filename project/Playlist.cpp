#include "Playlist.h"
#include <sstream>


void Playlist::copy(const Playlist& other)
{
	name = other.name;
	songs = other.songs;
}


//fill:
Playlist::Playlist(){} 
Playlist& Playlist::operator=(const Playlist& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}
Playlist::~Playlist(){}



void Playlist::set_name(const std::string& _name)
{
	//validation
	name = _name;
}
void Playlist::set_songs(std::set<std::string>& other_songs)
{
	for (auto& itr : other_songs)
	{
		songs.push_back(itr);
	}
}
void Playlist::add_song(Song& other) //song's name?
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
std::list<std::string>& Playlist::get_songs()
{
	return songs;
}

size_t Playlist::get_size()
{
	return songs.size();
}


void Playlist::load_playlist(std::string& line)
{
	std::istringstream ss(line);
	int i = 0;
	while (std::getline(ss, line, '|')) // name        song+song
	{
		if (i == 0)//name
		{
			name = line;
			++i;
		}
		else //song
		{
			std::string song = line;
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
	if (!playlist.songs.empty()) //if the playlist is not empty
	{
		out << playlist.name;
		out << "|"; //indicator for ending of "name"

		std::list<std::string>::iterator it = playlist.songs.begin();
		//fixed problem: (song+song+song+)
		if (it != playlist.songs.end())	//first song
		{
			out << *it;
			++it;
		}
		for (; it != playlist.songs.end(); ++it)
		{
			out << "+" << *it; // + separates different songs' names 
		}
	}
	return out;
}