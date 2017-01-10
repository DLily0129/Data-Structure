#include"SeqQueue.h"
#include<iostream>
using std::cout;
using std::endl;

int main()
{
	SeqQueue<int> sq(4);
	int a;
	sq.EnQueue(3);
	sq.EnQueue(7);
	sq.EnQueue(1);
	sq.EnQueue(2);
	sq.Traverse();
	cout<<endl;
	sq.DelQueue(a);
	sq.DelQueue(a);
	sq.DelQueue(a);
	sq.DelQueue(a);
	sq.Traverse();
	cout<<endl;
	sq.EnQueue(10);
	sq.EnQueue(20);
	sq.Traverse();
	return 0;
}