// 命令模式练习.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>


using namespace std;


/*
命令模式：降低请求者与接收者之间的耦合
		新的命令更容易加入
		缺点：可能会导致某些系统需要过多的具体命令类 
使用创景：
1 请求调用者和请求接收者解耦
2 系统需要在不同的时间指定请求、将请求排队和执行命令
3 系统需要将一组操作组合在一起形成宏命令

*/
class Cooker {
public:
	// 烤串
	void makeChuaner() {
		cout << "烤串师傅进行了烤串" << endl;
	}
	void makeChicken() {
		cout << "烤串师傅进行了烤鸡翅" << endl;
	}
};


class Command {
public:
	Command(Cooker* cooker) {
		this->cooker = cooker;
	}
	virtual ~Command() {
		if (this->cooker != nullptr) {
			delete this->cooker;
			this->cooker = nullptr;
		}
	}


	// 菜单让最终的执行者干活
	virtual void execute() = 0;
protected:
	Cooker * cooker;
};


class CommandChuaner :public Command{
public:
	CommandChuaner(Cooker*cooker) :Command(cooker) {

	}
	// 最终让执行者干的工作
	virtual void execute() {
		this->cooker->makeChuaner();
	}
};
class CommandChicken :public Command {
public:
	CommandChicken(Cooker*cooker) :Command(cooker) {

	}
	virtual void execute() {
		this->cooker->makeChicken();
	}
};


// 管理命令的一个模块
// 服务员MM
class Waitress {
public:
	// 给服务员添加菜单
	void setCmd(Command* cmd) {
		this->cmd_list.push_back(cmd);
	}
	// 让服务员下单
	void notify() {
		list<Command*>::iterator it = cmd_list.begin();
		for (; it != cmd_list.end(); it++) {
			// 执行烤串
			(*it)->execute();
		}
	}
private:
	list<Command*> cmd_list;
};



int main()
{
	Waitress *mm = new Waitress;
	Command* chuanger = new CommandChuaner(new Cooker);
	Command* chicken1 = new CommandChicken(new Cooker);
	Command* chicken2 = new CommandChicken(new Cooker);
	// 把订单交给服务员
	mm->setCmd(chuanger);
	mm->setCmd(chicken1);
	mm->setCmd(chicken2);
	// 服务员让师傅烤串
	mm->notify();

	delete mm;


	system("pause");
    return 0;
}

