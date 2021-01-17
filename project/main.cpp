#include <iostream>
#include <string>
//#include "AVLTree.h"
//#include "Library.h"
//#include "User.h"
#include "Commands.h"


// NOTES
//moje validaciq sled vseki cin i posle
//funkciq izcqlo za validacii

int main()
{

	/*Song song1("A", "B", "rock", "D", 5), song2("AA", "BB", "rock", "DD", 6);
	Song::property = Property::genre;
	AVLTree tr;
	tr.insert(song1);
	tr.insert(song2);

	AVLTree tr1;
	std::string genr = "rock";
	tr1.genre_minus(genr,tr);
	tr1.inorder();*/


	/*Song song1("a", "b", "a", "a", 1), song2("A", "B", "a", "a", 5),
		song3("AA", "BB", "indie", "a", 6), song4("AAA", "BB", "indie", "a", 6),
		song5("aa", "bb", "heavy metal", "A", 7);
	AVLTree tree;
	tree.insert(song1);
	tree.insert(song2);
	tree.insert(song3);
	tree.insert(song4);
	tree.insert(song5);

	Library lib(tree);

	User user1("user1", "useruser");
	lib.add_user(user1);
	lib.get_user().add_fav_genre("a");
	lib.get_user().add_fav_genre("indie");
	std::unordered_set<std::string> genres = lib.get_user().get_fav_genres();

	*/
	//Commands::generate_playlist(lib);

	//for tests
	/*Song song1("a", "a", "a", "a", 1), song2("b", "b", "b", "b", 2), song3("c", "c", "c", "c", 3),
		 song4("d", "d", "d", "d", 4), song5("e", "e", "e", "e", 5);

	AVLTree tree;
	tree.insert(song1);
	tree.insert(song2);
	tree.insert(song3);
	tree.insert(song4);
	tree.insert(song5);*/

	/*
	//TEST Playlist funcs in tree
	tree.find("a")->data.set_rating(4);
	tree.find("b")->data.set_rating(4);

	Song::priority = Priority::rating;
	AVLTree cpy(tree); //the copy constructor copies all data in a new priority way
	AVLTree empt;
	cpy.rating_bigger(3, empt); //delete elements 

	Song::priority = Priority::release_year; //!!don't forget!
	AVLTree emp;
	//std::string str = "a";
	cpy.year_bigger(1, emp);
	cpy.inorder();*/


	//!!!consider moving class commands into class library!!!
	//test check
	Library lib;//created library
	int input = -1;
	Commands::welcome();
	while(input != 0)//eternal loop
	{
		std::cin >> input;
		switch (input)
		{
		case 0:
		{
			std::cout << "Exiting..\n";
			break; 
		}
		case 1:
		{
			std::cout << "---Help--- \n";
			Commands::help();
			break;
		}
		case 2:
		{
			std::cout << "---Sign in---\n";
			Commands::sign_in(lib);
			break;
		}
		case 3:
		{
			std::cout << "---Sign up---\n";
			Commands::sign_up(lib);
			break;
		}
		case 4:
		{
			std::cout << "---Change data---\n";
			Commands::change_data(lib);
			break;
		}
		case 5:
		{
			std::cout << "---Save changes---\n";
			Commands::save_user_data(lib);
			break;
		}
		case 6:
		{
			std::cout << "---Add song---\n";
			Commands::add_song(lib);
			break;
		}
		case 7:
		{
			std::cout << "---Rate song---\n";
			Commands::rate_song(lib);
			break;
		}
		case 8:
		{
			std::cout << "---Generate playlist---\n";
			Commands::generate_playlist(lib);
			break;
		}
		case 9:
		{
			std::cout << "---Change playlist's name---\n";
			Commands::save_playlist(lib);
			break;
		}
		case 10:
		{
			std::cout << "---Load playlist---\n";
			Commands::load_playlist(lib);
			break;
		}
		case 11:
		{
			std::cout << "---Show all song's info---\n";
			Commands::show_all_info(lib);
			break;
		}
		}
	}
	Commands::save_songs;
	

	std::cout << "END";
}
