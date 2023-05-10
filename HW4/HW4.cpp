#include <iostream>
#include "Resourse.h"
#include "Cell.h"
#include "Player.h"
#include "Fraction.h"
#include "Fild.h"



int main()
{
    /*Player player1("Nuta", "1");
    Player player2("Sapa", "2");
    Player player3(player1);

    std::cout << player1.Get_player_id() << std::endl;
    std::cout << player2.Get_player_id() << std::endl;
    std::cout << player3.Get_player_id() << std::endl;

    std::cout << "Count of players: " << Player::Get_player_counter() << std::endl;*/

    Fild::Instance();
    string a;
    std::cout << "Enter the interested player";
    std::cin >> a;
    std::vector<int> play_fild = Fild::Instance().Get_fild_players(a);

    std::cout << "Enter the interested fraction";
    int b;
    std::cin >> b;
    std::vector<std::string> players = Fild::Instance().Get_fild_fractions(b);


}

