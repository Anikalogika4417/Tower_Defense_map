#include "Player.h"

int Player::player_counter = 1;

Player::Player(std::string coming_player_name, std::string coming_player_fraction_id)
{
	this->player_name = coming_player_name;
	this->player_id = std::to_string(player_counter);
	this->player_fraction_id = coming_player_fraction_id;
	player_counter++;
}

Player::Player(Player& player)
{
	this->player_name = std::move(player.player_name);
	this->player_id = std::to_string(player_counter);
	this->player_fraction_id = std::move(player.player_fraction_id);
	player_counter++;
}

std::string Player::Get_player_name()
{
	return this->player_name;
}

std::string Player::Get_player_id()
{
	return this->player_id;
}

std::string Player::Get_player_fraction_id()
{
	return this->player_fraction_id;
}

void Player::Ser_player_fraction_id(std::string _fraction_id)
{
	this->player_fraction_id = _fraction_id;
}

int Player::Get_player_counter()
{
	return player_counter - 1;
}
