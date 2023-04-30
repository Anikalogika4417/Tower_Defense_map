#include "Fraction.h"

int Fraction::fraction_counter = 1;

Fraction::Fraction(std::string coming_fraction_name)
{
	this->fraction_name = coming_fraction_name;
	this->fraction_id = fraction_counter;
	fraction_counter++;
}

Fraction::Fraction(const Fraction& fraction)
{
	this->fraction_name = std::move(fraction.fraction_name);
	this->fraction_id = fraction_counter;
	fraction_counter++;
}

int Fraction::Get_fraction_id()
{
	return this->fraction_id;
}

std::string Fraction::Get_fraction_name()
{
	return this->fraction_name;
}

void Fraction::Set_fraction_name(std::string _fraction_id)
{
	this->fraction_name = _fraction_id;

}

int Fraction::Get_fraction_counter()
{
	return fraction_counter-1;
}
