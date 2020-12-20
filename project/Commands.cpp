#include "Commands.h"
#include <string>

void Commands::welcome()
{
	std::cout << "Welcome to ... \n";
	// .............
}
void Commands::help()
{
	std::cout << "List of commands: \n";
	//1. 2. 3. ....
}

void Commands::sign_in()
{
	std::string un,
				pw;

	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;
	//validation
	//proverqva vyv faila?
	//logged in = 1
}
void Commands::sign_up()
{
	std::string un,	
				pw; //~~r_pw

	std::cout << "Enter username: ";
	std::cin >> un;
	std::cout << "Enter password: ";
	std::cin >> pw;
	//~~repeat password
	//validation
	//construktor
	//zapisva vyv faila
	//logged_in
}
void Commands::change_data()
{
	std::string input;
	//~~moje da gi izvadq v pomoshtna f-q
	std::cout << 
		"Choose: \n" <<
		"1. username \n" <<
		"2. password \n" <<
		"3. full name \n" <<
		"4. birth date \n" <<
		"5. favourite genres \n";
	std::cin >> input; //da proverq dali ima problem s "input" v if-ovete
	if (input == "1")
	{
		std::cout << "Enter new username: ";
		std::cin >> input;
		//validaciq
		//promqna
	}
	else if(input == "2")
	{
		//~potvyrjdavane na starata
		std::cout << "Enter new password: ";
		std::cin >> input;
		//validaciq
		//promqna
	}
	else if (input == "3")
	{ 
		std::cout << "Enter new full name: ";
		std::cin >> input;
		//validaciq
		//promqna
	}
	else if (input == "4")
	{ 
		std::cout << "Enter new bith date: ";
		std::cin >> input;
		//validaciq
		//promqna
	}
	else if (input == "5")
	{ 
		std::cout <<
			"Choose: \n" <<
			"1. add \n" <<
			"2. remove \n";
		std::cin >> input; 
		if (input == "1")
		{
			std::cout << "Enter genre you want to add: ";
			std::cin >> input;
			//validaciq
			//promqna
		}
		else if (input == "2")
		{
			std::cout << "Enter genre you want to remove: ";
			std::cin >> input;
			//validaciq
			//promqna
		}
		else
		{
			std::cout << "Wrong input\n";
		}
	}

}


void Commands::add_song()
{
	std::string name, artist, genre,
				album, release_date;
	//preduprejdenie che tr se popylva :DD
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter artist: ";
	std::cin >> artist;
	std::cout << "Enter genre: ";
	std::cin >> genre;
	std::cout << "Enter album: ";
	std::cin >> album;
	std::cout << "Enter release date: ";
	std::cin >> release_date;
	//validaciq
	//szydava Song
	//promqna v txt file
}
void Commands::rate_song()
{
	std::string name;
	int rating = 0;
	std::cout << "Enter song: ";
	std::cin >> name;
	//proverqva dali ima vyv file-a
	std::cout << "Enter rating: ";
	std::cin >> rating;
	//validaciq
	//promqna v class i file
}

void Commands::generate_playlist()
{
	//moje pomoshtna funkciq
	std::string input;
	std::cout << "Choose criteria: \n" <<
		"1. rating higher than \n" <<
		"2. icluded genres \n" <<
		"3. excluded genres \n" <<
		"4. only favourite genres \n" <<
		"5. before year \n" <<
		"6. from year \n" <<
		"7. after year \n";
	//moje da e v while cikyl
	std::cin >> input;
	//validaciq
	//moje da se zapazva v char* i da se chetat el-te s ++
	//???
	//syzdavane i zapazvane
	//save_playlist()
	//po default <username>'s playlist
	//is_loaded = 1
}
void Commands::save_playlist()
{
	std::string input;
	//ako ima is_loaded == 1
	//ako nqma -> load()
	std::cout << "Enter name: ";
	std::cin >> input;
	//validaciq
	//promqna v klasa i faila
}
void Commands::load_playlist()
{
	//ako ima loadnat go zatvarqme
	std::string input;
	std::cout << "Enter name: ";
	std::cin >> input;
	//validaciq
	//tyrsi pll po ime 
	//-> is_loaded = 1
}
void Commands::show_all_info()
{
	//ako nqma is_loaded == 1 -> WRONG
	//cikyl za obhojdane na playlista
	//vika info() za vs pesen (ili pomoshtna funkciq v song)
}