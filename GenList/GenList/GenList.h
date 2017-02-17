#ifndef GEN_LIST_H    //广义表
#define GEN_LIST_H
#include <iostream>
#include <assert.h>
using namespace std;

enum GenListNodeType{HEAD,ATOM,SUBLIST};
struct GenListNode
{
	GenListNodeType tag;
	union 
	{
		//int ref;   可用可不用
		char data;
		GenListNode *sublink;
	};
	GenListNode *next;

	GenListNode(GenListNodeType _type,char c=0):tag(_type),next(NULL)
	{
		if(tag==ATOM)
			data=c;
	}
};


class GenList
{
public:
	GenList();
	GenList(char *str);
	GenList(const GenList &copy);
	GenList & operator=(const GenList &copy);
	~GenList();
	void Print();
    friend ostream & operator<<(ostream &out,GenList &gList);
	int GetDepth();

protected:
   GenListNode* CreateGenList(char* &str);
   void ClearGenList(GenListNode *first);
   void _Print(GenListNode *first);
   int _Depth(GenListNode *first);
   GenListNode* _Copy(GenListNode *first);

private:
	GenListNode *head;
};

GenList::GenList():head(NULL)
{
}

GenList::GenList(char *str)
{
	head=CreateGenList(str);
}

GenList::GenList(const GenList &copy)
{
	head=_Copy(copy.head);
}

GenList & GenList::operator=(const GenList &copy)
{
	ClearGenList(head);
	head=_Copy(copy.head);
	return *this;
}

GenList::~GenList()
{
	ClearGenList(head);
}

void GenList::Print()
{
	_Print(head);
}

ostream & operator<<(ostream &out,GenList &gList)
{
	gList.Print();
	return out;
}

int GenList::GetDepth()
{
	int depth=_Depth(head);
	return depth;
}

GenListNode* GenList::CreateGenList(char* &str)   //注意要为引用，否则不成功
{
	assert(*str=='(');     //表达式的第一个字符一定是"(",如果不是，则有问题
	++str;          //读取左括号后的字符

	GenListNode *_head=new GenListNode(HEAD);//创建头结点
	GenListNode *cur=_head;
	while(*str)
	{
		if((*str>='a'&&*str<='z')||(*str>='A'&&*str<='Z'))
		{
			cur->next=new GenListNode(ATOM,*str);
			cur=cur->next;
			str++;
		}
		else if(*str=='(')
		{
			cur->next=new GenListNode(SUBLIST);
			cur=cur->next;
			cur->sublink=CreateGenList(str);
		}
		else if(*str==')')
		{
			str++;
			break;
		}
		else
			str++;
	}
	return _head;
}

void GenList::ClearGenList(GenListNode *first)
{
	GenListNode *cur=first,*del;
	while(cur)
	{
		del=cur;
		cur=cur->next;
        if(del->tag==SUBLIST)
			ClearGenList(del->sublink);
		delete del;
	}
}

void GenList::_Print(GenListNode *first)
{
	GenListNode *cur=first;
	while(cur)
	{
		if(cur->tag==HEAD)
			cout<<"(";
		else if(cur->tag==ATOM)
		{
			cout<<cur->data;
			if(cur->next)
				cout<<",";
		}
		else
		{
			_Print(cur->sublink);
			if(cur->next)
				cout<<",";	
		}
        cur=cur->next;
	}
	cout<<")";
}

int GenList::_Depth(GenListNode *first)
{
	GenListNode *cur=first;
	int depth=1;
	while(cur)
	{
		if(cur->tag==SUBLIST)
		{
			int subdepth=_Depth(cur->sublink);
			if(subdepth+1>depth)
				depth=subdepth+1;
		}
		cur=cur->next;
	}
	return depth;
}

GenListNode* GenList::_Copy(GenListNode *first)
{
	GenListNode *_head=new GenListNode(HEAD);
	GenListNode *p=first->next,*cur=_head;
	while(p)
	{
		if(p->tag==ATOM)
		{
            cur->next=new GenListNode(ATOM,p->data);
			cur=cur->next;
			p=p->next;
		}  
		else
		{
		   cur->next=new GenListNode(SUBLIST); 
		   cur=cur->next;
		   cur->sublink=_Copy(p->sublink);
		   p=p->next;
		}
	}
	return _head;
}
#endif