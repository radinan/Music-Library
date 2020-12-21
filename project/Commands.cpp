#include "Commands.h"
#include "User.h"
#include <string>

void Commands::sign_in(std::string& un, std::string& pw)
{
	//proverqva vyv faila?
	//moje f-q load user ;)
	User user; // danni ot faila
	user.set_is_logged(1);
	//library.add_user(user)
}
void Commands::sign_up(std::string& un, std::string& pw)
{
	User new_user(un, pw);
	//library.add_user(new_user);
	//zapisva vyv faila
	new_user.set_is_logged(1);
}
void Commands::change_data(int choice, std::string& input) 
{
	User user;//
	Playlist playlist;//
	if (choice == 1)
	{
		user.set_username(input);
	}
	else if(choice == 2)
	{
		user.set_password(input);
	}
	else if (choice == 3)
	{ 
		user.set_full_name(input);
	}
	else if (choice == 4)
	{ 
		user.set_birth_date(input);
	}
	else if (choice == 5) //dopis
	{

		std::cout << "Enter genre you want to add: ";
		std::cin >> input;
		user.add_genre(input);
	}
	else if (choice == 6)
	{
		std::cout << "Enter genre you want to remove: ";
		std::cin >> input;
		user.remove_genre(input);
	}

}


void Commands::add_song(std::string& name, std::string& artist, std::string& genre, 
						std::string& album, std::string& release_date) //oshte rabota
{
	Song song(name, artist, genre, album, release_date);
	//promqna v txt file
}
void Commands::rate_song(std::string& name, int rate)
{
	//proverqva dali ima vyv file-a
	Song song;
	song.set_rating(rate);
	//promqna v class i file
}

void Commands::generate_playlist(std::string& input) //dopis
{
	//string to char[]
	//tozi pyt validaciqta e tuk

	//f-q za syzdavane koqto priema char[]
	//save_playlist()
	//po default <username>'s playlist
	//????is_loaded = 1????
}
void Commands::save_playlist(std::string& name)
{

	//ako ima is_loaded == 1 vyv v-ra; ??(posle vyv file-a)??
	//ako nqma -> load_playlilst()
	Playlist p;
	p.change_name(name);
	//promqna v Library, User i faila
}
void Commands::load_playlist(std::string& name)
{
	//ako ima drug loadnat go zatvarqme
	//tyrsi pll po ime (vyv file-a)
	Playlist pl;//s (name)
	pl.load();
}
void Commands::show_all_info()
{
	//ako nqma is_loaded == 1 -> WRONG
	//cikyl za obhojdane na playlista
	//vika info() za vs pesen (ili pomoshtna funkciq v song)
}