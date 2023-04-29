# HW4

Home Coding:

A map for a Tower Defense type game
1) The class of the cell of the playing field (hexagonal cells), must contain the following information:
- type (field, swamp, elevation, mountain), type at the discretion of the developer, constant value
- the coefficient of patency (how convenient it is to move, affects the path search, the option impassable is possible), type floating point number, constant value
- to whom it belongs (string ID of the game character, std::string)
- the influence of the player in this cell, the type of floating-point number, calculated.
- the presence of the player's tower, its level.
- the availability of resources in the cell, their type, the rate of extraction (the resource is infinite).
Implement constructors - default, move, copy, get/set methods
2) Player class
- nickname (string)
- ID of the game character, (string)
- id of the faction (string)
- class fraction
- name (string)
- id of the fraction
3) Class of the playing field, arbitrary size: (n, m)
- to store cells and use vector (std::vector)
- list of players
- list of phrases
- a function for randomly generating a playing field with a given number of cell types, players and factions.
- search function for all player cells (result - cell numbers)
- search function for all players of the fraction (result - ID vector of players)
