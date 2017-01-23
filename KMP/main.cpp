#include"KMP.h"
#include<iostream>
using std::cout;

int main()
{
	string ob="abcabcaaa",pat="caa";
	cout<<KMP_FIND(ob,pat);
	return 0;
}