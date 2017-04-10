#include "AdjListUndirGraph.h"

int main()
{
	char vexs[12]="ABCDEFGHIJK";
	AdjListUndirGraph graph(vexs,11,11);
	graph.InsertArc(0,1);
	graph.InsertArc(0,4);
	graph.InsertArc(0,3);
	graph.InsertArc(1,2);
	graph.InsertArc(1,4);
	graph.InsertArc(2,4);
	graph.InsertArc(4,5);
	graph.InsertArc(5,8);
	graph.InsertArc(4,6);
	graph.InsertArc(6,7);
	graph.InsertArc(3,6);
	graph.InsertArc(9,10);
	graph.Show();
	graph.BFSTraverse();
	return 0;
}