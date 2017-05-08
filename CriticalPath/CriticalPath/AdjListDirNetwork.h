#ifndef ADJLIST_DIR_NETWORK_H    //邻接表实现有向网络
#define ADJLIST_DIR_NETWORK_H
#include <iostream>
using namespace std;
#define DEFAULT_SIZE 10
#define INFINITY 1000

struct AdjListArcNode    //边结点定义
{
	int adjVex;
	int weight;
	AdjListArcNode *nextArc;

	AdjListArcNode():nextArc(NULL) {}

	AdjListArcNode(int _adjVex,int _weight,AdjListArcNode *_nextArc=NULL)
	{
		adjVex=_adjVex;
		weight=_weight;
		nextArc=_nextArc;
	}
};

struct AdjListVexNode   //顶点结点定义
{
	char data;
	AdjListArcNode *firstArc;

	AdjListVexNode():firstArc(NULL) {}
	
	AdjListVexNode(char VexValue,AdjListArcNode *_firstArc=NULL)
	{
		data=VexValue;
		firstArc=_firstArc;
	}
};



enum VisitStatus{VISIT,UNVISIT};

class AdjListDirNetwork     //邻接表实现有向图定义
{
public:
    AdjListDirNetwork(int _vexMaxNum=DEFAULT_SIZE);
	AdjListDirNetwork(char *Vexs,int _vexNum,int _vexMaxNum=DEFAULT_SIZE);
	~AdjListDirNetwork();
	void Clear();
	void InsertArc(int vex1,int vex2,int _weight);   //输入需合法，不考虑平行边，且vex1不等于vex2
	void Show();
	int GetVexNum();
	void GetVexsIndgree(int *indegree);
	char GetElem(int vex);
	int GetFirstAdjVex(int vex);
	int GetNextAdjVex(int vex1,int vex2);
	int GetWeight(int vex1,int vex2);

private:
	VisitStatus *tag;
	AdjListVexNode *vexTable;
	int vexNum;
	int vexMaxNum;
	int arcNum;
	int *Indegree;
	int infinite;
};

AdjListDirNetwork::AdjListDirNetwork(int _vexMaxNum)
{
	vexMaxNum=_vexMaxNum;
	vexNum=0;
	arcNum=0;
	tag=new VisitStatus[vexMaxNum];
	vexTable=new AdjListVexNode[vexMaxNum];
	Indegree=new int[vexMaxNum];
	infinite=INFINITY;
}

AdjListDirNetwork::AdjListDirNetwork(char *Vexs,int _vexNum,int _vexMaxNum)
{
	vexMaxNum=_vexMaxNum;
	vexNum=_vexNum;
	arcNum=0;
	tag=new VisitStatus[vexMaxNum];
	vexTable=new AdjListVexNode[vexMaxNum];
	Indegree=new int[vexMaxNum];
	for(int i=0;i<vexNum;i++)
	{
		tag[i]=UNVISIT;
		vexTable[i].data=Vexs[i];
		Indegree[i]=0;
	}
	infinite=INFINITY;
}

AdjListDirNetwork::~AdjListDirNetwork()
{
	if(tag!=NULL)
		delete[] tag;
	Clear();
	if(vexTable!=NULL)
		delete[] vexTable;
	if(Indegree!=NULL)
		delete[] Indegree;
}

void AdjListDirNetwork::Clear()
{
	for(int i=0;i<vexNum;i++)
	{
		while(vexTable[i].firstArc!=NULL)
		{
			AdjListArcNode *p=vexTable[i].firstArc;
			vexTable[i].firstArc=p->nextArc;
			delete p;
			arcNum--;
		}
	}
}

void AdjListDirNetwork::InsertArc(int vex1,int vex2,int _weight)
{
	vexTable[vex1].firstArc=new AdjListArcNode(vex2,_weight,vexTable[vex1].firstArc);
	arcNum++;
	Indegree[vex2]++;
}

void AdjListDirNetwork::Show()
{
	for(int i=0;i<vexNum;i++)
	{
		cout<<vexTable[i].data<<": ";
		AdjListArcNode *p=vexTable[i].firstArc;
		while(p!=NULL)
		{
			cout<<"("<<p->adjVex<<","<<p->weight<<")"<<" ";
			p=p->nextArc;
		}
		cout<<endl;
	}
	for(int i=0;i<vexNum;i++)
		cout<<Indegree[i]<<" ";
	cout<<endl;
}

int AdjListDirNetwork::GetVexNum()
{
	return vexNum;
}

void AdjListDirNetwork::GetVexsIndgree(int *indegree)
{
	for(int i=0;i<vexNum;i++)
		indegree[i]=Indegree[i];
}

char AdjListDirNetwork::GetElem(int vex)
{
	return vexTable[vex].data;
}

int AdjListDirNetwork::GetFirstAdjVex(int vex)
{
	if(vexTable[vex].firstArc==NULL)
		return -1;
	return vexTable[vex].firstArc->adjVex;
}

int AdjListDirNetwork::GetNextAdjVex(int vex1,int vex2)
{
	AdjListArcNode *p=vexTable[vex1].firstArc;
	while(p!=NULL&&p->adjVex!=vex2)
		p=p->nextArc;
	if(p==NULL||p->nextArc==NULL)
		return -1;
	else
	    return p->nextArc->adjVex;
}

int AdjListDirNetwork::GetWeight(int vex1,int vex2)
{
	AdjListArcNode *p=vexTable[vex1].firstArc;
	while(p!=NULL&&p->adjVex!=vex2)
		p=p->nextArc;
	if(p!=NULL)
		return p->weight;
	else
		return infinite;
}
#endif