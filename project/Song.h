#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <fstream>

//starting the programm		 -> all data from txt file -> AVL Tree
//exiting the programm(save) -> all data from AVL Tree -> txt file
class Song
{
private: //changing attributes to be char* instead of string
	std::string name;
	std::string artist; //izpylnitel
	std::string genre; //moje da e enum??
	std::string album;
	int release_year; //mmoje i da go smenq na int
	std::pair <int, int> rating; //broi glasuvali, sbor ot glasove
private:
	void copy(const Song& other);
	void clear();
public:
	Song();
	Song(std::string& _name, std::string& _artist, std::string& _genre, 
		std::string& _album, int _release_year);
	Song& operator= (const Song& other);
	~Song();

	//public or private? setters and getters
	void set_rating(int rate);
	double get_rating();

	std::string& get_name();
	void song_info();

	//overloading operators
	friend std::ostream& operator << (std::ostream& out, Song& song);
	friend std::istream& operator >> (std::istream& in, Song& song);
};

