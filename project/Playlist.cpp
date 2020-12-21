#include "Playlist.h"


void Playlist::add_song(const Song& other)
{
	songs.push_back(other);
	size++;

}
void Playlist::remove_song(const Song& element)
{
	//mahane
	size--;
}

void Playlist::change_name(std::string& _name)
{
	//validation?
	name = _name;
}

void Playlist::load()
{
	is_loaded = 1;
}
void Playlist::unload()
{
	is_loaded = 0;
}