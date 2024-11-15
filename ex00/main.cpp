#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Optimus("Optimus Prime");

	Optimus.takeDamage(1);
	Optimus.takeDamage(1);
	Optimus.takeDamage(1);
	Optimus.takeDamage(1);
	Optimus.takeDamage(1);
	Optimus.takeDamage(1);
	Optimus.takeDamage(1);
	Optimus.takeDamage(1);
	Optimus.takeDamage(1);
	ClapTrap Franky = Optimus;
	//Franky.beRepaired(5);
	Franky.takeDamage(1);
	Franky.takeDamage(1);
	Franky.takeDamage(1);

	
}