#pragma once
#include <string>
#include "Structures.h"

class Cell
{
public:
	Cell(
		cell_types coming_cell_type,
		double coming_cell_coef_patency,
		cell_resourses coming_cell_resourse,
		std::string coming_cell_id_hero = "",
		int coming_cell_tower_exist = 0
		);

	Cell(Cell& cell);

	cell_types Get_cell_type();

	double Get_cell_coef_patency();

	std::string Get_cell_id_hero();
	void Set_cell_id_hero(std::string _id_hero);

	double Get_cell_influence();
	void Set_cell_influence(double _id_hero);

	int Get_cell_tower_exist();
	void Set_cell_tower_exist(int _tower_exist);

	cell_resourses Get_cell_resourse();

private:
	cell_types cell_type;
	double cell_coef_patency;
	std::string cell_id_hero;
	double cell_influence;
	int cell_tower_exist;
	cell_resourses cell_resourse;
};
