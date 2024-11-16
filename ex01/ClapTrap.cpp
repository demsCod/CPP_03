#include "ClapTrap.hpp"
#include <sstream>

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _AttackDamage(0)
{
	std::cout << "Claptrap " << _name << " enter to the ring" << std::endl;  
}

ClapTrap::ClapTrap() {
  _name = "unknown";
  _hitPoints = 10;
  _energyPoints = 10;
  _AttackDamage = 0;
  std::cout << "ClapTrap " << _name << " enter to the ring " << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other)
{
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << _name << " return to cloakroom" << std::endl;  
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
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

void ClapTrap::attack(const std::string& target)
{
	// this->displayStatus();
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
	// this->displayStatus();
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
	// this->displayStatus();
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

// void ClapTrap::displayStatus() const
// {
   
//     // Conversion des nombres en string
//     std::stringstream ss;
//     std::string hp_str, ep_str, ad_str;
    
//     ss << _hitPoints;
//     hp_str = ss.str();
//     ss.str("");  // Clear stringstream
    
//     ss << _energyPoints;
//     ep_str = ss.str();
//     ss.str("");
    
//     ss << _AttackDamage;
//     ad_str = ss.str();

//     // Ligne de séparation supérieure
//     std::cout << BLUE << "╔════════════════════════════════════════╗" << RESET << std::endl;
    
//     // Nom du ClapTrap
//     std::cout << BLUE << "║ " << RESET << BOLD << CYAN << "ClapTrap: " << _name 
//               << std::string(29 - _name.length(), ' ') << RESET << BLUE << "║" << RESET << std::endl;
    
//     // Ligne de séparation
//     std::cout << BLUE << "╠════════════════════════════════════════╣" << RESET << std::endl;
    
//     // Points de vie
//     std::string hpColor = (_hitPoints > 7) ? GREEN : (_hitPoints > 3 ? YELLOW : RED);
//     std::cout << BLUE << "║ " << RESET << "HP: " << hpColor << _hitPoints << "/10"
//               << std::string(31 - hp_str.length(), ' ') << BLUE << "║" << RESET << std::endl;
    
//     // Points d'énergie
//     std::string epColor = (_energyPoints > 7) ? GREEN : (_energyPoints > 3 ? YELLOW : RED);
//     std::cout << BLUE << "║ " << RESET << "Energy: " << epColor << _energyPoints << "/10"
//               << std::string(28 - ep_str.length(), ' ') << BLUE << "║" << RESET << std::endl;
    
//     // Dégâts d'attaque
//     std::cout << BLUE << "║ " << RESET << "Attack Damage: " << CYAN << _AttackDamage
//               << std::string(24 - ad_str.length(), ' ') << BLUE << "║" << RESET << std::endl;
    
//     // Status
//     std::cout << BLUE << "║ " << RESET << "Status: ";
//     if (_hitPoints <= 0)
//         std::cout << RED << "OUT!" << std::string(28, ' ');
//     else if (_energyPoints <= 0)
//         std::cout << YELLOW << "LOW ENERGY" << std::string(23, ' ');
//     else
//         std::cout << GREEN << "READY" << std::string(28, ' ');
//     std::cout << BLUE << "║" << RESET << std::endl;
    
//     // Ligne de séparation inférieure
//     std::cout << BLUE << "╚════════════════════════════════════════╝" << RESET << std::endl;
// }
