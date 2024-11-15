#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _AttackDamage(0)
{
	std::cout << "Claptrap " << _name << " enter to the ring" << std::endl;  
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_AttackDamage = other._AttackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << _name << " return to cloakroom" << std::endl;  
}

ClapTrap& ClapTrap::operator=(ClapTrap &src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_AttackDamage = src._AttackDamage;

	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints > 0)
		{
			--_energyPoints;
			std::cout << "ClapTrap :" << _name << " punched " << target 
				<< ", causing " << _AttackDamage << " points of damage !" << std::endl;
			return ;
		}
		std::cout << "ClapTrap :" << _name << " doesnt have energy to attack" << std::endl;
	}
	else
		std::cout  << "ClapTrap :" << _name << " can't attack \033[0;31m[He is Out !]\033[0m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "ClapTrap :" << _name << " take a big punch in the face " 
			<< "\033[0;31m(-" << amount << " HP)\033[0m"  << std::endl ;
	}
	else
		std::cout << "ClapTrap :" << _name << " can't be punched \033[0;31m[He is Out !]\033[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints < 1)
		{
			std::cout << "ClapTrap :" << _name << " doesnt have energy to repaired itself" << std::endl;
			return ;
		}
		--_energyPoints;
		_hitPoints += amount;
		if (_hitPoints > 10){_hitPoints = 10;}
		std::cout << "ClapTrap :" << _name  
			<< " repaired itself \033[0;32m(+" << amount << " HP)\033[0m" << std::endl;
	}
	else
		std::cout << "ClapTrap :" << _name << " can't be repaired \033[0;31m[He is Out !]\033[0m" << std::endl;
}