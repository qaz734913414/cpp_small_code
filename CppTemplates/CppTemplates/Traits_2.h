#pragma once
#include <iostream>
using namespace std;

struct no_move{};
struct has_move {};

struct ValueType{
public:
	void move(){cout <<"move a ValueType" << endl;}
};

template<typename T>
struct traits{
	typedef no_move move_method;//����traitsģ���࣬Ĭ��Ϊ��move����
	void move(T* p){}//Ĭ��Ϊ��move����
};

template <> struct 
traits<ValueType>{
	typedef has_move move_method;//����myValueType��traitsģ��ƫ�ػ�����������move����
	void move(ValueType* p){p->move();} //ģ���ػ�����move����
};

template <typename T> 
struct Container{
	void move(T* p){traits<T>().move(p);};
};

void test_06()
{
	int i=101;
	int *p1=&i;
	ValueType v1;
	ValueType *pv=&v1;
	Container<int> c1;
	Container<ValueType> c2;
	c1.move(p1);
	c2.move(pv);

}