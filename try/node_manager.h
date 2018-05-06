/******************************************************************************
* Copyright 2017 The xies Authors. All Rights Reserved.
*
* �ڵ�������࣬�����ڵ㣬�洢�ڵ�
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
	// �����ڵ���;
	void CreCNodeList(std::vector<Poin> vecpoin);
	
	// �����ڵ�ı�;
	void CreCNodeEdg(std::vector<Line> vecline);

	//���ӽڵ�
	void AddCNode(CNode * ptrnode_);

	// ���ص� n �� node_��
	CNode *GetCNode(int node_sno);

	// ����node_list
	std::vector<CNode*> GetCNodeList();

	// ����size
	void AddNodeListSize();

	// ��ȡsize
	int GetNodeListSize();
                                  

	static CNodeManager* instance();
private:
	static CNodeManager* p;
	std::vector<CNode*> node_list;
	int node_list_size;
};
#endif //_NODE_MANAGER_H_
