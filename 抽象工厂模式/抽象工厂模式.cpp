// 抽象工厂模式.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Fruit {
public:
	virtual void getName() = 0;
};

class AbstractFactory {
public:
	virtual Fruit* createApple() = 0;
	virtual Fruit* createBanana() = 0;

};

class USAApple:public Fruit
{
public:
	virtual void getName() {
		cout << "我是美国苹果" << endl;
	}
};
class USABanana :public Fruit
{
public:
	virtual void getName() {
		cout << "我是美国香蕉" << endl;
	}
};

class ChinaApple :public Fruit
{
public:
	virtual void getName() {
		cout << "我是中国苹果" << endl;
	}
};
class ChinaBanana :public Fruit
{
public:
	virtual void getName() {
		cout << "我是中国香蕉" << endl;
	}
};

class JapanApple :public Fruit
{
public:
	virtual void getName() {
		cout << "我是日本苹果" << endl;
	}
};
class JapanBanana :public Fruit
{
public:
	virtual void getName() {
		cout << "我是日本香蕉" << endl;
	}
};



// 美国具体工厂
class USAFactory :public AbstractFactory {
public:
	virtual Fruit* createApple() {
		return new USAApple;
	}
	virtual Fruit* createBanana() {
		return new USABanana;
	}
};
// 中国具体工厂
class ChinaFactory :public AbstractFactory {
public:
	virtual Fruit* createApple() {
		return new ChinaApple;
	}
	virtual Fruit* createBanana() {
		return new ChinaBanana;
	}
};
// 日本具体工厂
class JapanFactory :public AbstractFactory {
public:
	virtual Fruit* createApple() {
		return new JapanApple;
	}
	virtual Fruit* createBanana() {
		return new JapanBanana;
	}
};


// 如果要添加一个鸭梨，就必须修改原有代码，不符合开闭原则，
// 如果产品等级结构稳定的话，可以用抽象工厂模式
// 上面国家产地是一个产品组
// 几种苹果为一个产品等级结构


// 简单工厂模式 + 开闭原则 = 工厂方法模式
// 工厂方法模式 + 产品族 = 抽象工厂方法


int main()
{
	AbstractFactory* factory = new USAFactory;
	Fruit* fruit = factory->createApple();
	fruit->getName();


	system("pause");
    return 0;
}

