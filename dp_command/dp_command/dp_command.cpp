// dp_command.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>

using namespace std;

#define foreach BOOST_FOREACH
// ����ʦ��
class RoastCook
{
public:
	void	makeMutton()	
	{
		cout << "������" << endl;
	}


	void	makeChickWing()
	{
		cout << "�������" <<endl;
	}

};


// ����������
class Command
{
public:
	Command(RoastCook* tmp)
		: receiver(tmp)
	{
		
	}

virtual void execut() = 0;
protected:
	RoastCook* receiver;
};

// ����������

class MakeMuttonCmd : public Command

{

public:

	MakeMuttonCmd(RoastCook* tmp) : Command(tmp) {}

	virtual void execut() { receiver->makeMutton(); }

};

// �����������

class MakeChickenWingCmd : public Command

{

public:

	MakeChickenWingCmd(RoastCook* tmp) : Command(tmp) {}

	virtual void execut() { receiver->makeChickWing(); }

};


// ����Ա��

class Waiter

{

public:

	void appendCommand(Command* cmd)
	{
		commandList_.push_back(cmd);
	}

	// ִ֪ͨ��

	void invoke()
	{
		foreach(Command* cmd, commandList_)
		{
			cmd->execut();
		}
	}

protected:
	vector<Command*> commandList_;

};




int _tmain(int argc, _TCHAR* argv[])
{
	RoastCook* cook = new RoastCook();

	Command* cmd1 = new MakeMuttonCmd(cook);

	Command* cmd2 = new MakeChickenWingCmd(cook);

	Waiter* girl = new Waiter();

	// ���

	girl->appendCommand(cmd1);

	girl->appendCommand(cmd2);

	// ����Ա֪ͨ

	girl->invoke();

	return 0;
}

