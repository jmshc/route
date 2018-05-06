/******************************************************************************
 * Copyright 2017 The xies Authors. All Rights Reserved.
 *
 * 消息类管理类
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

	// 创建消息
	void AddMsg_(Msg_ msg);

	// 返回并删除一个msg
	Msg_ GetTopMsg_();

	//msg 求解开始
	void DoSolve();

	//
	static MsgManager* instance();
private:
	static MsgManager* p;
	std::vector<Msg_> msglist;

};

#endif //!_MSG_MANAGER_H_

