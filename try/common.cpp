#include<iostream>

#include"common.h"

void OutPutSolve(double cost, std::vector<int> poinlist)
{
	static double mincost = DBL_MAX;
	if (mincost > cost)
	{
		mincost = cost;
		for (auto it : poinlist)
		{
			std::cout << it << " -> ";
		}
		std::cout << "end" << "totalcost = " <<  mincost << std::endl;

	}
}