#include "Cat.hpp"
#include <iostream>

Cat::Cat():Animal("cat")
{
    std::cout << "Cat default constructor called ." << std::endl;
}

Cat::Cat(std::string type):Animal(type)
{
    std::cout << "Cat constructor called ." << std::endl;
}

Cat::Cat(const Cat &other):Animal(other)
{
    std::cout << "Cat copy constructor called ." << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called ." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat assignment operator called ." << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return (*this);
}


void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}