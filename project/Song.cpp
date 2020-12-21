#include "Song.h"


Song::Song()
{
	rating.first = 0;
	rating.second = 0;
}
Song::Song(std::string& _name, std::string& _artist, std::string& _genre, std::string& _album,
			std::string& _release_date)
{
	name = _name;
	artist = _artist;
	genre = _genre;
	album = _album;
	release_date = _release_date;
}

void Song::set_rating(int rate)
{
	++rating.first;
	rating.second += rate;
}
double Song::get_rating()
{
	return (double)rating.second / rating.first; //cast-vam, za da ne vyrne int
}

std::string& Song::get_name()
{
	return name;
}

void Song::song_info()
{
	std::cout << "Name: " << name << "\n"
		<< "Artist: " << artist << "\n"
		<< "Genre: " << genre << "\n"
		<< "Album" << album << "\n"
		<< "Release date: " << release_date << "\n"
		<< "Rating: " << get_rating();
}