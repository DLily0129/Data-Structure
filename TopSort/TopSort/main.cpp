#include "TopSort.h"

int main()
{
	char vexs[]="ABCDEF";
	AdjListDirGraph graph(vexs,6,6);
	graph.InsertArc(1,0);
	graph.InsertArc(3,0);
	graph.InsertArc(2,0);
	graph.InsertArc(1,3);
	graph.InsertArc(2,3);
	graph.InsertArc(4,2);
	graph.InsertArc(4,3);
	graph.InsertArc(4,5);
	graph.InsertArc(3,5);

	graph.Show();
	TopSort(graph);
	return 0;
}