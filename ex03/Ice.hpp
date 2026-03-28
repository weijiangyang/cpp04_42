#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

/**
 * Ice 类：AMateria 的具体实现
 * 代表一种冰霜属性的魔法物质
 */
class Ice : public AMateria
{
    public:
        // --- 构造与析构 ---
        
        // 默认构造函数：需要将 _type 初始化为 "ice"
        Ice();
        
        /**
         * 虚析构函数
         * 即使这里不写 virtual，由于基类已经是 virtual，它也是虚的。
         * 但写上是一个好的编程习惯。
         */
        virtual ~Ice();

        // --- 核心多态函数 ---

        /**
         * 实现基类的纯虚函数 clone()
         * 作用：返回一个新的 Ice 对象（在堆上申请内存），
         *      它是当前对象的一个完整副本。
         * 返回值：AMateria* 指针，符合多态设计。
         */
        AMateria* clone() const;

        /**
         * 重写基类的 use 函数
         * @param target 目标角色接口
         * 
         * 作用：实现 Ice 特有的行为。
         * 根据 42 题目要求，通常打印：
         * "* shoots an ice bolt at <target_name> *"
         */
        void use(ICharacter &target) const;
};

#endif