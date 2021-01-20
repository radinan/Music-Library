#pragma once
#include <iostream>
#include <string>
#include <fstream>

//starting the programm		 -> all data from txt file -> unordered map
//exiting the programm(save) -> all data from unordered map -> txt file

class Song
{
private:
	std::string name;
	std::string artist; 
	std::string genre; 
	std::string album;
	size_t release_year = 0; 
	std::pair <size_t, size_t> rating; //num of votes, sum of votes
private:
	//constructor helpers
	void copy(const Song& other);
	//!add bool funcs for data validation ;)
public:
	//constructors
	Song();
	Song(const std::string& _name, const std::string& _artist, const std::string& _genre,
		 const std::string& _album, size_t _release_year);
	Song& operator= (const Song& other);
	~Song();

	//public or private? setters and getters
	void set_rating(size_t rate);
	double get_rating() const;
	std::string& get_name();
	const std::string& get_genre() const;
	const size_t& get_year() const;

	//informative methods
	void song_info() const;

	//overloading operators

	friend std::ostream& operator << (std::ostream& out, Song& song); 
	friend std::istream& operator >> (std::istream& in, Song& song); 
	friend bool operator==(const Song& left, const Song& right);
	friend bool operator!=(const Song& left, const Song& right);


};

