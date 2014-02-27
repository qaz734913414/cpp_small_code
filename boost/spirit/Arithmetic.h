#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/spirit.hpp>
#include <boost/spirit/phoenix.hpp>
#include <vector>

using namespace std;
using namespace boost::spirit;
using namespace phoenix;
void calc();
void testPhoenix();

void arithmetic()
{
	rule<phrase_scanner_t> factor, term, exp;
	factor = real_p | ('(' >> exp >> ')');
	term   = factor >> *(('*' >> factor) | ('/' >> factor));
	exp    = term >> *(('+' >> term) | ('-' >> term));

	const char *szExp = "1 + (2 * (3 / (4 + 5)))";
	parse_info<> r = parse( szExp , exp, space_p);
	cout << "parsed " << (r.full?"successful":"failed") << endl;
	//testPhoenix();
	calc();
}

void testPhoenix()
{
	vector <int>vec(10);
	int i(0);
	for_each(vec.begin(), vec.end(), arg1 = var(i)++);
	for_each(vec.begin(), vec.end(), cout<<arg1<<endl);
}

void calc()
{
	//Ϊrule׼��һ��val����������Ϊdouble
	//׼ȷ��˵����һ��phoenix��(�����member1)����������phoenix�����lambda���ʽ����lambda�п��԰���������һ��double��      
	struct calc_closure : boost::spirit::closure<calc_closure, double>
	{
		member1 val;
	};
	//����ContextT����Ϊcalc_closure::context_t
	rule<phrase_scanner_t, calc_closure::context_t> factor, term, exp;
	//ֱ��ʹ��phoenix��lambda���ʽ��ΪActor
	factor = real_p[factor.val = arg1] | ('(' >> exp[factor.val = arg1] >> ')');
	term   = factor[term.val = arg1] >> *(('*' >> factor[term.val *= arg1]) | ('/' >> factor[term.val /= arg1]));
	exp    = term[exp.val = arg1] >> *(('+' >> term[exp.val += arg1]) | ('-' >> term[exp.val -= arg1]));
	const char *szExp = "1 + (2 * (3 / (4 + 5)))";
	double result;
	parse_info<> r = parse( szExp , exp[assign_a(result)], space_p);
	cout << szExp;
	if(r.full)
	{
		//�ɹ����õ����
		cout << " = " << result << endl;
	}
	else
	{
		//ʧ�ܣ���ʾ����λ��
		cout << endl << string(r.stop - szExp, ' ') << '^' << endl;
	}
}