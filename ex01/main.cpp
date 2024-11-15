#include "ScavTrap.hpp"

int	main(void)
{
	//ClapTrap Optimus("Optimus");
	ScavTrap OptimusPrime("Optimus Prime");
	OptimusPrime.takeDamage(99);
	ScavTrap Megatron(OptimusPrime);
	Megatron.takeDamage(1);
	Megatron.takeDamage(1);




	
	
}