#pragma once
enum cell_types 
{
	FILD,
	SWAMP,
	HILL,
	MOUNTAIN
};

enum resource_types 
{
	NONE,
	STONE,
	WOOD, 
	ORE,  //????
	CRYSTALS, 
	PRECIOUS_STONES, 
	MERCURY,   //?????
	SULFUR,  //????
	GOLD
};

struct cell_resourses
{
	bool resourse_availability;
	resource_types resourse_type = NONE;
	int resourse_speed = 0;
};