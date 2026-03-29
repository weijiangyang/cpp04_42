#include "AMateria.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

#include <iostream>

/*int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	
	return 0;
}*/


int main()
{
    std::cout << "===== BASIC TEST =====" << std::endl;

    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n===== INVENTORY LIMIT TEST =====" << std::endl;

    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice")); // should NOT equip (inventory full)

    std::cout << "\n===== UNEQUIP TEST =====" << std::endl;

    me->unequip(0);
    me->use(0, *bob); // should do nothing

    std::cout << "\n===== DEEP COPY TEST =====" << std::endl;

    Character* original = new Character("original");

    original->equip(src->createMateria("ice"));
    original->equip(src->createMateria("cure"));

    Character copy = *original;   // copy constructor

    original->unequip(0);

    std::cout << "Original uses slot 0:" << std::endl;
    original->use(0, *bob);

    std::cout << "Copy uses slot 0:" << std::endl;
    copy.use(0, *bob);   // must still work if deep copy

    std::cout << "\n===== ASSIGNMENT TEST =====" << std::endl;

    Character assign("assign");

    assign = copy;

    copy.unequip(1);

    std::cout << "Assign uses slot 1:" << std::endl;
    assign.use(1, *bob);

    std::cout << "\n===== INVALID TYPE TEST =====" << std::endl;

    tmp = src->createMateria("fire");

    if (!tmp)
        std::cout << "Materia 'fire' does not exist ✔" << std::endl;

    std::cout << "\n===== CLEANUP =====" << std::endl;

    delete original;
    delete bob;
    delete me;
    delete src;

    std::cout << "Program finished without crash ✔" << std::endl;

    return 0;
}
