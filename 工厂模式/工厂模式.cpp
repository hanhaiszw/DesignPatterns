// 工厂模式.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class Fruit {
public:
	virtual void getName() = 0;
};

class Apple: public Fruit {
public:
	virtual void getName() {
		cout << "我是苹果" << endl;
	}
};
class Banana : public Fruit {
public:
	virtual void getName() {
		cout << "我是香蕉" << endl;
	}
};

class AbstractFactory {
public:
	virtual Fruit* createFruit() = 0;
};

// 具体工厂
class AppleFactory :public AbstractFactory {
public:
	virtual Fruit* createFruit() {
		return new Apple;
	}
};
class BananaFactory :public AbstractFactory {
public:
	virtual Fruit* createFruit() {
		return new Banana;
	}
};

// 添加一个梨     
// 没有修改之前的代码   符合开闭原则
class Pear :public Fruit {
public:
	virtual void getName() override {
		cout << "我是鸭梨" << endl;
	}
};
class PearFactory :public AbstractFactory {
public:
	virtual Fruit* createFruit() {
		return new Pear;
	}
};


int main()
{
	// 来一个香蕉工厂
	AbstractFactory* banaFactory = new BananaFactory;
	// 来一个水果
	Fruit* banana = banaFactory->createFruit();
	banana->getName();

	AbstractFactory* appleFactory = new AppleFactory;
	Fruit* apple = appleFactory->createFruit();
	apple->getName();

	AbstractFactory* pearFactory = new PearFactory;
	Fruit* pear = pearFactory->createFruit();
	pear->getName();


	// 释放new对象空间

	system("pause");
    return 0;
}

