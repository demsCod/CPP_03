#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
		
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap& other);
		FragTrap();
		~FragTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		FragTrap& operator=(const FragTrap &src);
		void highFivesGuys(void);
};



#endif