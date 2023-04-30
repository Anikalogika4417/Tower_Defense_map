#pragma once
#include <string>

class Fraction
{
public:

	Fraction(std::string coming_fraction_name);

	Fraction(const Fraction& fraction);

	int Get_fraction_id();
	std::string Get_fraction_name();
	void Set_fraction_name(std::string _fraction_id);

	static int Get_fraction_counter();
private:
	static int fraction_counter;
	std::string fraction_name;
	int fraction_id;
};
