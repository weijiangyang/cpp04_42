#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal  
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string const &type);
        Animal(const Animal &other);
        virtual ~Animal();
        Animal &operator=(const Animal &other);

        const std::string &getType() const;
        virtual void makeSound() const;
};

#endif