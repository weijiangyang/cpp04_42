#include "MateriaSource.hpp"
#include <iostream>
#include <string>

// 构造函数
MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
    std::cout << "MateriaSource constructor called." << std::endl;
}

// 拷贝构造函数（深拷贝）
MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
    std::cout << "MateriaSource copy constructor called." << std::endl;
}

// 赋值操作符（深拷贝）
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete _materias[i];
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    std::cout << "MateriaSource assignment operator called." << std::endl;
    return *this;
}

// 析构函数
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete _materias[i];
    std::cout << "MateriaSource destructor called." << std::endl;
}

// learnMateria
void MateriaSource::learnMateria(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = m;
            return;
        }
    }
    // 已满，忽略
}

// createMateria
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL; // 类型未知
}