#ifndef ADJLIST_UNDIR_GRAPH_H    //邻接表实现有向图
#define ADJLIST_UNDIR_GRAPH_H
#include "AdjListDirGraphArc.h"
#include "AdjListDirGraphVex.h"
#include <iostream>
using namespace std;
#define DEFAULT_SIZE 10

enum VisitStatus{VISIT,UNVISIT};

//有向图邻接表类定义
template<typename ElemType>
class AdjListDirGraph     
{
public:
	//函数成员:
    AdjListDirGraph(int _vexMaxNum=DEFAULT_SIZE);   //无参构造函数
	AdjListDirGraph(ElemType *Vexs,int _vexNum,int _vexMaxNum=DEFAULT_SIZE);   //有参构造函数
	~AdjListDirGraph();   //析构函数
	void Clear();   //清空所有弧
	bool isEmpty();   //判断有向图是否为空
	ElemType GetElem(int vex);    //获取顶点元素值
	int GetOrder(ElemType &e);    //获取顶点的序号
	void InsertArc(int vex1,int vex2);     //插入弧
	void InsertVex(ElemType &e);     //插入顶点
	void DeleteArc(int vex1,int vex2);     //删除弧
	void DeleteVex(ElemType &e);     //删除顶点
	int GetVexNum();     //获取有向图的顶点个数
	int GetArcNum();     //获取有向图的弧数个数
	int FirstAdjVex(int vex);     //获取有向图中顶点vex的第一个邻接点
	int NextAdjVex(int vex1,int vex2);     //获取有向图中顶点vex1的相对于vex2的下一个邻接点
	void Display();     //显示有向图

private:
	//数据成员:
	VisitStatus *tag;
	AdjListDirGraphVex<ElemType> *vexTable;
	int vexNum;
	int vexMaxNum;
	int arcNum;

};

template<typename ElemType>
AdjListDirGraph<ElemType>::AdjListDirGraph(int _vexMaxNum)
{
	vexMaxNum=_vexMaxNum;
	vexNum=0;
	arcNum=0;
	tag=new VisitStatus[vexMaxNum];
	vexTable=new AdjListDirGraphVex<ElemType>[vexMaxNum];
}

template<typename ElemType>
AdjListDirGraph<ElemType>::AdjListDirGraph(ElemType *Vexs,int _vexNum,int _vexMaxNum)
{
	vexMaxNum=_vexMaxNum;
	vexNum=_vexNum;
	arcNum=0;
	tag=new VisitStatus[vexMaxNum];
	vexTable=new AdjListDirGraphVex<ElemType>[vexMaxNum];
	for(int i=0;i<vexNum;i++)
	{
		tag[i]=UNVISIT;
		vexTable[i].data=Vexs[i];
	}
}

template<typename ElemType>
AdjListDirGraph<ElemType>::~AdjListDirGraph()
{
	if(tag!=NULL)
		delete[] tag;
	Clear();
	if(vexTable!=NULL)
		delete[] vexTable;
}

template<typename ElemType>
void AdjListDirGraph<ElemType>::Clear()
{
	AdjListDirGraphArc *p;
	for(int i=0;i<vexNum;i++)
		while(vexTable[i].firstArc!=NULL)
		{
			p=vexTable[i].firstArc;
			vexTable[i].firstArc=p->nextArc;
			delete p;
		}
	arcNum=0;
}

template<typename ElemType>
bool AdjListDirGraph<ElemType>::isEmpty()
{
	return vexNum==0;
}

template<typename ElemType>
ElemType AdjListDirGraph<ElemType>::GetElem(int vex)
{
	return vexTable[vex].data;
}

template<typename ElemType>
int AdjListDirGraph<ElemType>::GetOrder(ElemType &e)
{
	for(int i=0;i<vexNum;i++)
		if(vexTable[i].data==e)
			return i;
	return -1;
}

