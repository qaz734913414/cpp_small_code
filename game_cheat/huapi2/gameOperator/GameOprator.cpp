#include "StdAfx.h"
#include "GameOprator.h"

BEGIN_MESSAGE_MAP(GameOprator, CWnd)
	ON_WM_TIMER()
END_MESSAGE_MAP()

GameOprator::GameOprator()
{
	TRACE("create");
	SetTimer(TT_MSGCHEACKER,1000,NULL);
	
}

GameOprator::~GameOprator()
{

}

void GameOprator::doMsgQueueOperator()
{
	try{

		interprocess::message_queue msgQueue(interprocess::open_only
			, INTERPRCESS_MESSAGE_QUEUE_NAME);

		unsigned int prioity, recvd_size;

		int recvd_number;
		msgQueue.receive(&recvd_number, sizeof(recvd_number), recvd_size, prioity);
		doOperator(static_cast<MSG_QUEUE_TYPE>(recvd_number));
	}
	catch(interprocess::interprocess_exception &ex)
	{
		interprocess::message_queue::remove("message_queue");
		//std::cout << ex.what() <<std::endl;
	}
}

void GameOprator::doOperator(MSG_QUEUE_TYPE type)
{
	switch(type)
	{
	case MQT_START:
		break;
	case MQT_PAUSE:
		break;
	default:
		break;
	}
}




void GameOprator::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ÔÚ´ËÌí¼ÓÏûÏ¢´¦Àí³ÌÐò´úÂëºÍ/»òµ÷ÓÃÄ¬ÈÏÖµ
	switch(nIDEvent)
	{
	case TT_MSGCHEACKER:
		TRACE("ontimer 1");
		break;
	default:
		break;
	}

	CWnd::OnTimer(nIDEvent);
}
