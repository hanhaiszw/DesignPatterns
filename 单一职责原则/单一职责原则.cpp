// 单一职责原则.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/*
   把类的方法分离出来，
   就能保证类的职责单一

   提高安全性，提高可维护性，提高了可读性，缺点生成大量类

*/
//一般方式
class Clothes {
public:
	void shopping() {
		cout << "休闲服装" << endl;
	}
	void working() {
		cout << "正式服装" << endl;
	}
};


//单一职责原则
class ClothesShopping {
public:
	void style() {
		cout << "休闲服装" << endl;
	}
};
class ClothesWorking {
public:
	void style() {
		cout << "正式服装" << endl;
	}
};

int main()
{
	//工作中
	Clothes c1;
	c1.shopping();

	//逛街中
	Clothes c2;
	c2.working();


	ClothesShopping cs;
	cs.style();

	ClothesWorking cw;
	cw.style();


	system("pause");
    return 0;
}

