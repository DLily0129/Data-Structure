#include"SeqStack.h"
#include<iostream>
#include<cstring>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

struct train
{
	char c;
	int num;

	train(){}
	train(int Num):c(0),num(Num)
	{
	}
	void Set(char C,int Num)
	{
		c=C;
		num=Num;
	}
	friend ostream & operator<<(ostream &out,const train &t)
	{
		out<<t.c;
		return out;
	}
};

int main()
{
	SeqStack<train> stack,stack2;
	char InSeq[30],OutSeq[30];
	cout<<"输入进站序列:";
	cin>>InSeq;
	cout<<"输入出站序列:";
	cin>>OutSeq;
	int i,j,n=strlen(OutSeq);
	train Seq[30],temp;
	for(i=0;OutSeq[i];i++)
		Seq[i].Set(OutSeq[i],i+1);
/*	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(Seq[j].c>Seq[j+1].c)
			{
				temp=Seq[j];
				Seq[j]=Seq[j+1];
				Seq[j+1]=temp;
			}
*/
	for(i=0;i<n-1;i++)
		for(j=i;j<n;j++)
           if(Seq[j].c==InSeq[i])
		   {
			   if(j!=i)
			   {
				   temp=Seq[j];
				   Seq[j]=Seq[i];
				   Seq[i]=temp;
				   break;
			   }
			   else
				   break;
		   }
	for(i=0,j=1;i<n;)
	{
        if(Seq[i].num==j)
		{
			stack.Push(Seq[i]);
		    cout<<stack.Top()<<"进调度站"<<endl;  
			stack2.Push(stack.Pop());
		    cout<<stack2.Top()<<"出调度站"<<endl;
			j++;
			i++;
		}
		else if(Seq[i].num<stack.Top().num)
		{
			stack.Push(Seq[i]);
			cout<<stack.Top()<<"进调度站"<<endl; 
			i++;
		}
		else
		{
			while(!stack.isEmpty()&&Seq[i].num>stack.Top().num)
		   {   
			   stack2.Push(stack.Pop());
		       cout<<stack2.Top()<<"出调度站"<<endl;
		   }
		   stack.Push(Seq[i]);
		   cout<<Seq[i]<<"进调度站"<<endl;
		   i++;
		   while(!stack.isEmpty()&&stack2.Top().num>j)
			{
				 stack.Push(stack2.Pop());
				 cout<<stack.Top()<<"进调度站"<<endl;
		   }
		   if(stack2.Top().num==j)
			   j++;
		}
	}
	while(!stack.isEmpty())
	{
	     stack2.Push(stack.Pop());
		 cout<<stack2.Top()<<"出调度站"<<endl;
	}
	return 0;
}