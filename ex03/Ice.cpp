#include "Ice.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice"){}
 
Ice::~Ice()
{
	std::cout << "Ice destructor called ." << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) const
{
    std::cout << "* shoots an ice bolt at "
              << target.getName()
              << " *" << std::endl;
}