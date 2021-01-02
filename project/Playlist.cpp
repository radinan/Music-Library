#include "Playlist.h"


void Playlist::add_song(const Song& other)
{
	if (size + 1 <= max_size  ) //if there is free space in the playlist
	{
		songs[size] = other;
		++size;

	}
	else
		std::cout << "No free space in the playlist \n";
}
void Playlist::remove_song(const std::string& _name) //removing it from the playlist, not deleting it from the file
{
	if (size == 0)
		return;

	for (int i = 0; i < size; ++i)
	{
		if (songs[i].get_name() == _name)
		{
			for (int j = i + 1; j < size; ++j, ++i)
			{
				songs[i] = songs[j];
			}
		}
	}
	
	--size;
}

void Playlist::change_name(const std::string& _name)
{
	//validation
	name = _name;
}

void Playlist::all_songs_name() const
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << songs[i].get_name() << std::endl;
	}
}
void Playlist::all_songs_info() const
{
	for (int i = 0; i < size; ++i) 
	{
		songs[i].song_info();
		std::cout << std::endl;
	}
}

