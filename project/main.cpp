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
	Library lib;

	User user1("user1", "useruser");
	lib.add_user(user1);
	lib.get_user().add_fav_genre("a");
	lib.get_user().add_fav_genre("indie");
	std::unordered_set<std::string> genres = lib.get_user().get_fav_genres(); 


	Song song1("a", "b", "a", "a", 1), song2("A", "B", "a", "a", 5),
		song3("AA", "BB", "indie", "a", 6), song4("AAA", "BB", "indie", "a", 6),
		song5("aa", "bb", "heavy metal", "A", 7);
	AVLTree tree;
	tree.insert(song1);
	tree.insert(song2);
	tree.insert(song3);
	tree.insert(song4);
	tree.insert(song5);

	Commands::generate_playlist(lib);
}
