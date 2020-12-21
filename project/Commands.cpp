#include "Commands.h"
#include "User.h"
#include "Library.h"
#include <string>
Library lib;

void Commands::sign_in(std::string& un, std::string& pw)
{
	//proverqva vyv faila
	User user; //f-q load_user() zadava st-ti ot faila
	lib.add_user(user);
}
void Commands::sign_up(std::string& un, std::string& pw)
{
	User new_user(un, pw);
	lib.add_user(new_user);
	//zapisva vyv faila
}
void Commands::change_data(int choice, std::string& input) 
{
	Playlist playlist;
	if (choice == 1)
	{
		lib.get_user().set_username(input);
	}
	else if(choice == 2)
	{
		lib.get_user().set_password(input);
	}
	else if (choice == 3)
	{ 
		lib.get_user().set_full_name(input);
	}
	else if (choice == 4)
	{ 
		lib.get_user().set_birth_date(input);
	}
	else if (choice == 5) //dopis
	{
		lib.get_user().add_genre(input);
	}
	else if (choice == 6)
	{
		lib.get_user().remove_genre(input);
	}
	//update-va file-a
}


void Commands::add_song(std::string& name, std::string& artist, std::string& genre, 
						std::string& album, std::string& release_date) 
{
	Song song(name, artist, genre, album, release_date);
	//promqna vyv file-a
}
void Commands::rate_song(std::string& name, int rate)
{
	//proverqva dali ima vyv file-a
	Song song; // s dannite ot faila
	//song.load(...) 
	song.set_rating(rate);
	//promqna v file
}

void Commands::generate_playlist(std::string& input) //dopis
{
	//f-q koqto da prerabotva inputa (returnva vector)
	//vector ot dvoiki <comanda,value> ->string

	//cikyl za obhojdane na vsichki komandi
	//za 1va komanda vzima ot faila podhodqshti elementi i gi dobavq vyv v-r
	//za dr komandi filtrira v-ra

	//save_playlist(..) po default "<username>'s playlist"

	//????is_loaded = 1????
}
void Commands::save_playlist(std::string& name)
{
	//ako ima v Library playlist s takova ime; ??(posle vyv file-a)??
	Playlist p; //otvarqme loadnitiq 
	p.change_name(name);
	//promqna vyv faila
	//ako nqma -> load_playlilst()
}
void Commands::load_playlist(std::string& name)
{
	//ako ima drug loadnat go zatvarqme
	//tyrsi pll po ime (vyv file-a)
	Playlist pl;//s (name)
	lib.add_playlist(pl);
	pl.all_songs_name();
}
void Commands::show_all_info()
{
	lib.get_playlist().all_songs_info();
}