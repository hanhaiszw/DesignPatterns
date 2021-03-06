// 依赖倒转原则.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#if 0
class Benz {
public:
	void run() {
		cout << "奔驰启动了" << endl;
	}
};
class BMW {
public:
	void run() {
		cout << "宝马启动了" << endl;
	}
};
class Zhang3 {
public:
	void driveBenz(Benz *b) {
		b->run();
	}
	void driveBMW(BMW *b) {
		b->run();
	}
	//每次开不同的车都需要改动大量的代码
	//非常不合适
};

#endif //  0


//依赖倒转原则   
//分为抽象层和实现层
//将业务层和实现层通过抽象层隔离
//抽象层
class Car{
public: 
	virtual void run() = 0;
};
class Driver {
public:
	virtual void drive(Car* car) = 0;
};

//实现层
class Zhang3 :public Driver {
public:
	virtual void drive(Car *car) {
		cout << "张三开车了" << endl;
		car->run();
	}
};
class Li4 :public Driver {
public:
	virtual void drive(Car *car) {
		cout << "李四开车了" << endl;
		car->run();
	}
};

class Benz :public Car {
public:
	virtual void run() {
		cout << "奔驰启动了" << endl;
	}
};
class BMW :public Car {
public:
	virtual void run() {
		cout << "宝马启动了" << endl;
	}
};


//业务
int main()
{
#if 0
	//张三去开奔驰
	Benz * benz = new Benz;
	Zhang3 *z = new Zhang3;
	z->driveBenz(benz);

	//张三去开宝马
	BMW* bmw = new BMW;
	z->driveBMW(bmw);
#endif 

	//张三去开奔驰
	Car* c = new Benz;
	Driver* d = new Zhang3;
	d->drive(c);

	//李四去开宝马
	Car* bmw = new BMW;
	Driver* li = new Li4;
	li->drive(bmw);

	// 张三去开宝马
	d->drive(bmw);

	system("pause");
    return 0;
}

