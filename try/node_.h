/******************************************************************************
* Copyright 2017 The xies Authors. All Rights Reserved.
*
* �ڵ��࣬��һ���ڵ����һ�������ʵ��
* 
*****************************************************************************/
#ifndef _NODE_H_
#define _NODE_H_

#include<vector>
#include<map>

#include"edg_.h"
#include"msg_.h"

class CNode
{
public:
	CNode(int node_sno, double x, double y);

	//��ӱ�;
	void AddEdg(int endnode_sno, double weight);

	// get node_sno;
	int GetCNodeSno();

	// get x
	double GetX();

	// get y
	double GetY();

	// get Edg
	std::vector<Edg> GetEdgList();

	/*����Ϣ�Ĵ����йصķ���*/

	// ����һ����Ϣ;
	void RecMsg_(struct Msg_ msg);

	// ��Ϣ���������Ƿ���������Ϣ
	void DealMsg_();

	// �����µ�msg;
	void MakeNewMsg_();

	// ������Ϣ����Ϣ������
	void SendMsg_(struct Msg_ msg);

	// ������н�;
	void OutDo();

	// �����Ϣ����
	void ClearMsg_();

	// ����targetno
	void SetTargetno(int no);

	// �ⲿ��������
	void OutTrig(struct Msg_ msg);

	// �ж��Ƿ��Ѿ���������ڵ�
	bool CheckHasPass();

	/* end*/
	~CNode();

private:     
	// ��ֹĬ�Ϲ��췽��
	CNode();  

	// �ڵ���ţ������ǵڼ����ڵ㣬
	int node_sno;
	//�ڵ��x,y ����
	double x;
	double y;

	//��¼ node_sno �ڵ��� �� �ڵ� ֮���Ȩֵ
	std::vector<Edg> edg_list;

	struct Msg_ *msg;

	// ��ʷ������ź�����
	std::map<unsigned __int64, double> hasseqcost;

	//��־λ�������õ��Ƿ������Ŀ��·����,���������ӳ��ĵڼ���
	int istargetno;
};
#endif // !_NODE_H_
  