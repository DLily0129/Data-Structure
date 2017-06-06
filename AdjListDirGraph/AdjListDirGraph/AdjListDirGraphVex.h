#ifndef ADJ_LIST_DIR_GRAPH_VEX_H
#define ADJ_LIST_DIR_GRAPH_VEX_H
#include "AdjListDirGraphArc.h"
#include <iostream>
using namespace std;

//有向图邻接表顶点结点定义
template<typename ElemType>
struct AdjListDirGraphVex   
{
//数据成员:
	ElemType data;
	AdjListDirGraphArc *firstArc;

//构造函数:
	AdjListDirGraphVex();   //无参构造函数
	AdjListDirGraphVex(ElemType VexValue,AdjListDirGraphArc *_firstArc=NULL);  //有参构造函数
};

template<typename ElemType>
AdjListDirGraphVex<ElemType>::AdjListDirGraphVex():firstArc(NULL) 
{
}

template<typename ElemType>
AdjListDirGraphVex<ElemType>::AdjListDirGraphVex(ElemType VexValue,AdjListDirGraphArc *_firstArc)
{
	data=VexValue;
	firstArc=_firstArc;
}
#endif