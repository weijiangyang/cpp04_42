#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}                     // 虚析构函数
    virtual void learnMateria(AMateria* m) = 0;     // 学习 Materia
    virtual AMateria* createMateria(std::string const & type) = 0; // 创建 Materia
};

#endif