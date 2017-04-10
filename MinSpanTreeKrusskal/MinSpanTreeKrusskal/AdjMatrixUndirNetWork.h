#ifndef ADJMATRIX_UNDIR_NETWORK_H
#define ADJMATRIX_UNDIR_NETWORK_H
#define DEFAULT_INFINITY 100
#define DEFAULT_SIZE 10
#include <iostream>
using namespace std;

enum VisitStatus{VISIT,UNVISIT};

class AdjMatrixUndirNetwork    //顶点为字符型
{
public:
	AdjMatrixUndirNetwork(int vertexMaxNum=DEFAULT_SIZE,int infinite=DEFAULT_INFINITY);
	AdjMatrixUndirNetwork(char *vexs,int vertexNum,int vertexMaxNum=DEFAULT_SIZE,int infinite=DEFAULT_INFINITY);
	~AdjMatrixUndirNetwork();
	void InsertArc(int vex1,int vex2,int weight);   //输入合法，vex1!=vex2，不考虑平行边
	void Display();
	int GetElem(int vex,char &data);   //返回状态
	int GetVexNum();
	int GetArcNum();
	int FirstAdjVex(int vex);   //返回顶点vex的第一个邻接顶点的序号，若没有则返回-1
	int NextAdjVex(int vex,int vex2);   //返回顶点vex的相对于vex2的下一个邻接顶点的序号，若没有则返回-1
	int GetWeight(int vex1,int vex2);

private:
	char *vertexes;
	VisitStatus *tag;
	int **arcs;
	int vexNum,vexMaxNum,arcNum;
	int infinity;
};

AdjMatrixUndirNetwork::AdjMatrixUndirNetwork(int vertexMaxNum,int infinite)
{
    vexMaxNum=vertexMaxNum;
	vexNum=0;
	arcNum=0;
	infinity=infinite;
	vertexes=new char[vexMaxNum];
	tag=new VisitStatus[vexMaxNum];
	arcs=new int *[vexMaxNum];
	for(int i=0;i<vexMaxNum;i++)
		arcs[i]=new int[vexMaxNum];
}

AdjMatrixUndirNetwork::AdjMatrixUndirNetwork(char *vexs,int vertexNum,int vertexMaxNum,int infinite)
{
	vexMaxNum=vertexMaxNum;
	vexNum=vertexNum;
	infinity=infinite;
	arcNum=0;
	vertexes=new char[vexMaxNum];
	tag=new VisitStatus[vexMaxNum];
	arcs=new int *[vexMaxNum];
	for(int i=0;i<vexMaxNum;i++)
		arcs[i]=new int[vexMaxNum];
	for(int i=0;i<vexMaxNum;i++)
	{
		vertexes[i]=vexs[i];
		tag[i]=UNVISIT;
		for(int j=0;j<vexMaxNum;j++)
			arcs[i][j]=infinity;
	}
}

AdjMatrixUndirNetwork::~AdjMatrixUndirNetwork()
{
	if(vertexes!=NULL)
		delete[] vertexes;
	if(tag!=NULL)
		delete[] tag;
	if(arcs!=NULL)
		delete arcs;
}

void AdjMatrixUndirNetwork::InsertArc(int vex1,int vex2,int weight)
{
	arcs[vex1][vex2]=weight;
	arcs[vex2][vex1]=weight;
	arcNum++;
}

void AdjMatrixUndirNetwork::Display()
{
	if(vexNum!=0)
	{
		for(int i=0;i<vexNum;i++)
		{
			cout<<"[ ";
			for(int j=0;j<vexNum;j++)
				cout<<arcs[i][j]<<" ";
			cout<<"]"<<endl;
		}
	}
}

int AdjMatrixUndirNetwork::GetElem(int vex,char &data)
{
	if(vex<0&&vex>=vexNum)
		return 0;
	data=vertexes[vex];
	return 1;
}

int AdjMatrixUndirNetwork::GetVexNum()
{
	return vexNum;
}

int AdjMatrixUndirNetwork::GetArcNum()
{
	return arcNum;
}

int AdjMatrixUndirNetwork::FirstAdjVex(int vex)
{
	for(int i=0;i<vexNum;i++)
		if(arcs[vex][i]!=infinity)
			return i;
	return -1;
}

int AdjMatrixUndirNetwork::NextAdjVex(int vex,int vex2)
{
	for(int i=vex2+1;i<vexNum;i++)
		if(arcs[vex][i]!=infinity)
			return i;
	return -1;
}

int AdjMatrixUndirNetwork::GetWeight(int vex1,int vex2)
{
	return arcs[vex1][vex2];
}
#endif
