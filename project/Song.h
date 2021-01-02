#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <fstream>

//starting the programm		 -> all data from txt file -> AVL Tree
//exiting the programm(save) -> all data from AVL Tree -> txt file
class Song
{
private:
	std::string name;
	std::string artist; 
	std::string genre; 
	std::string album;
	int release_year =0; 
	std::pair <int, int> rating; //num of votes, sum of votes
private:
	void copy(const Song& other);
	void clear();
	//bool funcs for data validation ;)
public:
	Song();
	Song(const std::string& _name, const std::string& _artist, const std::string& _genre,
		 const std::string& _album, int _release_year);
	Song& operator= (const Song& other);
	~Song();

	//public or private? setters and getters
	void set_rating(int rate);
	double get_rating() const;

	std::string get_name() const;
	void song_info() const;

	//overloading operators
	friend std::ostream& operator << (std::ostream& out, Song& song); //const?
	friend std::istream& operator >> (std::istream& in, Song& song); //const?
};

