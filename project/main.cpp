#include <iostream>
#include <string>
//#include "AVLTree.h"
//#include "Library.h"
//#include "User.h"
#include "Library.h"


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
	//lib.generate_playlist(lib);

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
	//add user.txt with admin(or user)
	Library lib;//created library
	int input = -1;
	lib.welcome();
	while(input != 0)//eternal loop
	{
		std::cout << std::endl << "Enter your command: ";
		std::cin >> input;
		std::cout << std::endl;
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
			lib.help();
			break;
		}
		case 2:
		{
			std::cout << "---Sign in---\n";
			lib.sign_in();
			break;
		}
		case 3:
		{
			std::cout << "---Sign up---\n";
			lib.sign_up();
			break;
		}
		case 4:
		{
			std::cout << "---Change data---\n";
			lib.change_data();
			break;
		}
		case 5:
		{
			std::cout << "---Save changes---\n";
			lib.save_user_data();
			break;
		}
		case 6:
		{
			std::cout << "---Add song---\n"; //ebano e
			lib.add_song();
			break;
		}
		case 7:
		{
			std::cout << "---Rate song---\n";
			lib.rate_song();
			break;
		}
		case 8:
		{
			std::cout << "---Generate playlist---\n"; //not working
			lib.generate_playlist();
			break;
		}
		case 9:
		{
			std::cout << "---Change playlist's name---\n";
			lib.save_playlist();
			break;
		}
		case 10:
		{
			std::cout << "---Load playlist---\n";
			lib.load_playlist();
			break;
		}
		case 11:
		{
			std::cout << "---Show all song's info---\n";
			lib.show_all_info();
			break;
		}
		}
	}

	lib.save_songs();
	
	std::cout << "END\n";
}
