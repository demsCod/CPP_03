#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"

class ClapTrap
{
  private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _AttackDamage;

  public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &other);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &src);
	void attack(const std::string &target);
	// void displayStatus() const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif