#include "Fild.h"
#include <vector>
#include <iomanip>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


Fild& Fild::Instance()
{
	static Fild theSingleInstance;
	return theSingleInstance;
}

std::vector<int> Fild::Get_fild_players(string _player_id)
{
	std::vector<int> result;
	for (int i = 0; i < fild.size(); i++) {
		string id = fild[i].Get_cell_id_hero();
		if (id == _player_id) {
			std::cout << i <<"\t";
			result.push_back(i);
		}
	}
	if (result.size() == 0) {
		std::cout << "\nNo such players\n";
	}
	return result;
}

std::vector<std::string> Fild::Get_fild_fractions(int _fraction_id)
{
	std::vector<std::string> result;

	for (int i = 0; i < players.size(); i++) {
		int index = std::stoi(players[i].Get_player_fraction_id());
		if (index == _fraction_id) {
			std::cout << players[i].Get_player_id() << "\t";
			result.push_back(players[i].Get_player_id());
		}
	}
	if (result.size() == 0) {
		std::cout << "\nNo such players\n";
	}
	return result;
}

void Fild::drawHoneycomb(int n)
{	
	for (int j=0; j < n; j++)
	{
		for (int i=0; i < n; i++)
		{
			if (i % 2) std::cout << "__";
			else std::cout << "/  \\";
		}
		if (j) std::cout << "/";
		std::cout << "\n";

		std::cout << "\\";
		for (int i=0; i < n; i++)
		{
			if (i % 2) std::cout << "/  \\";
			else std::cout << "__";
		}
		std::cout << "\n";
	}
}
