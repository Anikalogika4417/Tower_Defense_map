#include <iostream>
#include "Cell.h"


int main()
{
    Cell first_cell(FILD, 2.0, { true, WOOD, 2 });
    Cell second_cell(HILL, 2.0, { false });
    Cell third_cell(first_cell);
    third_cell.Set_cell_id_hero("Sapa");

    std::cout << "1 - " << first_cell.Get_cell_id_hero() << std::endl;
    std::cout << "3 - " << third_cell.Get_cell_id_hero() << std::endl;

}

