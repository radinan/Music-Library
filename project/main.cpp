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

class Users
{
public:
	char un[10];
	char pw[10];


	friend std::ostream& operator << (std::ostream& out, Users& user);
	//friend std::istream& operator >> (std::istream& in, Users& user);
};
std::ostream& operator << (std::ostream& out, Users& user)
{
	out << user.un << "\n" << user.pw<<"\n";
	return out;
}

void* operator new(size_t size)
{
	std::cout << "Alocating: " << size << "bytes\n";
	return malloc(size);
}

class Test
{
public:
	char commands[5][10] ;
	Test()
	{
		commands[0][0] = 'a';
		commands[0][1] = 'b';
		commands[1][0] = 'c';

		std::cout << "Constructor" << std::endl;
	}
	~Test()
	{
		std::cout << "Destructor" << std::endl;
	}
};
class TestTest
{
public:
	Test commanda;
	TestTest()
	{
		std::cout << "2Constructor2" << std::endl;

	}
	~TestTest()
	{
		std::cout << "2Destructor2" << std::endl;

	}
};

int main()
{
	/*std::pair<int, int> rate{ 5, 5 }, rate1{ 6,3 };
	Songs song{ "A", "A", "A", "A", 1876, rate },
		song1{ "B", "B", "B", "B", 10876, rate1 };
	Songs songg, songg1, songa;

	std::ofstream out("songs.txt");
	out << song << song1;
	out.close();

	std::string str = "First Name", filestr;
	std::ifstream in("songs.txt");
	for( ; ;)
	{
		in >> songg;
		if (songg.name == str)
		{
			std::cout << songg << "\n";// << songg1;

			break;
		}
		std::cout << songg << "\n";// << songg1;

	}

	in.close();*/
	
	/*Users user{ "first","pw" }, user1{ "second","pass" }, user2{ "third","psa" };
	
	std::ofstream out("users.txt", std::ios::out | std::ios::binary);
	out.write((char*)&user, sizeof(Users));
	out.write((char*)&user1, sizeof(Users));
	out.write((char*)&user2, sizeof(Users));
	out.close();

	Users uuser;
	std::string str = "third";

	std::ifstream file("users.txt", std::ios::in | std::ios::binary);
	file.seekg(0);
	int n = sizeof(Songs);
	while (file.read((char*)&uuser, sizeof(Users)) && uuser.un != str){}
	if (uuser.un == str)
		std::cout << uuser;
	file.close();*/

	//char ya[5][10] = { "ysssa", "aa", "yo", "za", "sa" };
	//std::cout << ya[2]; //qkoooo
	Test a;
	TestTest ya;
	//no heap allocation here ;)
	

	return 0;
}
