#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "========== POLYMORPHISM TEST ==========" << std::endl;

    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < size; i++)
    {
        animals[i]->makeSound();
    }

    std::cout << "========== DELETE TEST ==========" << std::endl;

    for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }

    std::cout << "========== DEEP COPY TEST ==========" << std::endl;

    Dog dog1;
    Dog dog2 = dog1;

    Cat cat1;
    Cat cat2;
    cat2 = cat1;

    std::cout << "========== END ==========" << std::endl;

    return 0;
}