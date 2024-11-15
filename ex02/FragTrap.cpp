#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name)  {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_AttackDamage = 30;
	std::cout << "FragTrap " << _name << " enter to the ring" << std::endl;  
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_AttackDamage = src._AttackDamage;

}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " return to cloakroom" << std::endl;  
}

void FragTrap::highFivesGuys(void)
{
	std::string input;

	if (_hitPoints < 1){
		std::cout << "FragTrap :" << _name  << "is K.O he can' t high five you " << std::endl;
	}
	if (!std::cin)
	{
		std::cout << "doesn't want a high five because you decided to be violent with him 😡" << std::endl;
		return ;
	}
	std::cout << "FragTrap :" << _name << " asking you for a high five" << std::endl;
	while (1)
	{
		std::cout << "Do you want ? YES OR NO" << std::endl;
		getline(std::cin, input);
		if (!std::cin)
		{
			std::cout << "Bro i just asking you for one thing 🤦🏿‍♂️" << std::endl;
			return ;
		}
		if (input == "YES")
		{
			std::cout << "\033[0;32mYou restore A LOT OF  HP for FragTrap " << _name << "\033[0m"<< std::endl;
			this->beRepaired(1);
			return;
		}
		else if (input == "NO")
		{
			std::cout << "FragTrap is very angry with you! 😡" <<std::endl;
			return ;
		}
	}
}



void FragTrap::attack(const std::string& target)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints > 0)
		{
			--_energyPoints;
			std::cout << "FragTrap :" << _name << " punched " << target 
				<< ", causing " << _AttackDamage << " points of damage !" << std::endl;
			return ;
		}
		std::cout << "FragTrap :" << _name << " doesnt have energy to attack" << std::endl;
	}
	else
		std::cout  << "FragTrap :" << _name << " can't attack \033[0;31m[He is Out !]\033[0m" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "FragTrap :" << _name << " take a big punch in the face " 
			<< "\033[0;31m(-" << amount << " HP)\033[0m"  << std::endl ;
	}
	else
		std::cout << "FragTrap :" << _name << " can't be punched \033[0;31m[He is Out !]\033[0m" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints < 1)
		{
			std::cout << "FragTrap :" << _name << " doesnt have energy to repaired itself" << std::endl;
			return ;
		}
		--_energyPoints;
		_hitPoints += amount;
		if (_hitPoints > 100){_hitPoints = 100;}
		std::cout << "FragTrap :" << _name  
			<< " repaired itself \033[0;32m(+" << amount << " HP)\033[0m" << std::endl;
	}
	else
		std::cout << "FragTrap :" << _name << " can't be repaired \033[0;31m[He is Out !]\033[0m" << std::endl;
}


FragTrap& FragTrap::operator=(FragTrap &src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_AttackDamage = src._AttackDamage;

	return *this;
}