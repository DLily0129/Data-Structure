#ifndef SEQLIST
#define SEQLIST
#include<iostream>

#define DEFAULT_SIZE 100

template <typename ElemType>
class SeqList
{
public:
	SeqList(int size=DEFAULT_SIZE);   //创建有一定容量的空表
	SeqList(ElemType *data,int n,int size=DEFAULT_SIZE);  //根据所给数组创建线性表,不考虑n>size的情况
	~SeqList();
	SeqList(const SeqList &other);  //深拷贝
	SeqList & operator=(const SeqList &other); //深赋值
	bool isEmpty() const;   //判读是否为空表
	void Clear();   //清空列表
	int InsertElem(const ElemType &e);   //在末尾插入元素,返回状态
	int InsertElem(int i,const ElemType &e);   //在指定位置插入元素,返回状态
	int DeleteElem(int i,ElemType &e);   //删除指定位置元素,返回状态
	int SetElem(int i,const ElemType &e);   //修改指定位置的元素,返回状态
	int GetElem(int i,ElemType &e) const;  //取得指定位置的元素，i从1开始,返回状态
    int LocateElem(const ElemType &e) const;  //定位元素
	int GetLength() const;  //取得长度
	void Traverse(void (*visit)(const ElemType &)) const;   //遍历

protected:
	int length;
	int maxLength;
	ElemType *elems;
};

template <typename ElemType>
SeqList<ElemType>::SeqList(int size)
{
	elems=new ElemType[size];
	length=0;
	maxLength=size;
}

template <typename ElemType>
SeqList<ElemType>::SeqList(ElemType *data,int n,int size=DEFAULT_SIZE)
{
	elems=new ElemType[size];
	maxLength=size;
	length=n;
	for(int i=0;i<n;i++)
		elems[i]=data[i];
}

template <typename ElemType>
SeqList<ElemType>::~SeqList()
{
	if(elems!=NULL)
		delete[] elems;
}

template <typename ElemType>
SeqList<ElemType>::SeqList(const SeqList &other)
{
	elems=NULL;
	*this=other;
}

template <typename ElemType>
SeqList<ElemType> & SeqList<ElemType>::operator=(const SeqList<ElemType> &other)
{
	length=other.length;
	maxLength=other.maxLength;
	if(elems!=NULL)
		delete[] elems;
	elems=new ElemType[maxLength];
	for(int i=0;i<other.length;i++)
		elems[i]=other.elems[i];
	return *this;
}

template <typename ElemType>
bool SeqList<ElemType>::isEmpty() const
{
	if(length==0)
		return true;
	else
		return false;
}

template <typename ElemType>
void SeqList<ElemType>::Clear()
{
	length=0;
}

template <typename ElemType>
int SeqList<ElemType>::InsertElem(const ElemType &e)
{
	if(length==maxLength)
		return 0;
	else
	{
		elems[length]=e;
		length++;
		return 1;
	}
}

template <typename ElemType>
int SeqList<ElemType>::InsertElem(int i,const ElemType &e)
{
	if(length==maxLength)
		return 0;
	else if(i<1||i>length+1)
		return 0;
	else
	{
		for(int j=length;j>=i;j--)
			elems[j]=elems[j-1];
		elems[i-1]=e;
		length++;
		return 1;
	}
}

template <typename ElemType>
int SeqList<ElemType>::DeleteElem(int i,ElemType &e)
{
	if(i<1||i>length)
		return 0;
	else
	{
		e=elems[i-1];
		for(int j=i;j<length;j++)
			elems[j-1]=elems[j];
		length--;
		return 1;
	}
}

template <typename ElemType>
int SeqList<ElemType>::SetElem(int i,const ElemType &e)
{
	if(i<1||i>length)
		return 0;
	else
	{	
		elems[i-1]=e;
		return 1;
	}

}

template <typename ElemType>
int SeqList<ElemType>::GetElem(int i,ElemType &e) const
{
	if(i<1||i>length)
		return 0;
	else
	{
		e=elems[i-1];
		return 1;
	}
}

template <typename ElemType>
int SeqList<ElemType>::LocateElem(const ElemType &e) const
{
	for(int i=0;i<length;i++)
	  if(elems[i]==e)
		return ++i;
	return 0;
}

template <typename ElemType>
int SeqList<ElemType>::GetLength() const
{
	return length;
}

template <typename ElemType>
void SeqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
{
	for(int i=0;i<length;i++)
		(*visit)(elems[i]);
}

#endif
