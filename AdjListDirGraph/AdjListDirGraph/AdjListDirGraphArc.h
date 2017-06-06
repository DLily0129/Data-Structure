#ifndef ADJ_LIST_DIR_GRAPH_ARC_H
#define ADJ_LIST_DIR_GRAPH_ARC_H
#include <iostream>
using namespace std;

//有向图邻接表边结点定义
struct AdjListDirGraphArc    
{
//数据成员:
	int adjVex;
	AdjListDirGraphArc *nextArc;

//构造函数:
	AdjListDirGraphArc();   //无参构造函数
	AdjListDirGraphArc(int _adjVex,AdjListDirGraphArc *_nextArc=NULL);   //有参构造函数
};

AdjListDirGraphArc::AdjListDirGraphArc():adjVex(-1),nextArc(NULL) 
{
}

AdjListDirGraphArc::AdjListDirGraphArc(int _adjVex,AdjListDirGraphArc *_nextArc)
{
	adjVex=_adjVex;
	nextArc=_nextArc;
}
#endif