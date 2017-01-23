#ifndef LINK_LIST    //有头链表 
#define LINK_LIST
#include "Node.h"
#include<iostream>

template <typename ElemType>
class LinkList
{
	//friend class Polynomial;
public:
	LinkList();
	LinkList(const ElemType *elems,int n);	
	~LinkList();
	LinkList(const LinkList &other);   //深拷贝
	LinkList & operator=(const LinkList &other); //深赋值
	void Clear();
	void Traverse(void (*visit)(const ElemType &e)) const;
	int GetLength() const;
	int InsertElem(const ElemType &e);  //返回状态
	int InsertElem(int i,const ElemType &e);  //返回状态
	int DeleteElem(int i,ElemType &e);   //返回状态
	int LocateElem(const ElemType &e) const;   //返回元素所在位置
	int GetElem(int i,ElemType &e) const;   //返回状态,取得元素放在e内
	int SetElem(int i,const ElemType &e);

protected:
	Node<ElemType> *head;
	int length;
	
};

template <typename ElemType>
LinkList<ElemType>::LinkList()
{
	head=new Node<ElemType>;
	length=0;
}

template <typename ElemType>
LinkList<ElemType>::LinkList(const ElemType *elems,int n)
{
	head=new Node<ElemType>;
	Node<ElemType> *p=head;
	for(int i=0;i<n;i++)
	{
		p->next=new Node<ElemType>(elems[i]);
		p=p->next;
	}
	length=n;
}

template <typename ElemType>
void LinkList<ElemType>::Clear()
{
	length=0;
	Node<ElemType> *p=head->next;
	while(p)
	{
		head->next=p->next;
		delete p;
		p=head->next;
	}
}

template <typename ElemType>
LinkList<ElemType>::~LinkList()
{
	Clear();
	delete head;
}

template <typename ElemType>
LinkList<ElemType>::LinkList(const LinkList &other)
{
	length=other.length;
	head=new Node<ElemType>;
	Node<ElemType> *q=other.head->next,*p=head;
	while(q)
	{
		p->next=new Node<ElemType>(q->data);
		q=q->next;
		p=p->next;
	}
}

template <typename ElemType>
LinkList<ElemType> & LinkList<ElemType>::operator=(const LinkList<ElemType> &other)
{
	Clear();
	length=other.length;
	Node<ElemType> *q=other.head->next,*p=head;
	while(q)
	{
		p->next=new Node<ElemType>(q->data);
		q=q->next;
		p=p->next;
	}
	return *this;
}

template <typename ElemType>
void LinkList<ElemType>::Traverse(void (*visit)(const ElemType &e)) const
{
	Node<ElemType> *p=head->next;
	while(p)
	{
		(*visit)(p->data);
		p=p->next;
	}
}

template <typename ElemType>
int LinkList<ElemType>::GetLength() const
{
	return length;
}

template <typename ElemType>
int LinkList<ElemType>::InsertElem(const ElemType &e)
{
	Node<ElemType> *p=head;
	while(p->next)
	{
		p=p->next;
	}
	p->next=new Node<ElemType>(e);
	length++;
	return 1;
}

template <typename ElemType>
int LinkList<ElemType>::InsertElem(int i,const ElemType &e)
{
    if(i<1||i>length+1)
		return 0;
	else{
	  Node<ElemType> *p=head,*q;
	  for(int count=1;count<i;count++)
		 p=p->next;
	  q=new Node<ElemType>(e,p->next);
	  p->next=q;
	  length++;
	  return 1;
	}
}

template <typename ElemType>
int LinkList<ElemType>::DeleteElem(int i,ElemType &e)
{
	if(i<1||i>length)
		return 0;
	else{
	  Node<ElemType> *p=head,*q;
	  for(int count=1;count<i;count++)
		  p=p->next;
	  q=p->next;
	  e=q->data;
	  p->next=q->next;
	  delete q;
	  length--;
	  return 1;
	}
}

template <typename ElemType>
int LinkList<ElemType>::LocateElem(const ElemType &e) const
{
	Node<ElemType> *p=head->next;
	int i=1;
	while(p)
	{
		if(p->data==e)
			return i;
		else
		{
			p=p->next;
			i++;
		}
	}
	return 0;
}

template <typename ElemType>
int LinkList<ElemType>::GetElem(int i,ElemType &e) const
{
	if(i<1||i>length)
         return 0;
	Node<ElemType> *p=head->next;
	for(int count=1;count<i;count++)
		p=p->next;
	e=p->data;
	return 1;
}

template <typename ElemType>
int LinkList<ElemType>::SetElem(int i,const ElemType &e)
{
	if(i<1||i>length)
		return 0;
	Node<ElemType> *p=head->next;
	for(int count=1;count<i;count++)
		p=p->next;
	p->data=e;
	return 1;
}
#endif
