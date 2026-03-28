#include "AMateria.hpp"
#include <iostream>

/**
 * 构造函数
 * 初始化 _type 成员。注意：虽然 AMateria 是抽象类，不能直接实例化，
 * 但子类（如 Ice/Cure）在构造时必须调用这个基类构造函数。
 */
AMateria::AMateria(std::string const &type) : _type(type)
{
    // 通常这里不打印信息，除非题目有特殊要求
}

/**
 * 虚析构函数
 * 确保通过基类指针删除子类对象时，内存能被完整释放。
 */
AMateria::~AMateria()
{
    std::cout << "AMateria destructor called ." << std::endl;
}

/**
 * 获取 Materia 类型
 * 返回常量引用以提高效率（避免字符串拷贝）
 */
std::string const & AMateria::getType() const
{
    return (_type);
}

/**
 * 使用 Materia 的默认实现
 * @param target 目标角色接口
 * 
 * 注意：(void)target; 这是一个常见的 C++ 技巧。
 * 因为基类的 use 函数逻辑比较通用（甚至为空），如果不使用 target 参数，
 * 编译器会报 "unused parameter" 警告。显式转换为 void 可以告诉编译器：
 * “我知道这个参数没用，我是故意的。”
 */
void AMateria::use(ICharacter& target) const
{
    (void)target;
}