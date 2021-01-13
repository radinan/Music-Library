#include "Song.h"

Priority Song::priority = Priority::name; //by default by name

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
//constructors
Song::Song()
{
	name.reserve(20);
	name = "";
	artist.reserve(20);
	artist = "";
	genre.reserve(20);
	genre = "";
	album.reserve(20);
	album = "";
	//release_year = 0;

	rating.first = 0;
	rating.second = 0;
}
Song::Song(const std::string& _name, const std::string& _artist, const std::string& _genre, 
		   const std::string& _album, int _release_year)
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
		clear();
		copy(other);
	}
	return *this;
}
Song::~Song()
{
	clear();
}

//setters and getters
void Song::set_rating(int rate)
{
	++rating.first;
	rating.second += rate;
}
double Song::get_rating() const
{
	if (rating.first == 0)
		return 0;
	else
		return (double)rating.second / rating.first; //casting int->double
}
std::string Song::get_name() const
{
	return name;
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
	in >> song.release_year; in.get(); //new line
	in >> song.rating.first; in >> song.rating.second; in.get(); //new line
	return in;
}

//more operators overloading
bool operator > (const Song& song, size_t value) //by year
{
	switch (Song::priority)
	{
	case Priority::release_year:
		return song.release_year > value; break;
	}
}
bool operator < (const Song& song, size_t value) //by year 
{
	switch (Song::priority)
	{
	case Priority::release_year:
		return song.release_year < value; break;
	}
}
bool operator == (const Song& song, size_t value) //by year
{
	switch (Song::priority)
	{
	case Priority::release_year:
		return song.release_year == value; break;
	}
}
bool operator != (const Song& song, size_t value) //by year
{
	switch (Song::priority)
	{
	case Priority::release_year:
		return song.release_year != value; break;
	}
}

bool operator > (const Song& song, double value) //by rating
{
	switch (Song::priority)
	{
	case Priority::rating:
		return song.get_rating() > value; break;
	}
}
bool operator < (const Song& song, double value) //by rating
{
	switch (Song::priority)
	{
	case Priority::rating:
		return song.get_rating() < value; break;
	}
}
bool operator == (const Song& song, double value) //by rating
{
	switch (Song::priority)
	{
	case Priority::rating:
		return song.get_rating() == value; break;
	}
}
bool operator != (const Song& song, double value) //by rating
{
	switch (Song::priority)
	{
	case Priority::rating:
		return song.get_rating() != value; break;
	}
}

bool operator > (const Song& song, std::string str)
{
	switch (Song::priority)
	{
	case Priority::name:
		return song.name > str; break;
	case Priority::genre:
		return song.genre > str; break;
	}
}
bool operator < (const Song& song, std::string str)
{
	switch (Song::priority)
	{
	case Priority::name:
		return song.name < str; break;
	case Priority::genre:
		return song.genre < str; break;
	}
}
bool operator == (const Song& song, std::string str) //by name or genre
{
	switch (Song::priority)
	{
	case Priority::name:
		return song.name == str; break;
	case Priority::genre:
		return song.genre == str; break;
	}
}
bool operator != (const Song& song, std::string str) //by name or genre
{
	switch (Song::priority)
	{
	case Priority::name:
		return song.name != str; break;
	case Priority::genre:
		return song.genre != str; break;
	}
}

//Priority: name, release_year, genre, rating //without break?
bool operator>(const Song& left, const Song& right)
{
	switch (Song::priority)
	{
	case Priority::name:
		if (left.name == right.name)
		{
			if (left.release_year == right.release_year)
			{
				if (left.genre == right.genre)
				{
					return left.get_rating() > right.get_rating();
					break; 
				}
				return left.genre > right.genre;
				break;
			}
			return left.release_year > right.release_year;
			break;
		}
		return left.name > right.name;
		break;
	case Priority::release_year:
		if (left.release_year == right.release_year)
		{
			if (left.name == right.name)
			{
				if (left.genre == right.genre)
				{
					return left.get_rating() > right.get_rating();
					break;
				}
				return left.genre > right.genre;
				break;
			}
			return left.name > right.name;
			break;
		}
		return left.release_year > right.release_year;
		break;
	case Priority::genre:
		if (left.genre == right.genre)
		{
			if (left.name == right.name)
			{
				if (left.release_year == right.release_year)
				{
					return left.get_rating() > right.get_rating();
					break;
				}
				return left.release_year > right.release_year; 
				break;
			}
			return left.name > right.name;
			break;
		}
		return left.genre > right.genre;
		break;

	case Priority::rating:
		if (left.get_rating() == right.get_rating())
		{
			if (left.name == right.name)
			{
				if (left.release_year == right.release_year)
				{
					return left.genre > right.genre;
					break;
				}
				return left.release_year > right.release_year;
				break;
			}
			return left.name > right.name;
			break;
		}
		return left.get_rating() > right.get_rating();
		break;
	}
}
bool operator<(const Song& left, const Song& right) 
{
	switch (Song::priority)
	{
	case Priority::name:
		if (left.name == right.name)
		{
			if (left.release_year == right.release_year)
			{
				if (left.genre == right.genre)
				{
					return left.get_rating() < right.get_rating();
					break;
				}
				return left.genre < right.genre;
				break;
			}
			return left.release_year < right.release_year;
			break;
		}
		return left.name < right.name;
		break;
	case Priority::release_year:
		if (left.release_year == right.release_year)
		{
			if (left.name == right.name)
			{
				if (left.genre == right.genre)
				{
					return left.get_rating() < right.get_rating();
					break;
				}
				return left.genre < right.genre;
				break;
			}
			return left.name < right.name;
			break;
		}
		return left.release_year < right.release_year;
		break;
	case Priority::genre:
		if (left.genre == right.genre)
		{
			if (left.name == right.name)
			{
				if (left.release_year == right.release_year)
				{
					return left.get_rating() < right.get_rating();
					break;
				}
				return left.release_year < right.release_year;
				break;
			}
			return left.name < right.name;
			break;
		}
		return left.genre < right.genre;
		break;

	case Priority::rating:
		if (left.get_rating() == right.get_rating())
		{
			if (left.name == right.name)
			{
				if (left.release_year == right.release_year)
				{
					return left.genre < right.genre;
					break;
				}
				return left.release_year < right.release_year;
				break;
			}
			return left.name < right.name;
			break;
		}
		return left.get_rating() < right.get_rating();
		break;
	}
}
bool operator==(const Song& left, const Song& right) 
{
	switch (Song::priority)
	{
	case Priority::name:
		return left.name == right.name; break;

	case Priority::release_year:
		return left.release_year == right.release_year; break;

	case Priority::genre:
		return left.genre == right.genre; break;

	case Priority::rating:
		return left.get_rating() == right.get_rating(); break;
	}
}
bool operator!=(const Song& left, const Song& right) 
{
	switch (Song::priority)
	{
	case Priority::name:
		return left.name != right.name; break;

	case Priority::release_year:
		return left.release_year != right.release_year; break;

	case Priority::genre:
		return left.genre != right.genre; break;

	case Priority::rating:
		return left.get_rating() != right.get_rating(); break;
	}
}
