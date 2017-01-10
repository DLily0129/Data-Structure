#ifndef NODE_H    
#define NODE_H 
#include<iostream>

template <typename ElemType>
struct Node
{
    ElemType data;
	int next;
	
    Node();
    Node(const ElemType &e,int n=-1);
};

template <typename ElemType>
Node<ElemType>::Node()
{
	next=-1;
}

template <typename ElemType>
Node<ElemType>::Node(const ElemType &e,int n)
{
	data=e;
	next=n;
}

#endif
