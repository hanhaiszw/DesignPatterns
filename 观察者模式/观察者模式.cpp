// 观察者模式.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

// 观察者
class Listenner {
public:
	// 老师来了 我该怎么办
	virtual void onTeacherComming() = 0;
	// 做坏事
	virtual void doBadThing() = 0;
};


class Notifier {
public:
	virtual void addListener(Listenner* listenner) = 0;
	virtual void delListener(Listenner* listenner) = 0;
	// 通知所有的观察者
	virtual void notify() = 0;
};


class Student :public Listenner {
public:
	Student(string name,string badthing) {
		this->name = name;
		this->badthing = badthing;
	}
	// 老师来了 我该怎么办
	virtual void onTeacherComming() {
		cout << "学生"<<name<<"发现班长给我使眼神了，"<<"停止" << badthing << endl;
		cout << "改为写作业" << endl;
	}
	// 
	virtual void doBadThing() {
		cout << "学生" << name << "正在" << badthing << endl;
	}
private:
	string name;
	string badthing;
};


// 具体的通知者
class Monitor:public Notifier {
public:
	virtual void addListener(Listenner* listenner) {
		l_list.push_back(listenner);
	}
	virtual void delListener(Listenner* listenner) {
		l_list.remove(listenner);
	}
	// 通知所有的观察者
	virtual void notify() {
		for (list<Listenner*>::iterator it = l_list.begin(); it != l_list.end(); it++) {
			(*it)->onTeacherComming();

			//如果在此再触发班长的notify，这样就出现无限循环 卡死
			
		}
	}
private:
	list<Listenner*> l_list;//班长手中所有的学生
};

int main(void)
{
	Listenner* s1 = new Student("张三", "抄作业");
	Listenner* s2 = new Student("李四", "打LOL");
	Listenner* s3 = new Student("王五", "看李四在打LOL");

	Notifier* bossXu = new Monitor;
	// 添加学生列表
	// 把观察者添加到列表   好让通知者通知
	bossXu->addListener(s1);
	bossXu->addListener(s2);
	bossXu->addListener(s3);

	cout << "----------------------------------------------" << endl;
	cout << "教室一片和谐，老师没有来" << endl;
	s1->doBadThing();
	s2->doBadThing();
	s3->doBadThing();

	// 不通知张三
	//bossXu->delListener(s1);

	cout << "----------------------------------------------" << endl;
	cout << "班长发现老师来了，给学生们使眼神" << endl;
	bossXu->notify();


	cout << "----------------------------------------------" << endl;
	system("pause");
    return 0;
}

