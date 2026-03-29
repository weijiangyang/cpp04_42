#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

/**
 * Cure 类：AMateria 的具体实现
 * 代表一种治疗性质的魔法物质
 */
class Cure : public AMateria
{
    public:
        // --- 构造与析构 ---
        
        // 默认构造函数：在实现中会将 _type 初始化为 "cure"
        Cure();
        
        /**
         * 虚析构函数
         * 确保内存释放链路完整。
         */
        virtual ~Cure();

        // --- 核心多态函数重写 ---

        /**
         * 实现基类的纯虚函数 clone()
         * 作用：在堆上创建一个新的 Cure 对象副本。
         * 这是深拷贝逻辑的基础。
         */
        virtual AMateria* clone() const;

        /**
         * 重写基类的 use 函数
         * @param target 目标角色接口（通常是队友或自己）
         * 
         * 根据 42 题目要求，通常打印：
         * "* heals <target_name>'s wounds *"
         */
        virtual void use(ICharacter &target) const;
};

#endif