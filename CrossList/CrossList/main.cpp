#include"CrossList.h"
using namespace std;

int main()
{
	Triple<int> tris[9]={Triple<int>(0,0,15),Triple<int>(0,3,22),Triple<int>(0,5,-5),
		Triple<int>(1,1,11),Triple<int>(1,2,3),Triple<int>(2,3,6),Triple<int>(4,0,91),
		Triple<int>(5,1,7),Triple<int>(6,2,28)};
	CrossList<int> CList(7,6,9,tris);
    cout<<CList;
	return 0;
}