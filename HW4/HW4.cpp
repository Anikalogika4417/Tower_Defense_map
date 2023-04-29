#include <iostream>
#include "Cell.h"
#include "Player.h"


int main()
{
    Player player1("Nuta", "1");
    Player player2("Sapa", "2");
    Player player3(player1);

    std::cout << player1.Get_player_id() << std::endl;
    std::cout << player2.Get_player_id() << std::endl;
    std::cout << player3.Get_player_id() << std::endl;

    std::cout << "Count of players: " << Player::Get_player_counter() << std::endl;

}

