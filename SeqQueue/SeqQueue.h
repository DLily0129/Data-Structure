#ifndef SEQ_QUEUE_H   //循环队列，解决假溢出问题
#define SEQ_QUEUE_H
#include<iostream>
#define DEFAULT_SIZE 10
using std::cout;

template<typename ElemType>
class SeqQueue
{
protected:
	int front,rear;
	int maxSize;
	ElemType *elems;

public:
	SeqQueue(int size=DEFAULT_SIZE);
	virtual ~SeqQueue();
	int EnQueue(const ElemType &e);  //返回状态
	int DelQueue(ElemType &e);  //返回状态
	int GetLength();   //返回个数
	void Traverse();
};

template<typename ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
{
	maxSize=size;
	front=rear=0;
	elems=new ElemType[maxSize];
}
template<typename ElemType>
SeqQueue<ElemType>::~SeqQueue()
{
	if(elems!=NULL)
		delete[] elems;
}

template<typename ElemType>
int SeqQueue<ElemType>::EnQueue(const ElemType &e)
{
	if(rear-front==maxSize)   //队列已满
		return 0;
	elems[rear%maxSize]=e;
	rear++;
	return 1;
}

template<typename ElemType>
int SeqQueue<ElemType>::DelQueue(ElemType &e)
{
	if(rear==front)   //队列为空
		return 0;
	e=elems[front%maxSize];
	front++;
	return 1;
}

template<typename ElemType>
int SeqQueue<ElemType>::GetLength()
{
	return rear-front;
}

template<typename ElemType>
void SeqQueue<ElemType>::Traverse()
{
	int length=rear-front;    //可以进一步改进为不要rear，只要length数据成员，遍历较复杂
	int i,j;
	for(i=front%4,j=0;i<maxSize&&j<length;i++,j++)
		cout<<elems[i]<<" ";
	if(i==maxSize)
	{
		for(i=0;j<length;j++)
			cout<<elems[i]<<" ";
	}
}
#endif