// 开闭原则.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#if 0
class Banker {
public:
	void save() {
		cout << "存款" << endl;
	}
	void pay() {
		cout << "支付" << endl;
	}
	void transfer() {
		cout << "转账" << endl;
	}

	//添加一个办理基金
	void fund() {
		cout << "办理基金" << endl;
	}
};
#endif



//开闭原则
//1 提高可读性  2 提高了安全性  3 提高了可维护性  4 提高了可复用性
//再添加新功能时，不应该更改原来的类代码
class AbstractBanker {
public:
	virtual void work() = 0;
};

//存款
class SaveBanker :public AbstractBanker {
public:
	virtual void work() {
		cout << "存款" << endl;
	}
};

//支付
class PayBanker :public AbstractBanker {
public:
	virtual void work() {
		cout << "支付" << endl;
	}
};

//转账
class TransBanker :public AbstractBanker {
public:
	virtual void work() {
		cout << "转账" << endl;
	}
};

//添加新方法  之前的代码就不用再改了
//与一般方法相比：防止了新添加的代码，影响原来代码的正常运行
class FuncBanker :public AbstractBanker {
public:
	virtual void work() {
		cout << "办理基金" << endl;
	}
};

int main()
{
#if 0
	Banker b;
	b.save();
	b.pay();
	b.transfer();
	b.fund();
#endif

	AbstractBanker *sb = new SaveBanker;
	sb->work();

	delete sb;


	AbstractBanker *tb = new TransBanker;
	tb->work();

	delete tb;

	AbstractBanker *fb = new FuncBanker;
	fb->work();

	delete fb;

	system("pause");
    return 0;
}

