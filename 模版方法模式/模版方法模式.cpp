// 模版方法模式.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;



class MakeDrink {
public:
	// 1 把水煮开
	void boil() {
		cout << "把水煮开" << endl;
	}
	// 2 冲某物
	virtual void brew() = 0;
	// 3 从大杯倒入小杯
	void putInCup() {
		cout << "把冲泡好的饮料从大杯倒入小杯" << endl;
	}
	// 4 加一些作料
	virtual void addThings() = 0;


	// 钩子函数    hook   修改固定的业务逻辑
	// 让实现类自定义是否添加其他东西
	virtual bool CustomWantAddThings() {
		return true;
	}

	// 业务逻辑的统一模板
	void make() {
		boil();
		brew();
		putInCup();

		if (CustomWantAddThings()==true) {
			addThings();
		}		
	}
};



class MakeCoffee :public MakeDrink {
public:
	MakeCoffee(bool isAdd) {
		this->isAdd = isAdd;
	}
	// 2 冲某物
	virtual void brew() {
		cout << "冲泡咖啡豆" << endl;
	}
	
	// 4 加一些作料
	virtual void addThings() {
		cout << "添加糖和牛奶" << endl;
	}

	virtual bool CustomWantAddThings() {
		//return false;
		return isAdd;
	}
private:
	bool isAdd;
};
class MakeTea :public MakeDrink {
public:
	MakeTea(bool isAdd) {
		this->isAdd = isAdd;
	}
	// 2 冲某物
	virtual void brew() {
		cout << "冲泡茶叶" << endl;
	}

	// 4 加一些作料
	virtual void addThings() {
		cout << "添加柠檬或者菊花" << endl;
	}

	virtual bool CustomWantAddThings() {
		//return false;
		return isAdd;
	}

private:
	bool isAdd;
};


int main()
{
	MakeDrink* makeCoffee = new MakeCoffee(true);
	makeCoffee->make();


	cout << "-----------------------------------" << endl;
	MakeDrink* makeTea = new MakeTea(false);
	makeTea->make();

	system("pause");
    return 0;
}

