#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)  {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_AttackDamage = 20;
	is_guarding = false;
	std::cout << "ScavTrap " << _name << " enter to the ring" << std::endl;  
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_AttackDamage = src._AttackDamage;
	is_guarding = src.is_guarding;

}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " return to cloakroom" << std::endl;  
}

void ScavTrap::guardGate()
{
	if (is_guarding == true)
	{
			std::cout << "ScavTrap " << _name << " is already guarding the GATE" << std::endl;  
			return ;
	}
	std::cout << "ScavTrap " << _name << " guard the GATE" << std::endl;  
	is_guarding = true;
}



void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints > 0)
		{
			--_energyPoints;
			std::cout << "ScavTrap :" << _name << " punched " << target 
				<< ", causing " << _AttackDamage << " points of damage !" << std::endl;
			return ;
		}
		std::cout << "ScavTrap :" << _name << " doesnt have energy to attack" << std::endl;
	}
	else
		std::cout  << "ScavTrap :" << _name << " can't attack \033[0;31m[He is Out !]\033[0m" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "ScavTrap :" << _name << " take a big punch in the face " 
			<< "\033[0;31m(-" << amount << " HP)\033[0m"  << std::endl ;
	}
	else
		std::cout << "ScavTrap :" << _name << " can't be punched \033[0;31m[He is Out !]\033[0m" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints < 1)
		{
			std::cout << "ScavTrap :" << _name << " doesnt have energy to repaired itself" << std::endl;
			return ;
		}
		--_energyPoints;
		_hitPoints += amount;
		if (_hitPoints > 100){_hitPoints = 100;}
		std::cout << "ScavTrap :" << _name  
			<< " repaired itself \033[0;32m(+" << amount << " HP)\033[0m" << std::endl;
	}
	else
		std::cout << "ScavTrap :" << _name << " can't be repaired \033[0;31m[He is Out !]\033[0m" << std::endl;
}


ScavTrap& ScavTrap::operator=(ScavTrap &src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_AttackDamage = src._AttackDamage;
	is_guarding = src.is_guarding;

	return *this;
}