/******************************************************************************
* Copyright 2017 The xies Authors. All Rights Reserved.
*
* 节点类，第一个节点会有一个该类的实例
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

	//添加边;
	void AddEdg(int endnode_sno, double weight);

	// get node_sno;
	int GetCNodeSno();

	// get x
	double GetX();

	// get y
	double GetY();

	// get Edg
	std::vector<Edg> GetEdgList();

	/*与消息的处理有关的方法*/

	// 接收一个消息;
	void RecMsg_(struct Msg_ msg);

	// 消息处理：决定是否丢弃该条消息
	void DealMsg_();

	// 生成新的msg;
	void MakeNewMsg_();

	// 发送消息到消息管理类
	void SendMsg_(struct Msg_ msg);

	// 输出可行解;
	void OutDo();

	// 清除消息缓存
	void ClearMsg_();

	// 设置targetno
	void SetTargetno(int no);

	// 外部触发函数
	void OutTrig(struct Msg_ msg);

	// 判定是否已经经过这个节点
	bool CheckHasPass();

	/* end*/
	~CNode();

private:     
	// 禁止默认构造方法
	CNode();  

	// 节点序号，表明是第几个节点，
	int node_sno;
	//节点的x,y 坐标
	double x;
	double y;

	//记录 node_sno 节点与 各 节点 之间的权值
	std::vector<Edg> edg_list;

	struct Msg_ *msg;

	// 历史搜索序号和消耗
	std::map<unsigned __int64, double> hasseqcost;

	//标志位，表明该点是否包含在目标路径中,如果在是在映射的第几个
	int istargetno;
};
#endif // !_NODE_H_
  