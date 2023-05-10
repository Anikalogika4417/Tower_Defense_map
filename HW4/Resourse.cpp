#include "Resourse.h"

int Resourse::counter = 1;

Resourse::Resourse(std::string coming_name)
{
	this->resource_index = counter;
	this->resource_name = std::move(coming_name);
	counter++;
}

int Resourse::Get_resourse_index()
{
	return this->resource_index;
}

std::string Resourse::Get_resource_name()
{
	return this->resource_name;
}

void Resourse::Set_resource_name(std::string _resource_name)
{
	this->resource_name = std::move(_resource_name);
}
