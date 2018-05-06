/******************************************************************************
 * Copyright 2017 The xies Authors. All Rights Reserved.
 *
 * map_����ļ��ж�ȡ��ͼ��Ϣ������������꣬�����Ȩ��
 * map_ ��Ϊ����ģʽ
 *****************************************************************************/
#ifndef _MAP_H_
#define _MAP_H_


#define POIN_FILENAME "poininfo.txt"
#define LINE_FILENAME "lineinfo.txt"

#include<vector>
#include<iostream>
#include<fstream>

#include"macro.h"

struct Poin
{
	Poin(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	double x;
	double y;
};

struct Line
{
	Line(int s, int e, double w)
	{
		startpoinsno = s;
		endpoinsno = e;
		weight = w;
	}
	int startpoinsno;
	int endpoinsno;
	double weight;
};

class CMap
{
public:

	//map_ ��ʼ�������ļ��ж�ȡmap_��Ϣ
    void InitCMap();

	// load poininfo
    void LoadPoinInfo(const std::string& filename);

	// load lineinfo
	void LoadLineInfo(const std::string& filename);

	//add poin
	void AddPoin(double x, double y);

	//add line
    void AddLine(int startpoinsno, int endpoinsno, double weight);

	// ���ش洢poin��vector
	std::vector<Poin> GetPoinList();

	// ���ش洢Line��vector
	std::vector<Line> GetLineList();

	//DECLARE_SINGLETON(CMap);
private:
	std::vector<Poin> poin_list;
	std::vector<Line> line_list;

};


#endif // !_MAP_H_
