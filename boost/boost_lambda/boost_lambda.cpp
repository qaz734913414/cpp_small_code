// boost_lambda.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <algorithm>
#include <vector>

using namespace std;
using namespace boost::lambda;

//һ�������
void print(int i)   
{   
	std::cout << i << std::endl;   
} 
void testFunction_0()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	for_each(a.begin(), a.end(), print);
}

//���Ӷ�ʡȥ����һ����������Ҫ������һ���ô��Ǵ����Ϊ����
//��ʹ���㷨�븺����������ĺ������Ǿֲ��Է���ġ�Boost.Lambda����ʹ֮��Ϊ��ʵ

void testFunction_2()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	for_each(a.begin(), a.end(), std::cout<< boost::lambda::_1 <<  "\n");
}


int _tmain(int argc, _TCHAR* argv[])
{
	testFunction_0();
	testFunction_2();
	return 0;
}

