#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp" // 引入接口，因为 use 函数需要引用角色对象

/**
 * AMateria 类：魔法物质的抽象基类
 * 前缀 'A' 通常代表 Abstract（抽象）
 */
class AMateria
{
    protected:
        // 存储 Materia 的类型（如 "ice" 或 "cure"）
        std::string _type;
    
    public:
        // --- 构造与析构 ---
        
        // 构造函数：必须提供类型名
        AMateria(std::string const &type);
        
        // 虚析构函数：确保子类（Ice/Cure）被正确销毁，防止内存泄漏
        virtual ~AMateria();

        // --- 成员函数 ---

        // 返回 Materia 的类型
        std::string const & getType() const;

        /**
         * 纯虚函数 (Pure Virtual Function)
         * "= 0" 标志着这是一个抽象类，不能被直接实例化。
         * 作用：强制要求所有子类（Ice, Cure 等）必须实现自己的 clone() 逻辑，
         *      用于返回一个该 Materia 对象的深拷贝副本。
         */
        virtual AMateria* clone() const = 0;

        /**
         * 虚函数 use
         * 基类提供了一个默认实现，但子类通常会重写它以表现出不同的行为。
         * 例如：Ice 会显示 "shoots an ice bolt"，Cure 会显示 "heals wounds"。
         */
        virtual void use(ICharacter& target) const;
};

#endif