/******************************************************************************
* Copyright 2017 The xies Authors. All Rights Reserved.
*
* 节点类管理类，创建节点，存储节点
* 
*****************************************************************************/
#ifndef _NODE_MANAGER_H_
#define _NODE_MANAGER_H_

#include<vector>

#include"node_.h"
#include"map_.h"

class CNodeManager
{
public:
	
	CNodeManager():node_list_size(-1){}   
	// 创建节点类;
	void CreCNodeList(std::vector<Poin> vecpoin);
	
	// 创建节点的边;
	void CreCNodeEdg(std::vector<Line> vecline);

	//增加节点
	void AddCNode(CNode * ptrnode_);

	// 返回第 n 个 node_类
	CNode *GetCNode(int node_sno);

	// 返回node_list
	std::vector<CNode*> GetCNodeList();

	// 增加size
	void AddNodeListSize();

	// 获取size
	int GetNodeListSize();
                                  

	static CNodeManager* instance();
private:
	static CNodeManager* p;
	std::vector<CNode*> node_list;
	int node_list_size;
};
#endif //_NODE_MANAGER_H_
