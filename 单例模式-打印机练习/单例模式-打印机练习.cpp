// 单例模式-打印机练习.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Printer {
public:
	static Printer* getInstance() {
		return instance;
	}
	void print(string text) {
		cout << "打印的内容是 " << text << endl;
		sequence++;
		cout << "今天已经打印了" << sequence << "条" << endl;
	}
	static int getCnt() {
		return sequence;
	}
private:
	static Printer* instance;
	static int sequence;
	// 用以释放单例
	// 可以不使用 程序执行完毕   垃圾会被释放
	// 单例实例不会引起内存泄漏
	// 因此一般不使用下面回收的代码
	class Garbo {
	public:
		~Garbo() {
			if (instance != nullptr) {
				delete instance;
			}
		}
	};
	// 在静态区开辟一个对象，析构单例
	static Garbo garbo;
};
Printer* Printer::instance = new Printer;
int Printer::sequence = 0;
Printer::Garbo Printer::garbo;


int main()
{
	// 员工1
	Printer* p1 = Printer::getInstance();
	p1->print("打印一份简历");


	Printer* p2 = Printer::getInstance();
	p2->print("打印游戏皮肤");

	Printer* p3 = Printer::getInstance();
	p3->print("打印一份试卷");

	system("pause");
    return 0;
}

