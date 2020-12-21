#include "Library.h"
#include <iostream>
#include <string>


void Library::add_user(const User& other)
{
	users.push_back(other);
}
void Library::add_song(const Song& other)
{
	songs.push_back(other);
}
void Library::add_playlist(const Playlist& other)
{
	playlists.push_back(other);
}
void Library::add_album(const Album& other)
{
	albums.push_back(other);
}


//moje da go izkaram navyn shte vidim
void Library::remove_user(const User& element)
{//shte vidim dali shte go ostavq vector
}
void Library::remove_song(const Song& element)
{}
void Library::remove_playlist(const Playlist& element)
{}
void Library::remove_album(const Album& element)
{}

