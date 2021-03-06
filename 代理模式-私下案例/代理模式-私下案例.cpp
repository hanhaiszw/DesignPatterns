// 代理模式-私下案例.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


// 抽象的美女类
class BeautyGirl {
public:
	// 1 跟男人抛媚眼
	virtual void MakeEyesWithMan() = 0;
	// 2 与男人共度美好时光
	virtual void HappyWithMan() = 0;
};

class JinLian :public BeautyGirl {
public:
	// 1 跟男人抛媚眼
	virtual void MakeEyesWithMan() {
		cout << "潘金莲抛了个媚眼" << endl;
	}
	// 2 与男人共度美好时光
	virtual void HappyWithMan() {
		cout << "潘金莲与你约会" << endl;
	}
};

// 代理
class WangPo :public BeautyGirl {
public:
	WangPo(BeautyGirl *girl) {
		this->girl = girl;
	}


	//王婆让手里的美女抛媚眼  和你约会
	// 1 跟男人抛媚眼
	virtual void MakeEyesWithMan() {
		//...
		girl->MakeEyesWithMan();
		//...
	}
	// 2 与男人共度美好时光
	virtual void HappyWithMan() {
		//...
		girl->HappyWithMan();
		//...
	}
private:
	BeautyGirl * girl;
};


// 西门大官人
int main()
{
	BeautyGirl* jinlian = new JinLian;
	WangPo* wangpo = new WangPo(jinlian);

	// 让金莲抛媚眼
	wangpo->MakeEyesWithMan();
	// 让金莲约会
	wangpo->HappyWithMan();


	system("pause");
	return 0;
}

