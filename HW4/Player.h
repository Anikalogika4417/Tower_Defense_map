#pragma once
#include <string>

class Player
{
public:

	Player(
		std::string coming_player_name,
		std::string coming_player_fraction_id
	);

	Player(const Player& player);

	std::string Get_player_name();
	std::string Get_player_id();
	std::string Get_player_fraction_id();
	void Set_player_fraction_id(std::string _fraction_id);

	static int Get_player_counter();



private:
	static int player_counter;
	std::string player_name;
	std::string player_id;
	std::string player_fraction_id;
};

