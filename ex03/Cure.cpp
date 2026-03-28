#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure"){}
 
Cure::~Cure()
{
	std::cout << "Cure destructor called ." << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target) const
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}