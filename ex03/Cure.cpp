#include "Cure.hpp"
#include <iostream>

// 默认构造函数
Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called." << std::endl;
}

// 拷贝构造函数
Cure::Cure(const Cure &other) : AMateria(other)
{
    std::cout << "Cure copy constructor called." << std::endl;
}

// 赋值运算符
Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Cure assignment operator called." << std::endl;
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

// 析构函数
Cure::~Cure()
{
    std::cout << "Cure destructor called." << std::endl;
}

// clone 函数：在堆上创建 Cure 副本
AMateria* Cure::clone() const
{
    return new Cure(*this);
}

// use 函数：多态调用
void Cure::use(ICharacter &target) const
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}