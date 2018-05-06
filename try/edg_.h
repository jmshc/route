/******************************************************************************
* Copyright 2017 The xies Authors. All Rights Reserved.
*
* 半边结构体，包括终点和起点到终点的权值
* 
*****************************************************************************/
#ifndef _EDG_H_
#define _EDG_H_

struct Edg
{
	Edg(int endnode_sno, double weight)
	{
		this->enode_sno = endnode_sno;
		this->weight = weight;
	}
	int enode_sno;
	double weight;
};

#endif // !_EDG_H_