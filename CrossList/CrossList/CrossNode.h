#ifndef CROSS_NODE_H
#define CROSS_NODE_H
#include<iostream>
using namespace std;

template <typename ElemType>
struct Triple
{
	int row,col;
	ElemType value;

	Triple() {}
	Triple(int r,int c,const ElemType &e):row(r),col(c),value(e) {}
};

template <typename ElemType>
struct CrossNode
{
	Triple<ElemType> triElem;
	CrossNode<ElemType> *down,*right;

	CrossNode()  {}
	CrossNode(Triple<ElemType> &_triElem):triElem(_triElem),down(NULL),right(NULL) {}
};

#endif
