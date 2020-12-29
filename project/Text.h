#pragma once

//text files:
//store data in the form of alphabets,numbers,special symbols
//less likely to become corrupted
//small error in a text file may simply show up (readable)
//several lines of text that are each followed by an End-of-Line (EOL) character

#include <iostream>
#include <fstream>
#include <string>

//adds line of text in the file
void write(const std::string& file_name, const std::string& line_text)
{
	std::ofstream out (file_name);
	std::ofstream out (file_name, std::ios::app); //to the end of the file

	if (!out.is_open())
		std::cout << "Unable to open file \n";
	out << line_text << "\n"; //decide later where u want to put the endl
	out.close();
}



void read(const std::string& file_name)
{
	std::ifstream in(file_name);
	if(!in.is_open())
		std::cout << "Unable to open file \n";
	
	//reads and prints symbol by symbol
	char symb;
	while (in.get(symb)) //whitespaces included
	{
		std::cout << symb;
	}

	//reads and prints word by word
	std::string word;
	while (in >> word) //without whitespaces
	{
		std::cout << word << " "; 
	}

	//reads and prints line by line
	std::string line;
	while (std::getline(in, line)) //getline reads till "\n"
	{
		std::cout << line << std::endl;
	}

	in.close();
}






//--(ofstream): Stream class to write on files (default ios::out)
//--(ifstream): Stream class to read from files (default ios::in)
//--(fstream) : Stream class to both from/to files. (default ios::out|ios::in)
//---------------------------------------------------------------------------------------------------------
// If the function is called with any value in that parameter the default mode is overridden, not combined.


//--open a file--//
//                                      open (filename, mode);  
//												 modes:
// ___________________________________________________________________________________________________________
// |ios::in | ios::out | ios::binary |   ios::ate    |   ios::app   | ios::trunc	                         |
// |  read  |  write   | binary mode | init position |  all outputs | if -> opened for output				 |
// |								 |  at the end   |   at the end | prev content -> deleted and replaced   |
// |_________________________________________________________________________________________________________|

bool open()
{
	std::ofstream file; 
	if (!file.is_open()) //if it's not opened
		file.open("example.txt");//open
	//or 
	//	std::ofstream file ("example.txt"); - opens file
	return file.is_open(); //returns true if it's opened
}

//--close a file--//
bool close()
{
	std::ofstream file;
	if (file.is_open()) //if it's opened
		file.close();   //close 
	return !file.is_open(); //returns true if it's not opened
}


//--write in a file--//
void write()
{
	std::ofstream file ("example.txt");
	if (file.is_open())
	{
		file << "Text on the first line.\n";
		file << "Text on the second line.\n";
		file.close();
	}
}

//--read from a file--//
void read()
{
	std::string line; //all elements in a line
	std::ifstream file ("example.txt");
	if (file.is_open())
	{
		while (std::getline(file, line)) //reads every line (till \n)
		{
			std::cout << line << "\n";
		}
		file.close();
	}
}

//            Checking state flags (all of them return a bool value)
// _____________________________________________________________________________
// |bad()______________________________________________________________________|
// |    ->true [reading or writing operation fails (not opened; no space)]     |
// |fail()_____________________________________________________________________|
// |    ->true [same cases] + [format error (letter when -> read an int num)]  |
// |eof()______________________________________________________________________|
// |    ->true [file open for reading -> the end]                              |
// |good()_____________________________________________________________________|
// |    ->false (checks all prev flags)                                        |
// |___________________________________________________________________________|
//  clear() can be used to reset the state flags

//          Random access (only for binary files).
//--get and put stream positioning--//
// ifstream (like istream) -> internal   -get-    position
// ofstream (like ostream) -> internal   -put-    position
// fstream (like iostream) -> both     -get|put-  position
// |------------------------------------------------------------|
// |      tellg()             and             tellp()           | (return streampos)
// |current get position                 current put position   |
// |------------------------------------------------------------|
// |      seekg()             and             seekp()           |
// | change the get position     	   change the put position  |
// |------------------------------------------------------------|
//   seekg ( position )           --position  is of type streampos
//   seekp ( position )
//   seekg ( offset, direction ); --offset    is of type streamoff
//   seekp ( offset, direction ); --direction is of type seekdir

//   ios::beg	offset counted from the beginning of the stream
//   ios::cur	offset counted from the current position
//   ios::end	offset counted from the end of the stream

int size()
{
	std::streampos end, begin;
	std::ifstream file("example.txt");
	begin = file.tellg();

	file.seekg(0, std::ios::end);
	end = file.tellg();

	return (end - begin);
}

//streampos - type used for buffer and file positioning
// position functions use:
// _________________________________________________________________________________|
// |___Type___|__Member type__|___________________Description_______________________| (more generic)
// |streampos | ios::pos_type |converted to/from streamoff + added/subtracted values|
// |streamoff | ios::off_type | AKA of fundamental integral types(int/long long)    |
// |--------------------------------------------------------------------------------|


