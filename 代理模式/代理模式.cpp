// 代理模式.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;



// 商品
class Item {
public:
	Item(string kind, bool fact) {
		this->kind = kind;
		this->fact = fact;
	}
	string getKind() { return kind; }
	bool getFact() { return fact; }
private:
	string kind;// 商品的种类
	bool fact; // 真假
};


// 抽象的购物方式
class Shopping {
public:
	virtual void buy(Item* it) = 0; // 抽象买东西方法
};


// 具体购物方式
class KoreaShoping :public Shopping {
public:
	virtual void buy(Item* it) {
		cout << "去韩国买了" << it->getKind() << endl;
	}
};
class USAShoping :public Shopping {
public:
	virtual void buy(Item* it) {
		cout << "去美国买了" << it->getKind() << endl;
	}
};



// 使用代理
// 注意代理也是shopping的子类
class OverseasProxy :public Shopping {
public:
	OverseasProxy(Shopping* shopping) {
		this->shopping = shopping;
	}

	// 由代理来执行具体的购买逻辑
	virtual void buy(Item*it) {
		// 1 辨别商品的真假
		// 2 进行购买
		// 3 通过海关安检，带回祖国
		if (it->getFact()) {
			cout << "1 发现正品，需要购买" << endl;
			// 2 购买
			shopping->buy(it);
			// 3 通过海关安检  带回祖国
			cout << "3 通过海关安检  带回祖国" << endl;
		}
		else {
			cout << "1 发现假货，不会购买" << endl;
		}
	}
private:
	Shopping * shopping; // 购物方式
};

int main()
{
	// 1 辨别商品的真假
	// 2 进行购买
	// 3 通过海关安检，带回祖国

	Item it1("nike鞋", true);
	Item it2("CET4证书", false);
	Shopping * koreaShopping = new KoreaShoping;
#if 0
	
	// 1 
	if (it1.getFact()==true) {
		cout << "1 发现正品，要购物" << endl;
		// 2 去韩国买商品
		koreaShopping->buy(&it1);
	}

	// 3 通过海关安检  带回祖国
	cout << "3 通过海关安检  带回祖国" << endl;
#endif

	Shopping *usaShopping = new USAShoping;
	OverseasProxy* overseasProxy = new OverseasProxy(usaShopping);
	overseasProxy->buy(&it2);

	overseasProxy->buy(&it1);

	OverseasProxy* overseasProxy1 = new OverseasProxy(koreaShopping);
	overseasProxy1->buy(&it1);

	system("pause");
    return 0;
}

