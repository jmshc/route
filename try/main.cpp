#include<iostream>
#include"map_.h"
#include"node_manager.h"
#include"msg_manager.h"

#define DEBUG 1
void TestCMap()
{

}

void main()
{

	CMap clmap_;
	CNodeManager *clnode_manager = CNodeManager::instance();
	MsgManager *clmsgmanager = MsgManager::instance();
	std::vector<int> haspoinlist;
	haspoinlist.push_back(1);
	haspoinlist.clear();
	std::vector<unsigned int> reqpoinsno;
	reqpoinsno.push_back(1);
	reqpoinsno.push_back(2);
	reqpoinsno.push_back(12);
	reqpoinsno.push_back(6);
	reqpoinsno.push_back(10);
	reqpoinsno.push_back(7);
	reqpoinsno.push_back(4);
	//reqpoinsno.clear();
	unsigned __int64 hasmap_ = 0;

	//创建第一条消息
	Msg_ msg(100, 0.0, haspoinlist, reqpoinsno, (int)reqpoinsno.size(), 0, hasmap_, *reqpoinsno.begin());
	//TestCMap();
	//从文件中读取图的信息到 map_中
	clmap_.InitCMap();

	//创建 CNode类和创建各个节点的边;
	clnode_manager->CreCNodeList(clmap_.GetPoinList());
	clnode_manager->CreCNodeEdg(clmap_.GetLineList());

	//TestCreCNode();
	if (DEBUG)
	{
		std::vector<CNode *> vecnode_ = clnode_manager->GetCNodeList();
		for (int index = 0; index  < (int)vecnode_.size(); index ++)
		{
			CNode * node_ = vecnode_[index];
			std::vector<Edg> vecEdg = vecnode_[index]->GetEdgList();

			std::cout << "node_sno = " << node_->GetCNodeSno() << " node_x = " << node_->GetX() << " node_y = " << node_->GetY() << std::endl;

			for (int index = 0; index < (int)vecEdg.size(); index++)
			{
				Edg Edg = vecEdg[index];
				std::cout << "snode_sno = " << node_->GetCNodeSno()<< " enode_sno = " << Edg.enode_sno << " weight = " << Edg.weight << std::endl;
			}

			std::cout << std::endl;
		}//end for
		//std::cout << "size = " << clnode_manager->GetNodeListSize() << std::endl;
	}//end if 

	int index = 1;
	for (auto it : reqpoinsno)
	{
		clnode_manager->GetCNode(it)->SetTargetno(index++);
	}
	/*clnode_manager->GetCNode(1)->SetTargetno(1);
	clnode_manager->GetCNode(2)->SetTargetno(2);
	clnode_manager->GetCNode(12)->SetTargetno(3);*/
	// 添加一条消息
	clmsgmanager->AddMsg_(msg);
	clmsgmanager->DoSolve();


	system("pause");
}