#include<iostream>
using namespace std;
//C++�Ķ�̬������ͨ���麯���ʹ��麯��ʵ�ֵ�
//����ͨ��ͨ������ָ����������ඨ��ĺ��� 
//�麯��ֻ�ܽ�����ָ������������ﵽ��̬��Ч�� 
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

