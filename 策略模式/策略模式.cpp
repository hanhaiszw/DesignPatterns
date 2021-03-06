// 策略模式.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// 抽象的策略
class AbstractStrategy {
public:
	// 纯虚函数   使用具体的策略
	virtual void useWeapon() = 0;
};

class KnifeStrategy :public AbstractStrategy {
public:
	virtual void useWeapon() {
		cout << "使用匕首，进行近战攻击" << endl;
	}

};
class AkStrategy :public AbstractStrategy {
public:
	virtual void useWeapon() {
		cout << "使用ak，进行远程射击" << endl;
	}

};


class Hero {
public:
	Hero() {
		strategy = NULL;
	}
	void setStrategy(AbstractStrategy* strategy) {
		this->strategy = strategy;
	}
	// 攻击方式
	void fight() {
		cout << "英雄开始战斗了" << endl;
		this->strategy->useWeapon();
	}
private:
	AbstractStrategy * strategy;
};

int main()
{
	AbstractStrategy* knife = new KnifeStrategy;
	AbstractStrategy* ak47 = new AkStrategy;

	Hero* hero = new Hero;
	cout << "---------------------------------------" << endl;
	cout << "远程兵来了，更换远程攻击" << endl;

	hero->setStrategy(ak47);
	hero->fight();

	cout << "---------------------------------------" << endl;
	cout << "近战兵来了，更换近战攻击" << endl;
	hero->setStrategy(knife);
	hero->fight();


	system("pause");
    return 0;
}

