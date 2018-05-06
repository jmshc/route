#include"node_manager.h"

CNodeManager* CNodeManager::p = NULL;
CNodeManager* CNodeManager::instance()
{
    if (p == NULL)
        p = new CNodeManager();
    return p;
}

//增加节点
void CNodeManager::AddCNode(CNode * ptrnode_)
{
	node_list.push_back(ptrnode_);
	node_list_size++;
}

// 返回第 n 个 node_类指针
CNode * CNodeManager::GetCNode(int node_sno)
{
	if (node_sno > node_list_size)
	{
		return nullptr; 
	}
	
	return node_list[node_sno];
}
  
// 返回node_list指针
std::vector<CNode*> CNodeManager::GetCNodeList()
{
	return node_list;
}

void CNodeManager::CreCNodeList(std::vector<Poin> vecpoin)
{
	//霸占第一个位置;保留
    AddCNode(new CNode(0, 0.0, 0.0));

	for (int index = 0; index  < (int)(vecpoin).size(); index++)
	{
		AddCNode(new CNode(index + 1, vecpoin[index].x, vecpoin[index].y));
	}

	return;
}


// 创建节点的边;
void CNodeManager::CreCNodeEdg(std::vector<Line> vecline)
{
	for (int index = 0; index < (int)vecline.size(); index++)
	{
		int spoinsno = vecline[index].startpoinsno;
		int epoinsno = vecline[index].endpoinsno;
		double weight = vecline[index].weight;

		node_list[spoinsno]->AddEdg(epoinsno, weight);

		node_list[epoinsno]->AddEdg(spoinsno, weight);
	}
}

	// 增加size
void CNodeManager::AddNodeListSize()
{
	node_list_size++;
}

	// 获取size
int CNodeManager::GetNodeListSize()
{
	return node_list_size; 
}