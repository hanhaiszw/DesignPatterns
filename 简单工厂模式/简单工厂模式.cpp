// 简单工厂模式.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#if 0
class Fruit {
public:
	Fruit(string kind) {
		this->kind = kind;
		if (kind == "apple") {
			//代表苹果
			//苹果的初始化方式
		}
		else if (kind == "banana") {
			//代表香蕉
			//香蕉的初始化方式
		}
	}
	void getName() {
		if (this->kind == "apple") {
			cout << "我是苹果" << endl;
		}
		else if (this->kind == "banana") {
			cout << "我是香蕉" << endl;
		}
	}
	
private:
	string kind;
};
#endif

//简单工厂方法实现
//抽象的水果类
class Fruit {
public:
	virtual void getName() = 0;
};

class Apple :public Fruit {
public:
	virtual void getName() {
		cout << "我是苹果" << endl;
	}
};
class Banana :public Fruit {
public:
	virtual void getName() {
		cout << "我是香蕉" << endl;
	}
};

class Pear :public Fruit {
public:
	virtual void getName() {
		cout << "我是鸭梨" << endl;
	}
};

//水果工厂
class Factory {
public:
	//水果生产器
	Fruit * createFruit(string kind) {
		Fruit* fruit = nullptr;
		if (kind == "apple") {
			fruit = new Apple;
		}
		else if (kind == "banana") {
			fruit = new Banana;
		}
		else if (kind == "pear") {   //添加一个鸭梨，修改了工厂类，违背了开闭原则
			fruit = new Pear;
		}
		return fruit;
	}
};


int main()
{
#if 0
	//创建一个苹果
	//main函数跟构造函数的相关度太大，随着水果的种类增加，构造方式，变得更复杂
	Fruit* apple = new Fruit("apple");
	apple->getName();
	delete apple;
#endif // 0

	//人们是跟工厂打交道的
	Factory* factory = new Factory;
	//苹果
	Fruit* apple = factory->createFruit("apple");
	apple->getName();

	Fruit* banana = factory->createFruit("banana");
	banana->getName();

	Fruit* pear = factory->createFruit("pear");
	pear->getName();


	delete apple;
	delete banana;
	delete pear;
	delete factory;	


	system("pause");
    return 0;
}

