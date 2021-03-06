// 外观模式.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/*
	根据迪米特法则：减少类之间相互了解
	使用中介
*/


class SysA {
public:
	void operationA() {
		cout << "sysA..." << endl;
	}
};

class SysB {
public:
	void operationB() {
		cout << "sysB..." << endl;
	}
};

class SysC {
public:
	void operationC() {
		cout << "sysC..." << endl;
	}
};

class SysD {
public:
	void operationD() {
		cout << "sysD..." << endl;
	}
};

class Facade {
public:
	void methodOne() {
		sysa.operationA();
		sysb.operationB();
	}
	void methodTwo() {
		sysc.operationC();
		sysd.operationD();
	}
private:
	SysA sysa;
	SysB sysb;
	SysC sysc;
	SysD sysd;
};

int main()
{
#if 0
	SysA sa;
	SysB sb;
	sa.operationA();
	sb.operationB();
#endif
	// 这样只用给facade接触就好了
	// 不用去关心SysA ... SysD
	Facade facade;
	// AB方法组合
	facade.methodOne();
	facade.methodTwo();

	system("pause");
    return 0;
}

