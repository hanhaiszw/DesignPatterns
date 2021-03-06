// 命令模式.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
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

// 创建病单  对医生隔离
class CommandEyes {
public:
	CommandEyes(Doctor* doctor) {
		this->doctor = doctor;
	}
	~CommandEyes() {
		if (doctor != nullptr) {
			delete doctor;
			doctor = nullptr;
		}
	}
	// 病单执行治疗的时候  实际是让医生执行治疗
	void treat() {
		doctor->treatEyes();
	}
private:
	Doctor * doctor;
};
class CommandNose {
public:
	CommandNose(Doctor* doctor) {
		this->doctor = doctor;
	}
	~CommandNose() {
		if (doctor != nullptr) {
			delete doctor;
			doctor = nullptr;
		}
	}

	void treat() {
		doctor->treatNose();
	}
private:
	Doctor * doctor;
};



int main()
{
#if 0
	// 直接找医生
	Doctor * doctor = new Doctor;
	doctor->treatEyes();
	doctor->treatNose();
#endif
	// 病单通过填写病单来找医生治疗
	CommandEyes* commandEyes = new CommandEyes(new Doctor);
	commandEyes->treat();

	CommandNose* commandNose = new CommandNose(new Doctor);
	commandNose->treat();

	system("pause");
    return 0;
}

