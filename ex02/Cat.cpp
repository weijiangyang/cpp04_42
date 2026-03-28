#include "Cat.hpp"
#include <iostream>

Cat::Cat():Animal("cat")
{
	brain = new Brain();
    std::cout << "Cat default constructor called ." << std::endl;
}

Cat::Cat(const Cat &other):Animal(other)
{
	brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called ." << std::endl;
}

Cat::~Cat()
{
	delete brain;
    std::cout << "Cat destructor called ." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat assignment operator called ." << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
    }
    return (*this);
}


void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}