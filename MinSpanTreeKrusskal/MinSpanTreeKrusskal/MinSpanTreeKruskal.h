#ifndef MINSPANTREE_KRUSKAL_H    //最小生成树，Kruskal算法
#define MINSPANTREE_KRUSKAL_H
#include "AdjMatrixUndirNetWork.h"
#include "UFSets.h"
#include "MinHeap.h"
#include <iostream>
using namespace std;

struct KruskalEdge
{
    int weight;
	char vex1,vex2;

	KruskalEdge(){}
	KruskalEdge(int w,char v1,char v2):weight(w),vex1(v1),vex2(v2)
	{}
	bool operator>=(KruskalEdge &other)
	{
		return weight>=other.weight;
	}
	bool operator<(KruskalEdge &other)
	{
		return weight<other.weight;
	}
	bool operator<=(KruskalEdge &other)
	{
		return weight<=other.weight;
	}
	friend ostream & operator<<(ostream &out,const KruskalEdge &e)
	{
		out<<e.weight;
		return out;
	}
};

void MinSpanTreeKruskal(AdjMatrixUndirNetwork &network)
{
	int arcNum=network.GetArcNum();
	int vexNum=network.GetVexNum();
	char *vexs,vex1,vex2;
	vexs=new char[vexNum];
	for(int i=0;i<vexNum;i++)
		network.GetElem(i,vexs[i]);
	UFSets<char> uf(vexs,vexNum);    //取network的点集初始化并查集
	MinHeap<KruskalEdge> edges(arcNum);
	for(int i=0;i<vexNum;i++)
		for(int j=network.FirstAdjVex(i);j!=-1;j=network.NextAdjVex(i,j))
			if(i<j)
			{
				network.GetElem(i,vex1);
				network.GetElem(j,vex2);
				KruskalEdge edge(network.GetWeight(i,j),vex1,vex2);
				edges.Insert(edge);     //取network的所有边插入最小堆
			}
    int count=0;
	while(count<vexNum-1)
	{
		KruskalEdge e;
		if(edges.DeleteTop(e))
		{
            if(uf.isDifferent(e.vex1,e.vex2))
		    {
			    cout<<"连接边：("<<e.vex1<<","<<e.vex2<<")，权："<<e.weight<<endl;
			    count++;
			    uf.Union(e.vex1,e.vex2);
		    }
		}
		else
			cout<<"该图不连通，无最小生成树!";
	}
	if(count==vexNum-1)
		cout<<"最小生成树生成成功!"<<endl;
	delete[] vexs;
}
#endif