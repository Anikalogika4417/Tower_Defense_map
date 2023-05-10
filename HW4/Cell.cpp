#include "Cell.h"


Cell::Cell()
{
}

Cell::Cell(cell_types coming_cell_type,
	double coming_cell_coef_patency,
	cell_resourses coming_cell_resourse,
	std::string coming_cell_id_hero,
	int coming_cell_tower_exist)
{
	this->cell_type = coming_cell_type;
	this->cell_coef_patency = coming_cell_coef_patency;
	this->cell_resourse = coming_cell_resourse;
	this->cell_influence = coming_cell_tower_exist*2;
	this->cell_id_hero = coming_cell_id_hero;
	this->cell_tower_exist = coming_cell_tower_exist;

};

Cell::Cell(const Cell& cell)
{
	this->cell_type = cell.cell_type;
	this->cell_coef_patency = cell.cell_coef_patency;
	this->cell_resourse = cell.cell_resourse;
	this->cell_influence = cell.cell_tower_exist;
	this->cell_id_hero = std::move(cell.cell_id_hero);
	this->cell_tower_exist = cell.cell_tower_exist;
}

Cell::Cell(Cell&& other) noexcept
{
	// Move the data from the other object to this object
	this->cell_type = other.cell_type;
	this->cell_coef_patency = other.cell_coef_patency;
	this->cell_resourse = std::move(other.cell_resourse);
	this->cell_influence = other.cell_influence;
	this->cell_id_hero = std::move(other.cell_id_hero);
	this->cell_tower_exist = other.cell_tower_exist;

	// Set the other object's data to a default state
	other.cell_type = cell_types::FILD;
	other.cell_coef_patency = 0.0;
	other.cell_resourse = { false, resource_types::NONE };
	other.cell_influence = 0;
	other.cell_id_hero = "";
	other.cell_tower_exist = 0;
}


cell_types Cell::Get_cell_type() 
{
	return this->cell_type;
};

double Cell::Get_cell_coef_patency()
{
	return this->cell_coef_patency;
};

std::string Cell::Get_cell_id_hero()
{
	return this->cell_id_hero;
};

void Cell::Set_cell_id_hero(std::string _id_hero)
{
	this->cell_id_hero = _id_hero;
};

double  Cell::Get_cell_influence()
{
	return this->cell_influence;
};

void Cell::Set_cell_influence(double _influense)
{
	this->cell_influence = _influense;
};

int Cell::Get_cell_tower_exist()
{
	return this->cell_tower_exist;
};

void Cell::Set_cell_tower_exist(int _tower_exist) 
{
	this->cell_tower_exist = _tower_exist;
};

cell_resourses Cell::Get_cell_resourse()
{
	return this->cell_resourse;
};