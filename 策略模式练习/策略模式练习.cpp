// 策略模式练习.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


// 
class AbstractStrategy {
public:
	// 商品具体的销售策略计算方式
	virtual double getPrice(double price) = 0;
};


// 商品
class Item {
public:
	Item(string name, double price) {
		this->name = name;
		this->price = price;
	}

	// 提供一个可以更换策略的方法

	void setStrategy(AbstractStrategy* strategy) {
		this->strategy = strategy;
	}

	double SellPrice() {
		return this->strategy->getPrice(this->price);
	}
private:
	string name;
	double price; // 商品的价格
	// 销售的策略
	AbstractStrategy* strategy;
};


class StrategyA :public AbstractStrategy {
public:
	virtual double getPrice(double price) {
		return 0.8*price;
	}
};
class StrategyB :public AbstractStrategy {
public:
	virtual double getPrice(double price) {
		if (price >= 200) {
			price = price - 100;
		}
		return price;
	}
};




int main()
{

	Item it("nike鞋",200);
	AbstractStrategy* sA = new StrategyA;
	AbstractStrategy* sB = new StrategyB;

	cout << "上午 商场执行策略A  全场八折" << endl;
	it.setStrategy(sA);
	cout << "nike鞋应该卖" << it.SellPrice() << endl;


	cout << "-----------------------------" << endl;
	cout << "下午 商场执行策略B  满200减100" << endl;
	it.setStrategy(sB);
	cout << "nike鞋应该卖" << it.SellPrice() << endl;

	system("pause");
    return 0;
}

