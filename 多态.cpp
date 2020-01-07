#include<iostream>
using namespace std;
//C++的多态特性是通过虚函数和纯虚函数实现的
//可以通过通过基类指针访问派生类定义的函数 
//虚函数只能借助于指针或者引用来达到多态的效果 
class A
{
public:
	void foo()
	{
		printf("1\n");
	}
	virtual  void fun()
	{
		printf("2\n");
	}
};
class B : public A
{
public:
	void foo()
	{
		printf("3\n");
	}
	void fun()
	{
		printf("4\n");
	}
};
int main(void)
{
	A a;
	B b;
	a.fun(); 
	A *p = &a;
	p->foo();
	p->fun();
	p = &b;
	p->foo();
	p->fun();
	return 0;
} 

