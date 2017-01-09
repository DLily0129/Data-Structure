#include "linklist.h"
#include<iostream>
using std::cout;
using std::endl;

void Print(const int &n)
{
	cout<<n<<" ";
}

int main()
{
	int p[5]={7,5,1,3,9},a;
	LinkList<int> llist1(p,5),llist2(llist1),llist3;
	
	llist2.Traverse(Print);  //测试深拷贝
	cout<<endl;	
	
	llist1.Traverse(Print);
	cout<<endl;
	
	llist1.InsertElem(100);  //在末尾插入
	llist1.Traverse(Print);
	cout<<endl;
	
	llist1.InsertElem(3,90);  //在指定位置插入
	llist1.Traverse(Print);
	cout<<endl;

	llist1.DeleteElem(2,a);  //删除
	llist1.Traverse(Print);
	cout<<endl;

	cout<<llist1.LocateElem(5)<<endl;  //定位

	llist1.GetElem(6,a);  //取元素
	cout<<a<<endl;

	llist1.SetElem(1,80);  //改值
	llist1.Traverse(Print);
	cout<<endl;

	llist3=llist1;  //测试深赋值
	llist1.Traverse(Print);
	cout<<endl;
	return 0;
}