template<typename ElemType>
void AdjListDirGraph<ElemType>::InsertArc(int vex1,int vex2)
{
	if(vex1<0 || vex1>=vexNum)
		cout<<"vex1不合法!";	 
	else if(vex2<0 || vex2>=vexNum)
		cout<<"vex2不合法!";	 
	else if(vex1==vex2)
		cout<<"vex1不能等于vex2!";  
	else
	{
	    vexTable[vex1].firstArc=new AdjListDirGraphArc(vex2,vexTable[vex1].firstArc);
		arcNum++;
	}

}
template<typename ElemType>
void AdjListDirGraph<ElemType>::InsertVex(ElemType &e)
{
	if(vexNum==vexMaxNum)
		cout<<"图的顶点数不能超过允许的最大数!"<<endl;
	vexTable[vexNum].data=e;
	vexTable[vexNum].firstArc=NULL;
	tag[vexNum]=UNVISIT;
	vexNum++;
}

template<typename ElemType>
void AdjListDirGraph<ElemType>::DeleteArc(int vex1,int vex2)
{
	if(vex1<0 || vex1>=vexNum)
		cout<<"vex1不合法!";	 
	if(vex2<0 || vex2>=vexNum)
		cout<<"vex2不合法!";	
    AdjListDirGraphArc *p=vexTable[vex1].firstArc,*q;
	while(p!=NULL && p->adjVex!=vex2)
	{
		q=p;
		p=p->nextArc;
	}
	if(p!=NULL)
	{
		if(vexTable[vex1].firstArc==p)
			vexTable[vex1].firstArc=p->nextArc;
		else
			q->nextArc=p->nextArc;
		delete p;
		arcNum--;
	}
}

template<typename ElemType>
void AdjListDirGraph<ElemType>::DeleteVex(ElemType &e)
{
	int v=GetOrder(e),u;
	if(v==-1)
		cout<<"图中不存在要删除的顶点!"<<endl;
	else
	{
		for(u=0;u<vexNum;u++)
			if(u!=v)
				DeleteArc(u,v);
		 AdjListDirGraphArc *p=vexTable[v].firstArc;
		 while(p!=NULL)
		 {
			 vexTable[v].firstArc=p->nextArc;
			 delete p;
			 p=vexTable[v].firstArc;
			 arcNum--;
		 }
		 if(v==vexNum-1)
			 vexNum--;
		 else
		 {
			 vexNum--;
			 vexTable[v]=vexTable[vexNum];
			 vexTable[vexNum].firstArc=NULL;
			 tag[v]=tag[vexNum];
			 for(u=0;u<vexNum;u++)
				 if(u!=v)
				 {
					 p=vexTable[u].firstArc;
					 while(p!=NULL)
					 {
						 if(p->adjVex==vexNum)
							 p->adjVex=v;
						 p=p->nextArc;
					 }
				 }
		 }
		
	}
}

template<typename ElemType>
int AdjListDirGraph<ElemType>::GetVexNum()
{
	return vexNum;
}

template<typename ElemType>
int AdjListDirGraph<ElemType>::GetArcNum()
{
	return arcNum;
}

template<typename ElemType>
int AdjListDirGraph<ElemType>::FirstAdjVex(int vex)
{
	if(vex<0 || vex>=vexNum)
		cout<<"vex不合法!";	 
	if(vexTable[vex].firstArc==NULL)
		return -1;
	else
		return vexTable[vex].firstArc->adjVex;
}

template<typename ElemType>
int AdjListDirGraph<ElemType>::NextAdjVex(int vex1,int vex2)
{
	if(vex1<0 || vex1>=vexNum)
		cout<<"vex1不合法!";	 
	if(vex2<0 || vex2>=vexNum)
		cout<<"vex2不合法!";	 
	AdjListDirGraphArc *p=vexTable[vex1].firstArc;
	while(p!=NULL && p->adjVex!=vex2)
		p=p->nextArc;
	if(p==NULL||p->nextArc==NULL)
		return -1;
	else
		return p->nextArc->adjVex;
}

template<typename ElemType>
void AdjListDirGraph<ElemType>::Display()
{
	cout<<"该有向图共"<<vexNum<<"个顶点,"<<arcNum<<"条弧"<<endl;
	for(int i=0;i<vexNum;i++)
	{
		cout<<vexTable[i].data<<"的邻接顶点为: ";
		AdjListDirGraphArc *p=vexTable[i].firstArc;
		if(p==NULL)
			cout<<"无"<<endl;
		else
		{
			while(p!=NULL)
			{
				cout<<GetElem(p->adjVex)<<" ";
				p=p->nextArc;
			}
			cout<<endl;
		}

	}
}

#endif