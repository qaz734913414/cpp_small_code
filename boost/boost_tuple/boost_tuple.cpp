// boost_tuple.cpp : �������̨Ӧ�ó������ڵ㡣
//

/** 
* @file         boost_tuple.cpp 
* @Synopsis     tuple�����׺�pair ���ƣ� ������֧��2�����ϵ����� 
* @author       diwu.sld 
* @version     	1.0
* @date         2012-7-23
*/

#include "stdafx.h"
#include <boost/tuple/tuple.hpp>
#include <iostream>
#include <boost/tuple/tuple_io.hpp>

using namespace boost;
using namespace  std;


//��ʹ��Ԫ��ʱ������μ�������ʵ��
//1.�ܹ��γ�Ԫ���Ԫ������Ŀǰ������ 10 ����
//2. Ԫ����԰����û�����������ͣ����������븺��ȷ����Щ���Ѿ���������ȷ�Ĺ��캯���Ϳ������캯�� (copy constructor)

void funTest_0()
{
	tuple<int, char, float> t(2, 'a', 0.9);
	cout<< t << endl;
}

//�� STL �ṩ�� make_pair �����ǳ����ƣ�Boost �ṩ�� make_tuple ���̡�
//Ҫ�Ӻ�������Ԫ�飬��������� make_tuple�����Դ���������ʱԪ�ص�Ԫ�飻

void funTest_1()
{
	tuple<int ,int> t = make_tuple<int, int>(10, 20);
	cout << t.get<0>() <<endl;

	get<0>(t) = 11;
	++get<0>(t);
	cout <<t.get<0>()<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	funTest_0();
	funTest_1();
	return 0;
}

