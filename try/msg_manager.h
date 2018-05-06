/******************************************************************************
 * Copyright 2017 The xies Authors. All Rights Reserved.
 *
 * ��Ϣ�������
 * 
 *****************************************************************************/
#ifndef _MSG_MANAGER_H_
#define _MSG_MANAGER_H_

#include<vector>
#include"msg_.h"
#include"node_manager.h"

class MsgManager

{
public:
	MsgManager();
	
	~MsgManager();

	// ������Ϣ
	void AddMsg_(Msg_ msg);

	// ���ز�ɾ��һ��msg
	Msg_ GetTopMsg_();

	//msg ��⿪ʼ
	void DoSolve();

	//
	static MsgManager* instance();
private:
	static MsgManager* p;
	std::vector<Msg_> msglist;

};

#endif //!_MSG_MANAGER_H_

