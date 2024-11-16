#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"



class DiamondTrap : public ScavTrap , public FragTrap{
	private :
		std::string _name;
	public :
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap& other);
		~DiamondTrap();
		DiamondTrap();

		void whoAmI();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		DiamondTrap& operator=(const DiamondTrap& src);
		void highFivesGuys(void);
};



#endif