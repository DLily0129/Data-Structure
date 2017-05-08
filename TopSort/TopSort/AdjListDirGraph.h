#ifndef ADJLIST_DIR_GRAPH_H    //邻接表实现有向图
#define ADJLIST_DIR_GRAPH_H
#include <iostream>
using namespace std;
#define DEFAULT_SIZE 10

struct AdjListArcNode    //边结点定义
{
	int adjVex;
	AdjListArcNode *nextArc;

	AdjListArcNode():nextArc(NULL) {}

	AdjListArcNode(int _adjVex,AdjListArcNode *_nextArc=NULL)
	{
		adjVex=_adjVex;
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

class AdjListDirGraph     //邻接表实现有向图定义
{
public:
    AdjListDirGraph(int _vexMaxNum=DEFAULT_SIZE);
	AdjListDirGraph(char *Vexs,int _vexNum,int _vexMaxNum=DEFAULT_SIZE);
	~AdjListDirGraph();
	void Clear();
	void InsertArc(int vex1,int vex2);   //输入需合法，不考虑平行边，且vex1不等于vex2
	void Show();
	int GetVexNum();
	void GetVexsIndgree(int *indegree);
	char GetElem(int vex);
	int GetFirstAdjVex(int vex);
	int GetNextAdjVex(int vex1,int vex2);

private:
	VisitStatus *tag;
	AdjListVexNode *vexTable;
	int vexNum;
	int vexMaxNum;
	int arcNum;
	int *Indegree;
};

AdjListDirGraph::AdjListDirGraph(int _vexMaxNum)
{
	vexMaxNum=_vexMaxNum;
	vexNum=0;
	arcNum=0;
	tag=new VisitStatus[vexMaxNum];
	vexTable=new AdjListVexNode[vexMaxNum];
	Indegree=new int[vexMaxNum];
}

AdjListDirGraph::AdjListDirGraph(char *Vexs,int _vexNum,int _vexMaxNum)
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
}

AdjListDirGraph::~AdjListDirGraph()
{
	if(tag!=NULL)
		delete[] tag;
	Clear();
	if(vexTable!=NULL)
		delete[] vexTable;
	if(Indegree!=NULL)
		delete[] Indegree;
}

void AdjListDirGraph::InsertArc(int vex1,int vex2)
{
	vexTable[vex1].firstArc=new AdjListArcNode(vex2,vexTable[vex1].firstArc);
	arcNum++;
	Indegree[vex2]++;
}

void AdjListDirGraph::Show()
{
	for(int i=0;i<vexNum;i++)
	{
		cout<<vexTable[i].data<<": ";
		AdjListArcNode *p=vexTable[i].firstArc;
		while(p!=NULL)
		{
			cout<<p->adjVex<<" ";
			p=p->nextArc;
		}
		cout<<endl;
	}
	for(int i=0;i<vexNum;i++)
		cout<<Indegree[i]<<" ";
	cout<<endl;
}

void AdjListDirGraph::Clear()
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

int AdjListDirGraph::GetVexNum()
{
	return vexNum;
}

void AdjListDirGraph::GetVexsIndgree(int *indegree)
{
	for(int i=0;i<vexNum;i++)
		indegree[i]=Indegree[i];
}

char AdjListDirGraph::GetElem(int vex)
{
	return vexTable[vex].data;
}

int AdjListDirGraph::GetFirstAdjVex(int vex)
{
	if(vexTable[vex].firstArc==NULL)
		return -1;
	return vexTable[vex].firstArc->adjVex;
}

int AdjListDirGraph::GetNextAdjVex(int vex1,int vex2)
{
	AdjListArcNode *p=vexTable[vex1].firstArc;
	while(p!=NULL&&p->adjVex!=vex2)
		p=p->nextArc;
	if(p==NULL||p->nextArc==NULL)
		return -1;
	else
	    return p->nextArc->adjVex;
}
#endif