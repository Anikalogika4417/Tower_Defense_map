#pragma once
#include <string>

class Resourse
{
public:
	Resourse(std::string coming_name);
	int Get_resourse_index();

	std::string Get_resource_name();
	void Set_resource_name(std::string _resource_name);

private:
	static int counter;
	int resource_index;
	std::string resource_name;
};

