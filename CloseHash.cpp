#define DELETE -1				// 删除标记 
#define EMPTY  0				// 空标记 
#define USE    1				// 有元素标记 
#include<iostream>
using namespace std;

// 散列表类
template <class ElemType, class KeyType>
class ClosedHashTable
{
protected:
//  散列表的的数据成员:
	ElemType *ht;								// 散列表
	int *tag;								    // 标记数组 
	int maxSize;								// 散列表容量
	int p;										// 除留余数法的除数

//	辅助函数:
	int H(KeyType key) const;					// 散列函数
	int Collision(KeyType key, int i) const;	// 处理冲突的函数

public:
//  二叉树方法声明及重载编译系统默认方法声明:
  	ClosedHashTable(int size, int divisor);			// 构造函数
  	~ClosedHashTable();								// 析造函数
  	void Traverse() const;	// 遍历散列表
	int Search(const KeyType &key) const ;	    // 查寻关键字为key的元素的下标 
	int Insert(const ElemType &e);				// 插入元素e
	bool Delete(const KeyType &key);			// 删除关键字为key的元素
  	ClosedHashTable(const ClosedHashTable<ElemType, KeyType> &t);	// 复制构造函数
  	ClosedHashTable<ElemType, KeyType> &operator=
		(const ClosedHashTable<ElemType, KeyType> &t);			// 赋值语句重载
};

// 散列表类的实现部分
template <class ElemType, class KeyType>
int ClosedHashTable<ElemType, KeyType>::H(KeyType key) const
//操作结果: 返回散列地址
{
	return key % p;
}

template <class ElemType, class KeyType>
int ClosedHashTable<ElemType, KeyType>::Collision(KeyType key, int i) const
//操作结果: 返回第i次冲突的探查地址
{
	return (H(key) + i) % maxSize;
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType>::ClosedHashTable(int size, int divisor)
// 操作结果: 以size为散列表容量, divisor为除留余数法的除数构造一个空的散表表
{
	maxSize = size;						// 赋值散列表容量
	p = divisor;						// 赋值除数
	ht = new ElemType[maxSize];			// 分配元素存储空间
	tag = new int[maxSize];				// 分配标记数组存储空间

	for (int i = 0; i < maxSize; i++)   // 将所有元素置空
		tag[i] = 0;
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType>::~ClosedHashTable()
// 操作结果: 销毁散列表
{
	delete []ht;							// 释放散列表
	delete []tag;							// 释放标记数组 
}

template <class ElemType, class KeyType>
void ClosedHashTable<ElemType, KeyType>::Traverse() const
// 操作结果: 依次对散列表的每个元素调用函数(*visit)
{
	for (int i = 0; i < maxSize; i++)	// 对散列表的每个元素调用函数(*visit)
		if (tag[i] == DELETE)   	 
           cout << " * ";				// 数据元素已经删除 
        else  	if (tag[i] == EMPTY)	
           cout << " # ";  				// 该位置没有元素
        else 
			cout<<" "<<ht[i]<<" ";			// 该位置有元素
}

template <class ElemType, class KeyType>
int ClosedHashTable<ElemType, KeyType>::Search(const KeyType &key) const
// 操作结果: 查寻关键字为key的元素的值,如果查找成功,返回元素在数组的下标,否则返回-1. 
{
	int c = 0;							// 冲突次数
	int i = H(key);						// 元素的哈希函数值 

	while (c < maxSize &&	((tag[i] == USE && ht[i] != key) || tag[i] == DELETE))					
		// 冲突次数应小于maxSize且元素ht[pos]非空且关键字值不等
		i = Collision(key, ++c);		// 求得下一个探查地址

	if (c >= maxSize || tag[i] == EMPTY)
		return -1;						// 查找失败，返回-1 
	else 	
		return i;						// 查找成功，返回元素在数组中的下标 
}

template <class ElemType, class KeyType>
int ClosedHashTable<ElemType, KeyType>::Insert(const ElemType &e)
// 操作结果: 在散列表中插入数据元素e,插入成功返回true,否则返回false
{
   int c = 0;							// 冲突次数
   int i = H(e);						// 元素的哈希函数值 
   int k = -1;                     	// 插入位置 

   while (c < maxSize &&	((tag[i] == USE && ht[i] != e) || tag[i] == DELETE)) {					
      // 冲突次数应小于maxSize且元素ht[i]非空且关键字值不等
      if (k == -1 && tag[i] == DELETE)
         k = i;
      i = Collision(e, ++c);		//求得下一个探查地址
   }

	if (c >= maxSize && k == -1)	   // 冲突次数应大于等于maxSize，说明哈希表已经放满 
		 return 0;
	else  if (tag[i] == USE && ht[i] == e)
     return 0;
  else  {		// 查找失败，则插入元素 
     if (k == -1)
        k = i;
     ht[k] = e;
     tag[k] = USE; 
		 return 1;
  }
}

template <class ElemType, class KeyType>
bool ClosedHashTable<ElemType, KeyType>::Delete(const KeyType &key)
// 操作结果: 删除关键字为key的数据元素,删除成功返回true,否则返回false
{
  int i = Search(key);
	if (i == -1)	                 // 查找失败,说明元素不存在。 
		return false; 
	else	{	                       
		tag[i] = DELETE;				     // 设置删除标记 
		return true;                 // 删除成功
	}
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType>::ClosedHashTable(const ClosedHashTable<ElemType, KeyType> &t)
// 操作结果：由散列表t构造新散列表--复制构造函数
{
	maxSize = t.maxSize;										// 散列表容量
	p = t.p;										// 除留余数法的除数
	ht = new ElemType[maxSize];							// 分配存储空间
	tag = new int[maxSize];							// 分配存储空间

	for (int i = 0; i < maxSize; i++)	{	// 复制数据元素
		ht[i] = t.ht[i];		// 复制元素
		tag[i] = t.tag[i];// 复制元素是否为空值
	}
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType> &ClosedHashTable<ElemType, KeyType>::
operator=(const ClosedHashTable<ElemType, KeyType> &t)
// 操作结果：将散列表t赋值给当前散列表--赋值语句重载
{
	if (&t != this)	{
		delete []ht;								// 释放当前散列表存储空间
		delete []tag;
		maxSize = t.maxSize;						// 散列表容量
		p = t.p;									// 除留余数法的除数
		ht = new ElemType[maxSize];					// 分配存储空间
		tag = new int[maxSize];						// 分配存储空间

		for (int i = 0; i < maxSize; i++)		{	// 复制数据元素
			ht[i] = t.ht[i];	// 复制元素
			tag[i] = t.tag[i];// 复制元素是否为空值
		}
	}
	return *this;
}

int main()
{
	ClosedHashTable<int, int> ht(13, 13);
	int elem[] = {32,40,36,53,16,46,71,27,42,24,49,64};
	for (int i = 0; i < 12; i++)
		ht.Insert(elem[i]);
	ht.Traverse();
	cout<<endl;
	if(ht.Search(27)!=-1)
		cout<<"查找27成功!"<<endl;
	return 0;
}
