#include "Cure.hpp"
#include <iostream>

/**
 * 默认构造函数
 * 调用父类 AMateria 的构造函数，将类型标识符设为 "cure"。
 * 这确保了通过 getType() 获取到的字符串永远是正确的。
 */
Cure::Cure() : AMateria("cure") {}

/**
 * 析构函数
 * 打印调试信息，用于观察对象销毁顺序。
 * 顺序通常是：子类析构 (Cure) -> 父类析构 (AMateria)。
 */
Cure::~Cure()
{
    std::cout << "Cure destructor called ." << std::endl;
}

/**
 * clone() 函数实现
 * 核心逻辑：new 一个当前对象的副本并返回。
 * 即使当前对象被存储为 AMateria* 指针，调用 clone() 也能产生一个新的 Cure。
 */
AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

/**
 * use() 函数实现
 * 实现了“治疗”的具体表现逻辑。
 * 按照 42 项目的严格要求，输出格式为：* heals <name>'s wounds *
 */
void Cure::use(ICharacter &target) const
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}