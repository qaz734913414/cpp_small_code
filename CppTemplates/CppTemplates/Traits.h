#pragma once 
#include "stdafx.h"
template<typename T>
inline T accum(const T * begin, const T* end)
{
	T total  = T();
	while (begin != end){
		total += *begin;
		++begin;
	}

	return total;
}


void testTrait()
{
	int nums[] = {1, 2, 3, 4, 5};
	cout << accum(&nums[0], &nums[5]) << endl;

	char name[] = "template";
	int legth = sizeof(name)-1;//��char ����ʵ������ʱ����ܻ����charԽ������
	cout << accum(&name[0], &name[legth]) << endl;
}
////////////////////////////////////////////////

template<typename T>
class AccumTraits;

template<>
class AccumTraits<char>{
public:
	typedef int AccT;
};

template<>
class AccumTraits<int>{
public:
	typedef int AccT;
};


template <typename T>
typename AccumTraits<T>::AccT accum_1(const T * begin, const T* end)
{
	typedef typename AccumTraits<T>::AccT AccT;
	AccT total = AccT();
	while (begin != end){
		total += *begin;
		++begin;
	}

	return total;
}

void testTrait_1()
{
	int nums[] = {1, 2, 3, 4, 5};
	cout << accum_1(&nums[0], &nums[5]) << endl;

	char name[] = "template";
	int legth = sizeof(name)-1;//��char ����ʵ������ʱ����ܻ����charԽ������
	cout << accum_1(&name[0], &name[legth]) << endl;
}
/////////////////////////////////////////////////
struct CatTag //��ֻ�Ǹ����࣬Ŀ���Ǽ�����������
{
};

struct DogTag{

};

class Dog{
public:
	typedef DogTag type;

};

class Cat{
public:
	typedef CatTag type;
};

template<typename T>
void doAccept(T dog, DogTag)
{
	cout << "dog" <<endl;
}


template<typename T>
void doAccept(T cat, CatTag)
{
	cout << "cat" << endl;
}

template<class T>
void accept(T animal)
{
	// ���TΪ���࣬��typename T::type����dog_tag��
	//��ôtypename T::type()���Ǵ�����һ��dog_tag�����ʱ����
	//���ݺ������صĹ����⽫����Accept(T,dog_tag)��������ת�����Ĳ��ԡ�
	//���TΪè�࣬��typename T::typeΪcat_tag����������Ƶ���
	//�⽫����Accept(T,cat_tag)����ת����è�Ĳ��ԣ�
	//typename �ؼ��ָ��߱�����T::type�Ǹ����Ͷ����Ǿ�̬��Ա��
	doAccept(animal, typename T::type());
}


void testTrait_2()
{
	accept(Dog());
	accept(Cat());
}

template<typename T, typename AT = AccumTraits<T>>
class Accum{
public:
	static typename AT::AccT accum(T* begin, T* end)
	{
		typedef typename AT::AccT AccT;
		AccT total = AccT();
		while (begin != end){
			total += *begin;
			++begin;
		}

		return total;
	}
};	

void testTrait_3()
{
	int nums[] = {1, 2, 3, 4, 5};
	cout << Accum<int>::accum(&nums[0], &nums[5]) << endl;

	char name[] = "template";
	int legth = sizeof(name)-1;//��char ����ʵ������ʱ����ܻ����charԽ������
	cout <<  Accum<char>::accum(&name[0], &name[legth]) << endl;
}
