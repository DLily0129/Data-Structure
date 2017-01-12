#ifndef SEQ_STACK_H
#define SEQ_STACK_H
#include<iostream>
using std::cout;
#define DEFAULT_SIZE 30

template<typename ElemType>
class SeqStack
{
protected:
	ElemType *elems;
	int top;
	int maxSize;
public:
	SeqStack(int size=DEFAULT_SIZE);
	~SeqStack();
	bool isEmpty();
	int Push(const ElemType &e);
	ElemType Pop();
	ElemType Top();
	int GetLength();
	void Traverse();
};

template<typename ElemType>
SeqStack<ElemType>::SeqStack(int size)
{
	maxSize=size;
	top=-1;
	elems=new ElemType[maxSize];
}

template<typename ElemType>
SeqStack<ElemType>::~SeqStack()
{
	if(elems!=NULL)
		delete[] elems;
}

template<typename ElemType>
bool SeqStack<ElemType>::isEmpty()
{
	if(top==-1)
		return true;
	else
		return false;
}

template<typename ElemType>
int SeqStack<ElemType>::Push(const ElemType &e)
{
	if(top==maxSize-1)
		return 0;
	elems[++top]=e;
	//cout<<e<<"in";
	    return 1;
}

template<typename ElemType>
ElemType SeqStack<ElemType>::Pop()
{
	if(top==-1)
		return 0;
	ElemType e=elems[top--];
	//cout<<e<<"out";
	    return e;
}

template<typename ElemType>
ElemType SeqStack<ElemType>::Top()
{
	if(top==-1)
		return 0;
	return elems[top];
}

template<typename ElemType>
int SeqStack<ElemType>::GetLength()
{
	return top+1;
}

template<typename ElemType>
void SeqStack<ElemType>::Traverse()
{
	for(int i=top;i>=0;i--)
		cout<<elems[i];
}
#endif
