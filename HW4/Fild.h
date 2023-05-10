#pragma once
#include <vector>
#include <iostream>
#include <string>
//#include <array>
//#include <math.h>
#include <random>
//#include <exception>
//#include "Structures.h"
#include "Cell.h"
#include "Player.h"
#include "Fraction.h"
#include "Lib.h"

using namespace std;



class Fild {
public:
	static Fild& Instance();
	
	vector<int> Get_fild_players(string _player_id);
	vector<string> Get_fild_fractions(int _fraction_id);
	
	void drawHoneycomb(int n);

private:
	std::vector<Cell> fild;
	std::vector<Player> players;

	Fild() {
		int input;
		cout << "Pease, input quantity of fractions (less 25)" << endl;
		cin >> input;
		vector<Fraction> fraction_cont(0);
		for (int i = 0; i < input; i++) {
			fraction_cont.push_back({ Lib::frac_name_lib[i] });
		};


		cout << "Pease, input quantity of players (less 20)" << endl;
		cin >> input;

		random_device rd; 
		mt19937 eng(rd()); 
		uniform_int_distribution<> rnd_frac(0, (fraction_cont.size()-1) );  
		
		int random_number = rnd_frac(eng);

		vector<Player> players_cont(0);
		for (int i = 0; i < input; i++) {
			random_number = rnd_frac(eng);
			string rand_id_frac = to_string(fraction_cont[random_number].Get_fraction_id());
			Player new_player (Lib::player_name_lib[i], rand_id_frac );
			players_cont.push_back({ new_player });
			players.push_back({ new_player });
		};


		vector<fild_size> final_vector(0);
		int count = 0;
		cout << "Please, input the quantity of filds" << std::endl;
		cin >> input;
		final_vector.push_back({ input, cell_types::FILD });
		count += input;
				
		cout << "Please, input the quantity of swamps" << std::endl;
		cin >> input;
		final_vector.push_back({ input,  cell_types::SWAMP });
		count += input;
			
		cout << "Please, input the quantity of hills" << std::endl;
		cin >> input;
		final_vector.push_back({ input, cell_types::HILL });
		count += input;
				
		cout << "Please, input the quantity of mountains" << std::endl;
		cin >> input;
		final_vector.push_back({ input, cell_types::MOUNTAIN });
		count += input;
		
		cout << "Filds: " << final_vector[0].quantity << std::endl;
		cout << "Swamps: " << final_vector[1].quantity << std::endl;
		cout << "Hills: " << final_vector[2].quantity << std::endl;
		cout << "Mountains: " << final_vector[3].quantity << std::endl;
		
		cout << "Note: The system can update a quantity of sells, to make a correct fild" << std::endl;
		
		int side = sqrt(count);
		count% side == 0 ? side += 0 : side += 1;
		int difer = (side * side) - count;
		if (difer != 0) { count = side * side; };

		std::cout << "Field size: " << side << " x " << side << std::endl;
		
		uniform_int_distribution<> rand_cell(0, 3); 		
		
		for (int i = 0; i < difer; i++) {
			int rand_val = rand_cell(eng);
			final_vector[rand_val].quantity++;
		}
		
		vector<Cell> cell_cont(0);
		uniform_int_distribution<> rand_type(0, 3);
		uniform_int_distribution<> rand_coef(0.0, 10.0);
		uniform_int_distribution<> rand_tower(0,10);

		for (int i = 0; i < count; i++) {
			cell_types randon_cell_type = (cell_types)generate_random_type(0, 3, final_vector);
			double random_cell_coef_patency = rand_coef(eng);
			cell_resourses reandom_cell_recource = generate_random_resource(0, 8);
			string reandom_id_player = generate_random_player(0, (players_cont.size()+20), players_cont);

			Cell new_cell(randon_cell_type, random_cell_coef_patency, reandom_cell_recource, reandom_id_player, rand_tower(eng));
			fild.push_back(new_cell);
		}

		for (int i = 0; i < count; i++) {
			cout << i+1;
			cout << "\tType: " << (int)fild[i].Get_cell_type();
			cout << "\tCoef.patency: " << fild[i].Get_cell_coef_patency();
			cout << "\tSell.resource: " << fild[i].Get_cell_resourse().resourse_availability;
			cout << "\tPlayer ID: " << fild[i].Get_cell_id_hero();
			cout << "\tRang of the tower: " << fild[i].Get_cell_tower_exist();
			cout << endl;
		}
	};

	Fild(const Fild& fild) = delete;
	Fild& operator=(const Fild&) = delete;

	int generate_random_type(int min, int max, vector<fild_size>& _final_vector) {
		random_device rd;
		mt19937 eng(rd());
		uniform_int_distribution<> rand_type(min, max);

		int random_type_index = rand_type(eng);

		if (_final_vector[0].quantity != 0 | _final_vector[1].quantity != 0 | _final_vector[2].quantity != 0 | _final_vector[3].quantity != 0) {
			if (_final_vector[random_type_index].quantity >= 0) {
				_final_vector[random_type_index].quantity--;
				return random_type_index;
			}
			else {
				generate_random_type(min, max, _final_vector);
			}
		}
		else {
			return 0;
		}
	}

	cell_resourses generate_random_resource(int min, int max) {
		random_device rd;
		mt19937 eng(rd());
		uniform_int_distribution<> rand_ability(false, true);
		uniform_int_distribution<> rand_type(min, max);
		uniform_int_distribution<> rand_time(0, 30);

		cell_resourses result;

		int random_cell_abilyty = (bool)rand_ability(eng);
		if (random_cell_abilyty) {
			result.resourse_availability = rand_ability(eng);
			result.resourse_type = (resource_types)rand_type(eng);
			result.resourse_speed = rand_time(eng);
			return result;
		}
		else {
			result.resourse_availability = rand_ability(eng);
			result.resourse_type = resource_types::NONE;
			result.resourse_speed =0;
			return result;
		}
	}

	string generate_random_player(int min, int max, vector<Player>& _player_cont) {
		random_device rd;
		mt19937 eng(rd());
		int rand_index = 0;
		if (min <= max) {
			uniform_int_distribution<> rand_int(min, max);
			rand_index = rand_int(eng);
		}

		if (rand_index >= _player_cont.size()) {
			return "No";
		}
		else {
			string result = _player_cont[rand_index].Get_player_id();
			return result;
		}
	}


};

