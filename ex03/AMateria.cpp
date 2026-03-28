#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type):_type(type){}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called ." << std::endl;
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target) const
{
	(void)target;
}
