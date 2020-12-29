#include <iostream>
#include <fstream>
#include <string>

// NOTES
//moje da smenq std::string sys char*
//janrovete moje s enum
//moje validaciq sled vseki cin i posle
//funkciq izcqlo za validacii
//!!!predi exit tr se setnat vs bool na 0

class Songs
{
public:
	std::string name;
	std::string artist;
	std::string genre;
	std::string album;
	int release_year;
	std::pair<int, int> rating;

	friend std::ostream& operator << (std::ostream& out, Songs& song);
	friend std::istream& operator >> (std::istream& in, Songs& song);

};
std::ostream& operator << (std::ostream& out, Songs& song)
{
	//std::ofstream out("songs.txt");
	out << song.name << "\n" << song.artist << "\n" << song.genre << "\n" << song.album << "\n"
		<< song.release_year << "\n" << song.rating.first << " " << song.rating.second << "\n";
	//out.close();
	return out;
}
std::istream& operator >> (std::istream& in, Songs& song)
{

	std::getline(in, song.name);
	std::getline(in, song.artist);
	std::getline(in, song.genre);
	std::getline(in, song.album);
	in >> song.release_year; in.get();
	in >> song.rating.first;
	in >> song.rating.second; in.get();
	return in;
}


int main()
{
	std::pair<int, int> rate{ 5, 5 }, rate1{ 6,3 };
	Songs song{ "Name", "Artist", "genre", "album", 1876, rate},
			song1{ "First Name", "First Artist", "First genre", "First album", 10876, rate1};
	Songs songg, songg1;

	std::ofstream out("songs.txt");
	out << song << song1;
	out.close();

	std::ifstream in("songs.txt");
	in >> songg;
	in >> songg1;
	in.close();

	std::cout << songg << "\n" << songg1;

	return 0;
}
