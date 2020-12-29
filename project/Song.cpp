#include "Song.h"

void Song::copy(const Song& other)
{
	name = other.name;
	artist = other.artist;
	genre = other.genre;
	album = other.album;
	release_year = other.release_year;
	rating = other.rating;
}
void Song::clear()
{
	name.clear(); //automatically calls str destructor
	artist.clear();
	genre.clear();
	album.clear();
	release_year = 0;
	rating.first = 0;
	rating.second = 0;
}

Song::Song()
{
	rating.first = 0;
	rating.second = 0;
}
Song::Song(std::string& _name, std::string& _artist, std::string& _genre, std::string& _album,
			int _release_year)
{
	name = _name;
	artist = _artist;
	genre = _genre;
	album = _album;
	release_year = _release_year;
	//think about pairs
	rating.first = 0;
	rating.second = 0;
}
Song& Song::operator= (const Song& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}
Song::~Song()
{
	clear();
}




void Song::set_rating(int rate)
{
	++rating.first;
	rating.second += rate;
}
double Song::get_rating()
{
	return (double)rating.second / rating.first; //casting int->double
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
		<< "Release date: " << release_year << "\n"
		<< "Rating: " << get_rating();
}

std::ostream& operator << (std::ostream& out, Song& song)
{
	out << song.name << "\n" 
		<< song.artist << "\n" 
		<< song.genre << "\n" 
		<< song.album << "\n"
		<< song.release_year << "\n" 
		<< song.rating.first << " " << song.rating.second << "\n";
	return out;
}
std::istream& operator >> (std::istream& in, Song& song)
{
	std::getline(in, song.name);
	std::getline(in, song.artist);
	std::getline(in, song.genre);
	std::getline(in, song.album);
	in >> song.release_year; in.get();
	in >> song.rating.first; in >> song.rating.second; in.get();
	return in;
}
