// 外观模式-家庭影院练习.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class TV {
public: 
	void On() {
		cout << "电视打开了" << endl;
	}
	void Off() {
		cout << "电视关闭了" << endl;
	}

};
class DVD {
public:
	void On() {
		cout << "DVD打开了" << endl;
	}
	void Off() {
		cout << "DVD关闭了" << endl;
	}

};

class XBox {
public:
	void On() {
		cout << "XBox打开了" << endl;
	}
	void Off() {
		cout << "XBox关闭了" << endl;
	}

};

class MikePhone {
public:
	void On() {
		cout << "MikePhone打开了" << endl;
	}
	void Off() {
		cout << "MikePhone关闭了" << endl;
	}

};

class Light {
public:
	void On() {
		cout << "Light打开了" << endl;
	}
	void Off() {
		cout << "Light关闭了" << endl;
	}

};






class HomePlayer {
public:
	// ktv模式
	void doKTV() {
		light.Off();
		tv.On();
		dvd.On();
	}
	// 游戏模式
	void doGame() {
		tv.On();
		xbox.On();
	}
private:
	Light light;
	XBox xbox;
	DVD dvd;
	MikePhone mikephone;
	TV tv;
};

int main()
{
	HomePlayer homeplayer;
	cout << "-----------------------进入ktv模式-----------------------" << endl;
	homeplayer.doKTV();


	cout << "-----------------------进入游戏模式-----------------------" << endl;
	homeplayer.doGame();

	system("pause");
    return 0;
}

