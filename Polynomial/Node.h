#ifndef NODE    
#define NODE 
#include<iostream>

template <typename ElemType>
struct Node
{
    ElemType data;
	Node *next;
	
    Node();
    Node(const ElemType &e,Node *p=NULL);
};

template <typename ElemType>
Node<ElemType>::Node()
{
	next=NULL;
}

template <typename ElemType>
Node<ElemType>::Node(const ElemType &e,Node *p)
{
	data=e;
	next=p;
}

#endif
