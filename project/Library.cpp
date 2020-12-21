#include "Library.h"
#include <iostream>
#include <string>

User& Library::get_user()
{
	return logged_user;
}

Playlist& Library::get_playlist()
{
	return loaded_playlist;
}


void Library::add_user(const User& other)
{
	logged_user = other;
}

void Library::add_playlist(const Playlist& other)
{
	loaded_playlist = other;
}



void Library::remove_user(const User& element)
{}

void Library::remove_playlist(const Playlist& element)
{}
//void Library::remove_album(const Album& element){}

