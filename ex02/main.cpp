#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int	main(void)
{
	//ClapTrap Optimus("Optimus");
	
	FragTrap Franky("Franky");
	ScavTrap OptimusPrime("Optimus Prime");
	OptimusPrime.takeDamage(99);
	ScavTrap Megatron(OptimusPrime);
	Megatron.takeDamage(1);
	Megatron.takeDamage(1);
	Franky.takeDamage(1);
	Franky.highFivesGuys();
	Franky.highFivesGuys();

	




	
	
}