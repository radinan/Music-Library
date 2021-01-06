#pragma once
#include <iostream>
#include <string>
#include <fstream>

//starting the programm		 -> all data from txt file -> AVL Tree
//exiting the programm(save) -> all data from AVL Tree -> txt file

enum class Sort_type {name, release_year, genre, rating}; //sorting types
class Song
{
private:
	std::string name;
	std::string artist; 
	std::string genre; 
	std::string album;
	size_t release_year =0; 
	std::pair <int, int> rating; //num of votes, sum of votes
private:
	//constructor helpers
	void copy(const Song& other);
	void clear();
	//!add bool funcs for data validation ;)
public:
	static Sort_type sort_type; //same for all objects
public:
	//constructors
	Song();
	Song(const std::string& _name, const std::string& _artist, const std::string& _genre,
		 const std::string& _album, int _release_year);
	Song& operator= (const Song& other);
	~Song();

	//public or private? setters and getters
	void set_rating(int rate);
	double get_rating() const;
	std::string get_name() const;

	//informative methods
	void song_info() const;

	//overloading operators
	friend bool operator > (const Song& song, size_t value);
	friend bool operator < (const Song& song, size_t value);
	friend bool operator == (const Song& song, size_t value);
	friend bool operator == (const Song& song, std::string str);
	friend bool operator != (const Song& song, size_t value);
	friend bool operator != (const Song& song, std::string str);

	friend std::ostream& operator << (std::ostream& out, Song& song); 
	friend std::istream& operator >> (std::istream& in, Song& song); 

	friend bool operator>(const Song& left, const Song& right);
	friend bool operator<(const Song& left, const Song& right);
	friend bool operator==(const Song& left, const Song& right);
	friend bool operator!=(const Song& left, const Song& right);

};

