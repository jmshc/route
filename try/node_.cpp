#include<iostream>

#include"common.h"
#include"node_.h"
#include"msg_manager.h"

CNode::CNode(int pnode_sno, double px, double py)
	:node_sno(pnode_sno),
	x(px),
	y(py),
	msg(NULL),
	istargetno(0)
{
	// 初始化 第 node_sno 个节点， x = x , y = y
}

void CNode::AddEdg(int endnode_sno, double weight)
{
	if (endnode_sno < 0 || weight < 0.0)
	{
		return;
	}

	edg_list.push_back(Edg(endnode_sno, weight));
}



CNode::~CNode()
{
}


// get node_sno;
int CNode::GetCNodeSno()
{
	return node_sno;
}


// get x
double CNode::GetX()
{
	return x;
}

// get y
double CNode::GetY()
{
	return y;
}

std::vector<Edg> CNode::GetEdgList()
{
	return edg_list;
}

void CNode::RecMsg_(Msg_ pmsg)
{
	msg = new Msg_(pmsg);

}

void CNode::DealMsg_()
{
	if(1)
	{
		std::map<unsigned __int64, double>::iterator it;

		it = hasseqcost.find(msg->reqpoinsnomap_);

		if (istargetno)
		{
			//int a = 56; //8 * (8 - msg->haspoinnum);

			if(CheckHasPass())
			{
				return;
			}
			unsigned __int64 temp = istargetno;
			msg->haspoinnum += 1;
			msg->reqpoinsnomap_ |= temp<< (8 * (8 - msg->haspoinnum - 1));
			
		}

		if ((it != hasseqcost.end()) 
			&& (it->second <= msg->hascost))
		{
			return;
		}else
		{
			// it == end || second > hascost
			hasseqcost[msg->reqpoinsnomap_] = msg->hascost;
		}
	}
	//if(istargetno)
	//{
	//	msg->haspoinnum += 1;
	//}
    //	生成新的msg;
	MakeNewMsg_();

}

bool CNode::CheckHasPass()
{
	int hasnum = msg->haspoinnum;

	__int64 target = istargetno;

	target <<= (8 * 7);
	__int64 haspoinmap = msg->reqpoinsnomap_;

	while (hasnum > 0)
	{
		if (!(haspoinmap ^ (haspoinmap | target)))
		{
			return true;
		}

		target >>= 8;
		hasnum--;
	}
	return false;
}

void CNode::MakeNewMsg_()
{
	//unsigned __int64 temppoinmap_ = msg->reqpoinsnomap_;


	//把当前点加入已走过的点vector中
	msg->haspoinlist.push_back(node_sno);


	if (msg->haspoinnum == msg->totalnum)
	{
		// 可行解;
		//OutDo();
		OutPutSolve(msg->hascost, msg->haspoinlist);
		return;
	}

	std::vector<int>::iterator haspoinit;
	std::vector<int> haspoinlist = msg->haspoinlist;
	for (auto it : edg_list)
	{
		haspoinit = std::find(haspoinlist.begin(), haspoinlist.end(), it.enode_sno);
		if(haspoinit == haspoinlist.end())
		{
			it.enode_sno;
			msg->hascost += it.weight;
			msg->nextnode_ = it.enode_sno;
			SendMsg_(*msg);
			msg->hascost -= it.weight;
		}
	}
}

void CNode::OutDo()
{
	for (auto it : msg->haspoinlist)
	{
		std::cout << it << " -> ";
	}
	std::cout << "end" << "totalcost = " << msg->hascost << std::endl;

}

void CNode::SendMsg_(Msg_ msg)
{
	MsgManager *msgmanager = MsgManager::instance();

	msgmanager->AddMsg_(msg);

}

void CNode::ClearMsg_()
{
	msg = NULL;
}

void CNode::OutTrig(Msg_ msg)
{
	// 接收一个消息
	RecMsg_(msg);

	//处理消息
	DealMsg_();


	//消除消息缓存
	ClearMsg_();
}

void CNode::SetTargetno(int no)
{
	istargetno = no;
}