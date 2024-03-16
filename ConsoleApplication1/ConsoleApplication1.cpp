#include <iostream>
#include<conio.h>
using namespace std;

class Base {
	int zx = -1;
public:
	Base() {
		printf("Base() %p\n", this);
	}
	Base(Base* c) {
		printf("Base(Base *c) %p\n", this);
	}
	Base(Base& c) {
		printf("Base(Base &c) %p\n", this);
	}
	void set(int _zx) {
		zx = _zx;
	}
	int get() {
		return zx;
	}
	void Metod1()
	{
		printf("Metod1 Base\n");
	}
	void virtual Metod2()
	{
		printf("Metod2 Base\n");
	}
	void foo()
	{
		printf("Base\n");
	}
	void virtual foo2()
	{
		printf("Base\n");
	}
	~Base() {
		printf("~Base()\n");
	}


};
void func1(Base c) {
	printf("func1: c адрес %p\n", &c);
}
void func2(Base* c) {
	printf("func2: c адрес %p\n", c);
}
void func3(Base& c) {
	printf("func3: c адрес %p\n", &c);
}
Base func1() {

	printf("Base func1()\n");
	Base c;
	return c;
}
Base* func2() {

	printf("Base* func2()\n");
	return new Base;
}
Base& func3(Base* c) {
	printf("Base& func3()\n");
	return *c;
}
class Desc :public Base {

public:
	Desc() {
		printf("Desc() %p\n", this);
	}
	Desc(Desc* obj) {
		printf("Desc(Desc* c) %p\n", this);
	}
	Desc(Desc& obj) {
		printf("Desc(Desc& c) %p\n", this);
	}
	void Metod1()
	{
		printf("Metod1 Desc\n");
	}
	void  Metod2() override
	{
		printf("Metod2 Desc\n");
	}
	void foo()
	{
		printf("Desc\n");
	}
	void foo2()
	{
		printf("Desc\n");
	}

	virtual ~Desc() {
		printf("~Desc()\n");
	}


};

class Desc2 :public Desc {

public:
	void Metod1()
	{
		printf("Metod Desc2\n");
	}
	void  Metod2() override
	{
		printf("Metod2 Desc2\n");
	}
	void foo()
	{
		printf("Desc2\n");
	}
	void foo2()
	{
		printf("Desc2\n");
	}

	~Desc2() {
		printf("~Desc2()\n");
	}


};

class Animal {
public:
	Animal() {
		printf("Animal()\n");
	}
	string name;
	virtual string classname() {
		return "Animal";
	}
	virtual void sound() {
		printf("!\n");

	}
	virtual bool isA(string who)
	{
		return (who == "Animal");

	}
	virtual ~Animal()
	{
		printf("~Animal()\n");
	}
};

class Cat : public Animal {
public:
	Cat() {
		printf("Cat()\n");
	}

	string classname() {
		return "Cat";
	}
	bool isA(string who)
	{
		return(who == "Cat" || Animal::isA(who));
	}
	void catch_() {
		printf("Cat::catch_()\n");
	}
	virtual void sound() {
		printf("mew-mew\n");

	}
	~Cat()
	{
		printf("~Cat()\n");
	}
};
class Dog : public Animal {
public:
	Dog() {
		printf("Dog()\n");
	}
	bool isA(string who)
	{
		return(who == "Dog" || Animal::isA(who));
	}
	string classname() {
		return "Dog";
	}
	void chase_() {
		printf("Сhase()\n");
	}
	virtual void sound() {
		printf("wow-wow\n");

	}
	~Dog()
	{
		printf("~Dog()\n");
	}
};
class WildDog : public Dog {
public:
	WildDog() {
		printf("Dog()\n");
	}
	bool isA(string who)
	{
		return(who == "Dog" || Dog::isA(who));
	}
	string classname() {
		return " WildDog";
	}
	virtual void sound() {
		printf("grrrrrrr\n");

	}
	~WildDog()
	{
		printf("~WildDog()\n");
	}
};
class Clock {
public:
	Clock() {
		printf("Clock()\n");
	}


