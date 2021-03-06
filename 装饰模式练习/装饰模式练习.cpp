// 装饰模式练习.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Hero {
public:
	virtual void status() = 0;
};


class Akali :public Hero {
public:
	virtual void status() {
		cout << "HP: 1000" << endl;
		cout << "AP: 500" << endl;
		cout << "AD: 50" << endl;
	}
};

// 英雄装饰器
class Decorator :public Hero {
public:
	Decorator(Hero* hero) {
		this->hero = hero;
	}
	virtual void status() = 0;
protected:
	Hero * hero;
};


// 日炎斗篷的装饰器
class RYDecorator :public Decorator {
public:
	RYDecorator(Hero* hero):Decorator(hero) {
		
	}
	virtual void status() {
		this->hero->status();  // 先调用被装饰英雄的基本状态
		cout << "HP + 1000" << endl;
	}
};

// 深渊权杖装备的装饰器
class SYQZDecorator :public Decorator {
public:
	SYQZDecorator(Hero* hero) :Decorator(hero) {

	}
	virtual void status() {
		this->hero->status();  // 先调用被装饰英雄的基本状态
		cout << "AP + 50000" << endl;
	}
};



int main()
{
	// 需要注意的是   三个akali不是同一个
	Hero *akali = new Akali;
	cout << "akali的初始状态" << endl;
	akali->status();

	cout << "日炎斗篷装饰器" << endl;
	Decorator* ryAkali = new RYDecorator(akali);
	ryAkali->status();

	cout << "再添加深渊权杖装饰器" << endl;
	Hero* syAkali = new SYQZDecorator(ryAkali);
	syAkali->status();


	system("pause");
	return 0;
}

