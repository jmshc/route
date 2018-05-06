/******************************************************************************
 * Copyright 2017 The xies Authors. All Rights Reserved.
 *
 * 消息类，各节点间路径的传播载体
 * 
 *****************************************************************************/
#ifndef _MSG_H_
#define _MSG_H_

#include<vector>

#include"node_.h"

struct Msg_
{
	Msg_(){} 

    Msg_& operator=(Msg_& msg)
    {
        sno = msg.sno;
        hascost = msg.hascost;
		haspoinlist.assign(msg.haspoinlist.begin(), msg.haspoinlist.end());
		reqpoinsno.assign(msg.reqpoinsno.begin(), msg.reqpoinsno.end());
		totalnum = msg.totalnum;
		haspoinnum = msg.haspoinnum;
		reqpoinsnomap_ = msg.reqpoinsnomap_;
		nextnode_ = msg.nextnode_;
        return *this;
    }

	Msg_(unsigned __int64 psno, double phascost, std::vector<int> phaspoinlist, std::vector<unsigned int> preqpoinsno, int ptotalnum, int phaspoinnum, unsigned __int64 preqpoinsnomap_, int pnextnode_)
		:sno(psno),hascost(phascost),haspoinlist(phaspoinlist),reqpoinsno(preqpoinsno),totalnum(ptotalnum),haspoinnum(phaspoinnum),reqpoinsnomap_(preqpoinsnomap_), nextnode_(pnextnode_){}


		// 标识每个问题的序号
	unsigned __int64 sno; 

	// 此解决方案已消耗的路径
	double hascost;

	// 已走过的点
	std::vector<int> haspoinlist;

	//求解中的问题包含的点的序号
	std::vector<unsigned int> reqpoinsno;

	// 此问题中要经过的点总数
	int totalnum;

	// 已经经过的点的数目
	int haspoinnum;

	//reqpoinsno中的点的映射,第一个poin对应每一位.
	unsigned __int64 reqpoinsnomap_;

	// 下一个节点的指针
	int nextnode_;
};

#endif //!_MSG_H_