#include "Playlist.h"


void Playlist::add_song(const Song& other)
{
	songs.push_back(other);
	size++;
}
void Playlist::remove_song(std::string& _name)
{
	for (size_t i = 0; i < songs.size(); ++i) //ili i<size (se taq)
	{
		if(songs[i].get_name() == _name)
			songs.erase(songs.begin() + i);
	}
	size--;
}

void Playlist::change_name(std::string& _name)
{
	//validation?
	name = _name;
}

void Playlist::all_songs_name()
{
	for (size_t i = 0; i < songs.size(); ++i) //ili i<size (se taq)
	{
		std::cout << songs[i].get_name() << std::endl;
	}
}
void Playlist::all_songs_info()
{
	for (size_t i = 0; i < songs.size(); ++i) 
	{
		songs[i].song_info();
		std::cout << std::endl;
	}
}