	~Clock() {
		printf("~Clock()\n");
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Перекрываемые методы:\n");
	printf("Вызов методов предка:\n");
	Base* x = new Base();
	x->Metod1();
	x->Metod2();
	delete x;
	printf("Вызов методов наследника:\n");
	Desc* x1 = new Desc();
	x1->Metod1();
	x1->Metod2();
	delete x1;
	printf("Вызов предка, объявленного как наследник:\n");
	Base* x2 = new Desc();
	x2->Metod1();
	x2->Metod2();
	delete x2;
	printf("\n");

	printf("Виртуальных методов, в т.ч.деструкторов\n");
	printf("Вызов методов предка:\n");
	Base* x11 = new Base();
	x11->foo2();
	delete x11;
	printf("Вызов методов наследника:\n");
	Desc* x12 = new Desc();
	x12->foo2();
	delete x12;
	printf("Вызов предка, объявленного как наследник:\n");
	Base* x22 = new Desc();
	x22->foo2();
	delete x22;
	printf("\n");

	printf("Деструктор виртуальный\n");
	printf("У класса Desc2 foo не виртуальный метод\n");
	Desc* y = new Desc();
	y->foo();
	delete y;
	Desc2* y1 = new Desc2();
	y1->foo();
	delete y1;
	Desc* y2 = new Desc2();
	y2->foo();
	delete y2;
	printf("У класса Desc2 foo2  виртуальный метод\n");
	Desc* y3 = new Desc();
	y3->foo2();
	delete y3;
	Desc2* y4 = new Desc2();
	y4->foo2();
	delete y4;
	Desc* y5 = new Desc2();
	y5->foo2();
	delete y5;
	printf("\n");

	printf("Проверка на принадлежность классу\n");
	printf("Если принадлежит, то вызывает метод\n");
	Animal* zoo[10];
	for (int i = 0; i < 10; i++)
		if (rand() % 2 == 0)
			zoo[i] = new Cat;
		else zoo[i] = new Dog;
	printf("Проверка на принадлежность классу(classname)\n");
	for (int i = 0; i < 10; i++)
		if (zoo[i]->classname() == "Dog")
			((Dog*)zoo[i])->chase_();
	printf("Проверка на принадлежность классу(ISA)\n ");
	for (int i = 0; i < 10; i++)
		if (zoo[i]->isA("Dog"))
			((Dog*)zoo[i])->chase_();
	printf("безопасное приведение типов \n Проверка на принадлежность классу(dynamic cast) \n");
	for (int i = 0; i < 10; i++)
	{
		Dog* d = dynamic_cast<Dog*>(zoo[i]);
		if (d != NULL)
			d->chase_();
	}
	printf("Опасное приведение типов(c-style)\n");
	//не можем вызвать метод chase, но можем sound()
	Animal* an = new Dog;
	an->sound();

	//если an привести к типу Dog*, тогда мы сможем вызвать chase_()
	Dog* an2 = (Dog*)an;
	an2->chase_();
	delete an;

	for (int i = 0; i < 10; i++)
		delete zoo[i];
	printf("\n Передача объектов как параметров в функции и возвращения объектов как результата из функции\n");
	printf("Передаем Base в функцию");
	printf("\n");
	{
		printf("func1()\n");
		func1(new Base);

		printf("func2()\n");
		func2(new Base);

		printf("func3()\n");
		func3(*(new Base));
	}
	printf("\n\n");

	printf("Передаем Desc в функцию");
	printf("\n");

	{
		printf("func1()\n");
		func1(new Desc);
		printf("func2()\n");
		func2(new Desc);
		printf("func3()\n");
		func3(*(new Desc));
	}
	printf("\n\n");


	printf("\n");
	{
		Base c;
		c.set(3);
		Base* p = &c;
		printf("Значение р: %p\n", p);
		printf("Значение с %d\n", c.get());

		printf("\n");
		printf("func1()\n");

		*p = func1();
		printf("Значение р: %p\n", p);
		printf("Значение с: %d\n", c.get());

		printf("\n");
		printf("func2()\n");

		p = func2();
		printf("p: %p\n", p);

		printf("func3()\n");

		printf("func3()\n");
		Base c2;
		c2.set(10);
		Base* p1 = &c2;
		printf("Значение р: %p\n", p1);
		printf("Значение с: %d\n", p1->get());

		*p1 = func3(p1);

		printf("Значение р:%p\n", p1);
		printf("Значение с:  %d\n", p1->get());

	}
	printf("\n");
	printf(" Умные указатели");

	printf("Работа с unique_ptr\n");

	//unique_ptr удалится сам, когда выйдет из области видимости
	unique_ptr<Clock> Clock1 = make_unique<Clock>();

	//item2 = nullptr
	unique_ptr<Clock> Clock2;

	cout << "Clock1: " << (static_cast<bool>(Clock1) ? "не nullptr\n" : "nullptr\n");
	cout << "Clock2: " << (static_cast<bool>(Clock2) ? "не nullptr\n" : "nullptr\n");

	//item1 превращается в nullptr
	Clock2 = move(Clock1);
	cout << "Clock1: " << (static_cast<bool>(Clock1) ? "не nullptr\n" : "nullptr\n");
	cout << "Clock2: " << (static_cast<bool>(Clock2) ? "не nullptr\n" : "nullptr\n");
	//при выходе из области видимости умный указатель сам себя уничтожит

	printf("Работа с shared_ptr\n");
	//// Выделяем Clock и передаем его в shared_ptr
	Clock* clock = new Clock;
	shared_ptr<Clock> ptr1(clock);
	{
		shared_ptr<Clock> ptr2(ptr1); // используем копирующую инициализацию для создания второго shared_ptr из ptr1, указывающего на тот же Clock

			cout << "Удален pointer\n";
	} // ptr2 выходит из области видимости здесь, но больше ничего не происходит

	cout << "Удален другой pointer\n";
	// ptr1 выходит из области видимости здесь, и выделенный Item уничтожается также здесь
	return 0;
}