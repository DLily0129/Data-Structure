#include "AdjListDirGraph.h"

int main()
{
//构造初始图:
	char vexs[]="ABC";
	AdjListDirGraph<char> graph(vexs,3);
	graph.InsertArc(0,2);
	graph.InsertArc(0,1);
	graph.InsertArc(1,2);
	graph.InsertArc(2,1);

//对该图进行部分常用操作:
	cout<<"1. 显示当前有向图"<<endl;
	cout<<"2. 插入顶点"<<endl;
	cout<<"3. 插入弧"<<endl;
	cout<<"4. 删除弧"<<endl;
	cout<<"5. 删除顶点"<<endl;
	cout<<"6. 输出给定顶点v的第一个邻接顶点"<<endl;
	cout<<"7. 输出给定顶点v1关于某一个顶点v2的下一邻接顶点"<<endl;
	cout<<"0. 退出"<<endl;
	cout<<"请选择功能(0~7):";
	char c,e,e1,e2,ee;
	while(cin>>c && c!='0')	
	{
		if(c=='1')
		{
			cout<<"\n1. 显示当前有向图"<<endl;
			graph.Display();
			cout<<endl<<"请选择功能(0~7):";
		}
		else if(c=='2')
		{
			cout<<"\n2. 插入顶点"<<endl;
			cout<<"请输入插入的顶点:";
			cin>>e;
			graph.InsertVex(e);
			cout<<"执行完毕"<<endl<<"\n请选择功能(0~7):";
		}
		else if(c=='3')
		{
			cout<<"\n3. 插入弧"<<endl;
			cout<<"请输入与该弧的起点与终点:";
			cin>>e1>>e2;
			graph.InsertArc(graph.GetOrder(e1),graph.GetOrder(e2));
			cout<<"执行完毕"<<endl<<"\n请选择功能(0~7):";
		}
		else if(c=='4')
		{
			cout<<"\n4. 删除弧"<<endl;
			cout<<"请输入与该弧的起点与终点:";
			cin>>e1>>e2;
			graph.DeleteArc(graph.GetOrder(e1),graph.GetOrder(e2));
			cout<<"执行完毕"<<endl<<"\n请选择功能(0~7):";
		}
		else if(c=='5')
		{
			cout<<"\n5. 删除顶点"<<endl;
			cout<<"请输入删除的顶点:";
			cin>>e;
			graph.DeleteVex(e);
			cout<<"执行完毕"<<endl<<"\n请选择功能(0~7):";
		}
		else if(c=='6')
		{
			cout<<"\n6. 输出给定顶点v的第一个邻接顶点"<<endl;
			cout<<"请输入给定的顶点v:";
			cin>>e;
			ee=graph.GetElem(graph.FirstAdjVex(graph.GetOrder(e)));
			cout<<"该顶点的第一个邻接顶点为:"<<ee<<endl;
			cout<<"执行完毕"<<endl<<"\n请选择功能(0~7):";
		}
		else if(c=='7')
		{
			cout<<"\n7. 输出给定顶点v1关于某一个顶点v2的下一邻接顶点"<<endl;
			cout<<"请输入v1与v2:";
			cin>>e1>>e2;
			ee=graph.GetElem(graph.NextAdjVex(graph.GetOrder(e1),graph.GetOrder(e2)));
			cout<<"下一邻接顶点为:"<<ee<<endl;
			cout<<"执行完毕"<<endl<<"\n请选择功能(0~7):";
		}
	}
	return 0;
}