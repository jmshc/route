#include"msg_manager.h"

MsgManager::MsgManager()
{
}

MsgManager::~MsgManager()
{
}

void MsgManager::AddMsg_(Msg_ msg)
{
	msglist.push_back(msg);
}

Msg_ MsgManager::GetTopMsg_()
{
	Msg_ msg = msglist.back();
	msglist.pop_back();
	return msg;
}


void MsgManager::DoSolve()
{
	CNodeManager *clnode_manager = CNodeManager::instance();

	while(true)
	{
		if (msglist.size() >= 1)
		{
			Msg_ msg = GetTopMsg_();
			CNode *node_ = clnode_manager->GetCNode(msg.nextnode_);
			node_->OutTrig(msg);
		}else
		{
			break;
		}
	}
}

MsgManager* MsgManager::p = NULL;
MsgManager* MsgManager::instance()
{
    if (p == NULL)
        p = new MsgManager();
    return p;
}