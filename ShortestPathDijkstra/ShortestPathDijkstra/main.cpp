#include "ShortestPathDijkstra.h"
#include "AdjMatrixDirNetwork.h"

int main()
{
	char vexs[]="012345";
	AdjMatrixDirNetwork network(vexs,6,6);

	network.InsertArc(0,1,45);
	network.InsertArc(0,2,50);
	network.InsertArc(0,3,15);
	network.InsertArc(1,2,5);
	network.InsertArc(1,4,20);
	network.InsertArc(1,5,15);
	network.InsertArc(3,0,10);
	network.InsertArc(3,1,10);
	network.InsertArc(3,4,79);
	network.InsertArc(4,1,30);
	network.InsertArc(5,4,20);

	network.Display();
	ShortestPathDijkstra(network,0);
	return 0;
}