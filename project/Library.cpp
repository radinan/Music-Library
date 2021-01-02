#include "Library.h"
#include <iostream>
#include <string>

User Library::get_user() const
{
	return curr_user;
}
Playlist Library::get_playlist() const
{
	return curr_playlist;
}


void Library::add_user(const User& other)
{
	curr_user = other;
}
void Library::add_playlist(const Playlist& other)
{
	curr_playlist = other;
}

void Library::add_song(const Song& other)
{
	//all_songs.insert(other);
}

