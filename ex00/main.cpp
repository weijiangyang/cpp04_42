#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

/*int main(void)
{
	std::cout << "==== Animal test ====" << std::endl;

	Animal a;
	Animal b("un animal");
	Animal c(b);
	a = c;

	std::cout << std::endl;

	std::cout << "==== Dog polymorphism test ====" << std::endl;

	Animal *d = new Dog("un dog");
	d->makeSound();
	std::cout << d->getType() << std::endl;

	std::cout << std::endl;

	std::cout << "==== Cat polymorphism test ====" << std::endl;

	Animal *e = new Cat("un chat");
	e->makeSound();
	std::cout << e->getType() << std::endl;

	std::cout << std::endl;
	std::cout << "==== Destructor test ====" << std::endl;
	delete d;
	delete e;

	return 0;
}*/

/*int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

}*/

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Cat cat1;
	Dog dog1;

	std::cout << cat1.getType() << std::endl;
	std::cout << dog1.getType() << std::endl;

	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *cat = new WrongCat();

	std::cout << cat->getType() << std::endl;

	cat->makeSound(); // ❗会调用 WrongAnimal 的函数
	meta->makeSound();

	delete meta;
	delete cat;
}