// 命令模式1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <list>


using namespace std;

// 系统的一个核心类方法
class Doctor {
public:
	// 治疗眼睛的方法
	void treatEyes() {
		cout << "医生治疗了眼睛" << endl;
	}
	// 治疗鼻子的方法
	void treatNose() {
		cout << "医生治疗了鼻子" << endl;
	}
};


// 定义一个抽象的订单
class Command {
public:
	Command(Doctor* doctor) {
		this->doctor = doctor;
	}

	virtual ~Command() {
		if (doctor != nullptr) {
			delete doctor;
			doctor = nullptr;
		}
	}
	virtual void treat() = 0;

protected:
	Doctor * doctor;
};


// 创建病单  对医生隔离
class CommandEyes:public Command {
public:
	CommandEyes(Doctor* doctor):Command(doctor) {
		
	}
	
	// 病单执行治疗的时候  实际是让医生执行治疗
	virtual void treat() {
		doctor->treatEyes();
	}
};

class CommandNose :public Command {
public:
	CommandNose(Doctor* doctor) :Command(doctor) {
		
	}
	
	virtual void treat() {
		doctor->treatNose();
	}
};

#if 0
// 创建一个护士   
// 需要一个护士来填写订单
class Nurse {
public:
	Nurse(Command* cmd) {
		this->cmd = cmd;
	}
	//下发订单
	void notify() {
		this->cmd->treat();
	}
private:
	Command * cmd;
};
#endif

// 护士长
class NurseBoss {
public:
	NurseBoss() {
		m_list.clear();
	}
	~NurseBoss() {
		m_list.clear();
	}

	// 给护士长添加病单的方法
	void setCmd(Command* cmd) {
		m_list.push_back(cmd);
	}

	// 下发所有的病单执行
	void notify() {
		for (list<Command*>::iterator it = m_list.begin(); it != m_list.end(); it++) {
			(*it)->treat();
		}
	}

private:
	list<Command*> m_list;
};

int main()
{
#if 0
	// 直接找医生
	Doctor * doctor = new Doctor;
	doctor->treatEyes();
	doctor->treatNose();
#endif
	NurseBoss *woman = new NurseBoss;
	Command *cmd1 = new CommandEyes(new Doctor);
	Command *cmd2 = new CommandNose(new Doctor);

	// 将指令都给护士长
	woman->setCmd(cmd1);
	woman->setCmd(cmd2);

	// 病人与护士长交互   护士长与病单交互  病单与医生交互
	// 护士长执行   由护士长再叫医生治病
	woman->notify();

	system("pause");
	return 0;
}
