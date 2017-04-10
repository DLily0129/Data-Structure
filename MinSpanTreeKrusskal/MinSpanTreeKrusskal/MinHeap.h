#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include <iostream>
using namespace std;

template <typename ElemType>
class MinHeap
{
private:
	ElemType *heapArr;
	int maxSize,CurrentSize;

public:
	MinHeap(int _maxSize=10);
	MinHeap(ElemType *_heapArr,int n,int _maxSize);
	~MinHeap();
	void FilterDown(int _start);
	void FilterUp(int _end);
	int DeleteTop(ElemType &_top);   //返回状态
	int Insert(ElemType _item);     //返回状态
	template <typename ElemType>
	friend ostream & operator<<(ostream &out,const MinHeap<ElemType> &minheap);
	
};

template <typename ElemType>
MinHeap<typename ElemType>::MinHeap(int _maxSize)
{
	if(_maxSize<=0)
	{
        cout<<"堆的大小不能小于1";
		return ;
	}
	maxSize=_maxSize;
	CurrentSize=0;
	heapArr=new ElemType[maxSize];
}

template <typename ElemType>
MinHeap<typename ElemType>::MinHeap(ElemType *_heapArr,int n,int _maxSize)
{
	if(n>_maxSize||_maxSize<=0||n<0)
	{
		cout<<"输入错误";
		return ;
	}
	maxSize=_maxSize;
	CurrentSize=n;
	heapArr=new ElemType[maxSize];
	int i;
	for(i=0;i<CurrentSize;i++)
		heapArr[i]=_heapArr[i];
	i=(CurrentSize-2)/2;
	while(i>=0)
	{
		FilterDown(i);
		i--;
	}
}

template <typename ElemType>
void MinHeap<typename ElemType>::FilterDown(int _start)
{
	int i=_start;
	int j=2*i+1;
	ElemType temp=heapArr[i];
	while(j<CurrentSize)
	{
		if(j+1<CurrentSize&&heapArr[j+1]<heapArr[j])
		    j++;
		if(temp<=heapArr[j])
			break;
		else
		{
			heapArr[i]=heapArr[j];
			i=j;
			j=2*j+1;
		}
	}
	heapArr[i]=temp;
}

template <typename ElemType>
void MinHeap<typename ElemType>::FilterUp(int _end)
{
	int i=_end;
	int j=(i-1)/2;
	ElemType temp=heapArr[i];
	while(i>0)
	{
		if(temp>=heapArr[j])
			break;
		else
		{
			heapArr[i]=heapArr[j];
			i=j;
			j=(j-1)/2;
		}
	}
	heapArr[i]=temp;
}

template <typename ElemType>
int MinHeap<typename ElemType>::DeleteTop(ElemType &_top)
{
	if(CurrentSize==0)
		return 0;
	_top=heapArr[0];
	heapArr[0]=heapArr[CurrentSize-1];
	CurrentSize=CurrentSize-1;
	FilterDown(0);
	return 1;
}

template <typename ElemType>
int MinHeap<typename ElemType>::Insert(ElemType _item)
{
    if(CurrentSize==maxSize)
		return 0;
	heapArr[CurrentSize]=_item;
	CurrentSize++;
	FilterUp(CurrentSize-1);
	return 1;
}

template <typename ElemType>
MinHeap<typename ElemType>::~MinHeap()
{
	delete[] heapArr;
}

template <typename ElemType>
ostream & operator<<(ostream &out,const MinHeap<ElemType> &minheap)
{
	for(int i=0;i<minheap.CurrentSize;i++)
        out<<minheap.heapArr[i]<<" ";
	out<<endl;
	return out;
}


#endif