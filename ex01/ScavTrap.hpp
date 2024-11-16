#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	private :
		bool is_guarding;
	public :
		ScavTrap(std::string name);
		ScavTrap(ScavTrap& other);
		ScavTrap();
		~ScavTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		ScavTrap& operator=(const ScavTrap &src);
		void guardGate();
};



#endif