// 装饰器模式.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/*
	和代理模式一样，都是通过组合的方式，给类添加新的功能
	不同的是，装饰器模式可以不断的嵌套，添加新的功能
	代理模式一般是静态给类添加新的功能，不能嵌套
	装饰器是动态的给类添加小功能
*/


// 抽象的手机类
class Phone {
public:
	virtual void show() = 0;
};

class iPhone :public Phone {
public:
	virtual void show() {
		cout << "秀出了iPhone" << endl;
	}
};
class Mi :public Phone {
public:
	virtual void show() {
		cout << "秀出了小米手机" << endl;
	}
};



// 写一个装饰器
class Decorator :public Phone {

public:
	Decorator(Phone* phone) {
		this->phone = phone;
	}

	virtual void show() = 0;
protected:
	Phone * phone;  // 拥有一个父类指针
};

// 具体的贴膜装饰器
class MoDecorator :public Decorator {
public:
	MoDecorator(Phone* phone) :Decorator(phone) {

	}
	virtual void show() {
		// 保持原有的show
		this->phone->show();
		// 额外添加一个膜的方法
		this->mo();
	}

	void mo() {
		cout << "手机有了贴膜" << endl;
	}
};

// 皮套装饰器
class TaoDecorator :public Decorator {
public:
	TaoDecorator(Phone*phone) :Decorator(phone) {

	}
	virtual void show() {
		// 保持原有的show
		this->phone->show();
		// 额外添加一个皮套的方法
		this->tao();
	}

	void tao() {
		cout << "手机有了皮套" << endl;
	}

};


int main()
{
	Phone *phone = new iPhone;
	//Phone *phone = new Mi;
	phone->show();

	// 加膜
	cout << "-----------------------------------" << endl;
	Phone* moPhone = new MoDecorator(phone);
	moPhone->show();


	// 加皮套
	cout << "-----------------------------------" << endl;
	Phone * taoPhone = new TaoDecorator(phone);
	taoPhone->show();



	// 加膜加皮套
	cout << "-----------------------------------" << endl;
	Phone * moTaoPhone = new TaoDecorator(moPhone);
	moTaoPhone->show();  // moPhone.show() + tao() == phone.show()+mo()+tao();



	system("pause");
    return 0;
}

