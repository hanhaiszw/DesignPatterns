// 适配器模式.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// 5V电压类   没有
class V5 {
public:
	/*void useV5() {
		cout << "使用了V5的电压充电" << endl;
	}*/
	virtual void useV5() = 0;
};


// 目前只有v220
class V220 {
public:
	void useV220() {
		cout << "使用了V220的电压充电" << endl;
	}
};

// 定义一个中间的适配器类
// adapter可以使用v220 
// 通过创建适配器    让iPhone用到访问不到的V220类
class Adapter :public V5 {
public:
	Adapter(V220* v220) {
		this->v220 = v220;
	}
	~Adapter() {
		if (this->v220 != NULL) {
			delete this->v220;
		}
	}

	virtual void useV5() {
		this->v220->useV220();
	}
private:
	V220 * v220;
};


class iPhone {
public:
	iPhone(V5* v5) {
		this->v5 = v5;
	}
	iPhone() {
		if (this->v5 != NULL) {
			delete this->v5;
		}
	}

	// 充电的方法
	void charge() {
		cout << "iphone手机进行充电" << endl;
		v5->useV5();
	}
private:
	V5 * v5;
};



int main()
{
	iPhone* iphone = new iPhone(new Adapter(new V220));
	iphone->charge();

	system("pause");
	return 0;
}

