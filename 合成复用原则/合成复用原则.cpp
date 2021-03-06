// 合成复用原则.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Cat {
public:
	void sleep() {
		cout << "小猫睡觉了" << endl;
	}
};
//向猫中添加一个功能，创建一个新猫，既能够睡觉，又能吃东西
//通过继承的方式完成
//如果使用继承方式，那么新类会和原有类，高度耦合
class AdvCat :public Cat {
public:
	void eatAndSleep() {
		cout << "吃东西" << endl;
		sleep();
	}
};


//使用组合的方式来添加小猫的吃东西方式
//降低了AdvCat2和Cat的耦合度，跟Cat的父类没有任何关系，只能跟Cat的实例化方法有关系
class AdvCat2 {
public:
	AdvCat2(Cat* cat) {
		this->cat = cat;
	}
	void eatAndSleep() {
		cout << "吃东西" << endl;
		cat->sleep();
	}
private:
	Cat * cat;
};



int main()
{
	Cat c;
	c.sleep();

	AdvCat ac;
	ac.eatAndSleep();

	cout << "----------" << endl;

	AdvCat2 ac2(&c);
	ac2.eatAndSleep();

	system("pause");
    return 0;
}

