#include "Character.hpp"
#include <iostream>

// 构造函数
Character::Character(const std::string &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "Character " << _name << " constructor called." << std::endl;
}

// 拷贝构造函数（深拷贝）
Character::Character(const Character &other) : _name(other._name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    std::cout << "Character copy constructor called." << std::endl;
}

// 赋值操作符（深拷贝）
Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        _name = other._name;

        // 删除现有 inventory
        for (int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }

        // 深拷贝新 inventory
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    std::cout << "Character assignment operator called." << std::endl;
    return *this;
}

// 析构函数
Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
    std::cout << "Character " << _name << " destructor called." << std::endl;
}

// getName
std::string const & Character::getName() const
{
    return _name;
}

// equip
void Character::equip(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return;
        }
    }
    // inventory full: do nothing
}

// unequip
void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4) return;
    _inventory[idx] = NULL; // 不 delete
}

// use
void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx]) return;
    _inventory[idx]->use(target);
}