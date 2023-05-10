#pragma once
#include "Cell.h"
#include "Fraction.h"
#include "Player.h"

enum class cell_types 
{
	FILD = 0,
	SWAMP,
	HILL,
	MOUNTAIN
};

enum class resource_types 
{
	NONE = 0,
	STONE,
	WOOD, 
	ORE,
	CRYSTALS, 
	PRECIOUS_STONES, 
	MERCURY, 
	SULFUR,
	GOLD
};



struct cell_resourses
{
	bool resourse_availability;
	resource_types resourse_type = resource_types::NONE;
	int resourse_speed = 0;
};

struct fild_size
{
	int quantity;
	cell_types type_of_sell;
};

