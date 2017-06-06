#include <iostream>
using namespace std;
#define DEFAULT_DIVISOR 11

//链地址法结点定义
struct HashNode    
{
	int key;
	HashNode *next;

	HashNode();
	HashNode(int _key,HashNode *_next=NULL);
};

HashNode::HashNode()
{
	next=NULL;
}

HashNode::HashNode(int _key,HashNode *_next)
{
	key=_key;
	next=_next;
}

//链地址法散列表类定义
class OpenHashTable
{
public:
	OpenHashTable(int divisor=DEFAULT_DIVISOR);
	~OpenHashTable();
	HashNode * Find(int key);
	void Insert(int key);
	void Display();

private:
	HashNode *ht;
	int div;    //除留余数法的除数

	int H(int key);
};

int OpenHashTable::H(int key)
{
	return key%div;
}

OpenHashTable::OpenHashTable(int divisor)
{
	div=divisor;
	ht=new HashNode[divisor];
}

OpenHashTable::~OpenHashTable()
{
	for(int i=0;i<div;i++)
	{
		HashNode *p=ht[i].next;
        while(p!=NULL)
		{
			ht[i].next=p->next;
			delete p;
			p=ht[i].next;
		}	
	}
	delete[] ht;
		
}

HashNode * OpenHashTable::Find(int key)
{
	int i=H(key);
	HashNode *p=ht[i].next;
	while(p!=NULL && p->key!=key)
		p=p->next;
	return p;
}

void OpenHashTable::Insert(int key)
{
	int i=H(key);
	HashNode *p=Find(key);
	if(p==NULL)    //关键字未找到，可以插入
		ht[i].next=new HashNode(key,ht[i].next);   //在表头插入
	else
	    cout<<"该键值已存在"<<endl;
}

void OpenHashTable::Display()
{
	for(int i=0;i<div;i++)
	{
		cout<<i<<": ";
		HashNode *p=ht[i].next;
		while(p!=NULL)
		{
			cout<<p->key<<" ";
			p=p->next;
		}
		cout<<endl;
	}
}

int main()
{
	int a[]={32,40,36,53,16,46,71,27,42,24,49,64},i;
	OpenHashTable htable(13);
	for(i=0;i<12;i++)
		htable.Insert(a[i]);
	htable.Display();
	if(htable.Find(27)!=NULL)
		cout<<"查找27成功!"<<endl;
	return 0;
}
