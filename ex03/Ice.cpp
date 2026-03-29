#include "Ice.hpp"
#include <iostream>

/**
 * 默认构造函数
 * 显式调用父类 AMateria 的构造函数，并将类型硬编码为 "ice"。
 * 这样每个 Ice 实例被创建时，其 _type 成员都会被正确初始化。
 */
Ice::Ice() : AMateria("ice") {}

/**
 * 析构函数
 * 打印调试信息。在 42 的项目中，这有助于验证
 * delete AMateria* 指针时是否正确调用了子类的析构。
 */
Ice::~Ice()
{
    std::cout << "Ice destructor called ." << std::endl;
}

/**
 * clone() 函数实现
 * 这是原型模式（Prototype Pattern）的核心。
 * 作用：在堆（Heap）上创建一个当前 Ice 对象的全新副本。
 * 使用 new Ice(*this) 会调用隐式的拷贝构造函数。
 * 返回值：返回基类指针 AMateria*，方便存入 Character 的背包数组中。
 */
AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

/**
 * use() 函数实现
 * 实现了该 Materia 的具体功能逻辑。
 * @param target 目标角色的引用。通过 target.getName() 获取目标的名称。
 * 输出格式必须严格遵循题目要求：* shoots an ice bolt at <name> *
 */
void Ice::use(ICharacter &target) const
{
    std::cout << "* shoots an ice bolt at "
              << target.getName()
              << " *" << std::endl;
}