#include "UFSets.h"
#include <iostream>
using namespace std;

int main()
{
	char *str="ABCDE";
	UFSets<char> uf(str,5);
	uf.Union('D','E');
	uf.Union('C','E');
	cout<<uf.isDifferent('C','D')<<endl;
	cout<<uf;
}