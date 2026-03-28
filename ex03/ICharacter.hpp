#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>

// 前置声明 (Forward Declaration)
// 告诉编译器 AMateria 是一个类，但不需要现在就包含它的头文件。
// 这可以打破 ICharacter 和 AMateria 之间的循环引用（Circular Dependency）。
class AMateria;

/**
 * ICharacter 接口类
 * 它定义了所有角色类（如 Character）必须实现的行为准则。
 * 接口类不包含成员变量，只定义“协议”。
 */
class ICharacter
{
    public:
    /**
     * 虚析构函数
     * 接口类必须提供虚析构函数，以确保通过接口指针删除具体子类对象时，
     * 子类的析构函数能被正确触发。
     */
    virtual ~ICharacter() {}

    /**
     * 获取角色名字
     * "= 0" 表示纯虚函数，子类必须重写它。
     */
    virtual std::string const & getName() const = 0;

    /**
     * 装备 Materia
     * @param m 指向要装备的魔石的指针
     * 子类需要实现将此指针存入背包（通常是一个大小为 4 的数组）的逻辑。
     */
    virtual void equip(AMateria* m) = 0;

    /**
     * 卸下 Materia
     * @param idx 要卸下的物品槽位下标
     * 注意：在 42 的要求中，unequip 通常不 delete 掉该 Materia，
     * 只是将其从背包移除，需要另外处理内存以防泄露。
     */
    virtual void unequip(int idx) = 0;

    /**
     * 使用 Materia
     * @param idx 使用第几个槽位的魔石
     * @param target 目标角色
     * 逻辑通常是：找到 idx 位的 Materia，并调用该 Materia 的 use 函数。
     */
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif