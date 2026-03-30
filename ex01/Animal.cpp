#include "Animal.hpp"
#include <iostream>

Animal::Animal():_type("animal")
{
    std::cout << "Animal default constructor called ." << std::endl;
}

Animal::Animal(std::string type):_type(type)
{
    std::cout << "Animal constructor called ." << std::endl;
}

Animal::Animal(const Animal &other): _type(other._type)
{
    std::cout << "Animal copy constructor called ." << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called ." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal assignment operator called ." << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

const std::string & Animal::getType() const
{
   return (_type);
}

void Animal::makeSound() const
{
    std::cout << "Some generic animal sound" << std::endl;
}