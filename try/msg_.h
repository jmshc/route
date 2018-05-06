/******************************************************************************
 * Copyright 2017 The xies Authors. All Rights Reserved.
 *
 * ��Ϣ�࣬���ڵ��·���Ĵ�������
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


		// ��ʶÿ����������
	unsigned __int64 sno; 

	// �˽�����������ĵ�·��
	double hascost;

	// ���߹��ĵ�
	std::vector<int> haspoinlist;

	//����е���������ĵ�����
	std::vector<unsigned int> reqpoinsno;

	// ��������Ҫ�����ĵ�����
	int totalnum;

	// �Ѿ������ĵ����Ŀ
	int haspoinnum;

	//reqpoinsno�еĵ��ӳ��,��һ��poin��Ӧÿһλ.
	unsigned __int64 reqpoinsnomap_;

	// ��һ���ڵ��ָ��
	int nextnode_;
};

#endif //!_MSG_H_