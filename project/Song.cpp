#include "Song.h"

//constructor helpers
void Song::copy(const Song& other)
{
	name = other.name;
	artist = other.artist;
	genre = other.genre;
	album = other.album;
	release_year = other.release_year;
	//reserve?
	rating = other.rating;
}

//constructors
Song::Song()
{
	/*name.reserve(20);
	name = "";
	artist.reserve(20);
	artist = "";
	genre.reserve(20);
	genre = "";
	album.reserve(20);
	album = "";
	//release_year = 0;*/

	rating.first = 0;
	rating.second = 0;
}
Song::Song(const std::string& _name, const std::string& _artist, const std::string& _genre, 
		   const std::string& _album, size_t _release_year)
{
	name = _name;
	artist = _artist;
	genre = _genre;
	album = _album;
	release_year = _release_year;

	rating.first = 0;
	rating.second = 0;
}
Song& Song::operator= (const Song& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}
Song::~Song()
{
}

//setters and getters
void Song::set_rating(size_t rate)
{
	++rating.first;
	rating.second += rate;
}
double Song::get_rating() const
{
	if (rating.first == 0)
		return 0;
	else
		return (double)rating.second / rating.first; //casting size_t->double
}
std::string& Song::get_name() 
{
	return name;
}
const std::string& Song::get_genre() const
{
	return genre;
}
const size_t& Song::get_year() const
{
	return release_year;
}

//informative methods
void Song::song_info() const
{
	std::cout << "Name: " << name << "\n"
		<< "Artist: " << artist << "\n"
		<< "Genre: " << genre << "\n"
		<< "Album" << album << "\n"
		<< "Release date: " << release_year << "\n"
		<< "Rating: " << get_rating()<<"\n";
}

//overloading operators
std::ostream& operator << (std::ostream& out, Song& song)
{
	out << song.name << '\n'
		<< song.artist << '\n'
		<< song.genre << '\n'
		<< song.album << '\n'
		<< song.release_year << '\n'
		<< song.rating.first << " " << song.rating.second << '\n'; //no appending here; directly re-write the file so '\n' is not a problem
	return out;
}
std::istream& operator >> (std::istream& in, Song& song)
{
	std::getline(in, song.name);
	std::getline(in, song.artist);
	std::getline(in, song.genre);
	std::getline(in, song.album);
	in >> song.release_year; in.get(); //new line
	in >> song.rating.first; in >> song.rating.second; in.get(); //new line
	return in;
}
bool operator==(const Song& left, const Song& right) 
{
	return left.name == right.name &&
		left.release_year == right.release_year &&
		left.genre == right.genre &&
		left.get_rating() == right.get_rating(); 
}
bool operator!=(const Song& left, const Song& right) 
{
	return left.name != right.name &&
		left.release_year != right.release_year &&
		left.genre != right.genre &&
		left.get_rating() != right.get_rating();
}
