#include "Playlist.h"


void Playlist::add_song(const Song& other)
{
	if (size + 1 < max_size) //if there is free space in the playlist
	{
		++size;
		songs[size] = other;
	}
	else
		std::cout << "No free space in the playlist \n";
}
void Playlist::remove_song(std::string& _name) //removing it from the playlist, not deleting it from the library
{
	for (size_t i = 0; i < size; ++i) 
	{
		if (songs[i].get_name() == _name)
		{
			for (size_t j = i + 1; j < size; ++j)
				songs[i] = songs[j];
			break;
		}
	}
	--size;
}

void Playlist::change_name(std::string& _name)
{
	//validation?
	name = _name;
}

void Playlist::all_songs_name()
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << songs[i].get_name() << std::endl;
	}
}
void Playlist::all_songs_info()
{
	for (size_t i = 0; i < size; ++i) 
	{
		songs[i].song_info();
		std::cout << std::endl;
	}
}

