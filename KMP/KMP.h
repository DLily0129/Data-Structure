#include<string>
using std::string;

void GetFailure(const string &s,int *f)  //求失效函数值
{
/*	int n=s.length(),i,j,k,c=0;
	if(n==0)
		return ;
	f[0]=-1;
	for(i=1;i<n;i++)
	{
	    for(j=0,k=1;k<i;)
		{
			if(s[j]==s[k])
			{
				j++;
				k++;
				c++;
			}
			else
			{
				if(c==0)
				   k++;
				else
				{
					j=0;
					c=0;
				}
			}
		}
		f[i]=c;
		c=0;
	}
*/
	int j=0,k=-1;
	f[0]=-1;
	while(j<(s.length()-1))
		if(k==-1||s[k]==s[j])
			f[++j]=++k;
		else
			k=f[k];
}

int KMP_FIND(const string &ob,const string &pat)
{
	int n=pat.length(),m=ob.length();
	int *f=new int[n];
	GetFailure(pat,f);
    int i=0,j=0;
	while(i<m&&j<n&&(m-i)>=(n-j))
	{
		if(j==-1||ob[i]==pat[j])
		{
			i++; j++;
		}
		else
			j=f[j];
	}
	delete[] f;
	if(j<n)
		return -1;
	else
		return i-j;
}