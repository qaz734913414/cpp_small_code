#pragma once
#include <iostream>
#include <algorithm>
#include <boost/spirit.hpp>
using namespace std;
using namespace boost::spirit;

#define rule1  !(ch_p('+')|ch_p('-'))>>+digit_p>>!(ch_p('.')>>+digit_p)
			  
void testFloat()
{
	parse_info<> r = parse("-111.2233", rule1);
	cout << "parsed " << (r.full?"successful":"failed") << endl;
}

void parserFloat()
{
	vector<double> reallist;
	//���ڽ������ַ���
	const char *szNumberList = "12.4,1000,-1928,33,30"; 
	//ʹ���Դ���push_back_a
	parse_info<> r = parse( szNumberList, real_p[push_back_a(reallist)] % ',' );
	cout << "parsed " << (r.full?"successful":"failed") << endl;
	cout << szNumberList << endl;
	//ʹ��parse_info::stopȷ����������λ�ñ��ڲ��
	cout << string(r.stop - szNumberList, ' ') << '^' << endl;
	//��ʾ���
	copy(reallist.begin(),reallist.end(),ostream_iterator<double>(cout,"\n"));
}