#include "DiamondTrap.hpp"


/*• Name, which is passed as parameter to a constructor
• ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
• Hit points (FragTrap)
• Energy points (ScavTrap)
• Attack damage (FragTrap)
• attack() (Scavtrap)*/

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") , ScavTrap(name  + "_clap_name") , FragTrap(name  + "_clap_name") {
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "DiamondTrap " << _name << " enter to the Arena" << std::endl;  
}

DiamondTrap::DiamondTrap() : ClapTrap("unknow_clap_name"),  ScavTrap(), FragTrap()
{
	_name = "unknow";
	 _hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "DiamondTrap " << _name << " enter to the Arena" << std::endl;  
}

DiamondTrap::DiamondTrap(DiamondTrap& src)
{
	 *this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " return to cloakroom" << std::endl;  
}

void DiamondTrap::highFivesGuys(void)
{
	std::string input;

	if (_hitPoints < 1){
		std::cout << "DiamondTrap :" << _name  << "is K.O he can' t high five you " << std::endl;
	}
	if (!std::cin)
	{
		std::cout << "doesn't want a high five because you decided to be violent with him 😡" << std::endl;
		return ;
	}
	std::cout << "DiamondTrap :" << _name << " asking you for a high five" << std::endl;
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
			std::cout << "\033[0;32mYou restore A LOT OF  HP for DiamondTrap " << _name << "\033[0m"<< std::endl;
			this->beRepaired(1);
			return;
		}
		else if (input == "NO")
		{
			std::cout << "DiamondTrap is very angry with you! 😡" <<std::endl;
			return ;
		}
	}
}



void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "DiamondTrap :" << _name << " take a big punch in the face " 
			<< "\033[0;31m(-" << amount << " HP)\033[0m"  << std::endl ;
	}
	else
		std::cout << "DiamondTrap :" << _name << " can't be punched \033[0;31m[He is Out !]\033[0m" << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints < 1)
		{
			std::cout << "DiamondTrap :" << _name << " doesnt have energy to repaired itself" << std::endl;
			return ;
		}
		--_energyPoints;
		_hitPoints += amount;
		if (_hitPoints > 100){_hitPoints = 100;}
		std::cout << "DiamondTrap :" << _name  
			<< " repaired itself \033[0;32m(+" << amount << " HP)\033[0m" << std::endl;
	}
	else
		std::cout << "DiamondTrap :" << _name << " can't be repaired \033[0;31m[He is Out !]\033[0m" << std::endl;
}

void DiamondTrap:: whoAmI()
{
	std::cout << "My real name is " << _name <<  std:: endl << "My Clapname is " << ClapTrap::_name <<std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	if (this != &src)
	{
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_AttackDamage = src._AttackDamage;
	}
	return *this;
}


