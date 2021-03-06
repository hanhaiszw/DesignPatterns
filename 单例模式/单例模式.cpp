// 单例模式.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Singleton {
private:
	// 不让类外再创建实例
	Singleton() {

	}
	static Singleton* instance; // 指向本类唯一实例的指针
public:
	static Singleton* getInstance() {
		return instance;
	}
};
// 饿汉式  多线程时安全
// 在类的外部初始化  饿汉式    在编译期间，唯一单例已经创建
Singleton* Singleton::instance = new Singleton;



class Singleton2 {
private:
	// 不让类外再创建实例
	Singleton2() {

	}
	static Singleton2* instance; // 指向本类唯一实例的指针
public:
	static Singleton2* getInstance() {
		// 需要保证多线程安全  要在此处加锁

		if (instance == NULL) {
			instance = new Singleton2;
		}

		// 释放锁

		return instance;
	}
};
// 多线程时，懒汉式不安全
// 懒汉式   第一次使用时，创建对象
Singleton2* Singleton2::instance = NULL;


int main()
{
	// 获取实例
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();

	if (s1 == s2) {
		cout << "s1==s2" << endl;
	}


	Singleton2* s3 = Singleton2::getInstance();
	Singleton2* s4 = Singleton2::getInstance();

	if (s3 == s4) {
		cout << "s3==s4" << endl;
	}


	system("pause");
	return 0;
}

