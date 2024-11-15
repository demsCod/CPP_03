#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	private :
		
	public :
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		FragTrap& operator=(FragTrap &src);
		void highFivesGuys(void);
};



#endif