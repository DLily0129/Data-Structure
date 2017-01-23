#include"Polynomial.h"

Polynomial::Polynomial()
{
}

Polynomial::Polynomial(const LinkList<PolyItem> &p)
{
	polyList=p;
}

void Polynomial::Display() const
{
	PolyItem p;
	int status=polyList.GetElem(1,p);
	if(status!=0)
	{
		cout<<p.coef<<"x^"<<p.expn;
		for(int i=2;polyList.GetElem(i,p);i++)
		{	
			if(p.coef>0)
				cout<<"+";
		    cout<<p.coef;
			if(p.expn!=0)
				cout<<"x^"<<p.expn;
		}
	}

}

ostream & operator<<(ostream &out,Polynomial &p)
{
	p.Display();
	return out;
}

Polynomial::~Polynomial()
{
}

Polynomial Polynomial::operator+ (const Polynomial &other) const
{
	int i,j;
	PolyItem pa,pb;
	Polynomial result;
	for(i=1,j=1;polyList.GetElem(i,pa)&&other.polyList.GetElem(j,pb);)
	{
		if(pa.expn>pb.expn)
		{
             result.polyList.InsertElem(pa);
			 i++;
		}
		else if(pa.expn<pb.expn)
		{
			result.polyList.InsertElem(pb);
			j++;
		}
		else
		{
			if(pa.coef+pb.coef!=0)
			{
				pa.coef=pa.coef+pb.coef;
				result.polyList.InsertElem(pa);
				i++;  j++;
			}
		}
	}
	while(polyList.GetElem(i,pa))
	{
		result.polyList.InsertElem(pa);
		i++;
	}
	while(other.polyList.GetElem(j,pb))
	{
		result.polyList.InsertElem(pb);
		j++;
	}
	return result;
}

Polynomial Polynomial::operator- (const Polynomial &other) const
{
	int i,j;
	PolyItem pa,pb;
	Polynomial result;
	for(i=1,j=1;polyList.GetElem(i,pa)&&other.polyList.GetElem(j,pb);)
	{
		if(pa.expn>pb.expn)
		{
             result.polyList.InsertElem(pa);
			 i++;
		}
		else if(pa.expn<pb.expn)
		{
			pb.coef=-pb.coef;
			result.polyList.InsertElem(pb);
			j++;
		}
		else
		{
			if(pa.coef-pb.coef!=0)
			{
				pa.coef=pa.coef-pb.coef;
				result.polyList.InsertElem(pa);
				i++;  j++;
			}
		}
	}
	while(polyList.GetElem(i,pa))
	{
		result.polyList.InsertElem(pa);
		i++;
	}
	while(other.polyList.GetElem(j,pb))
	{
		pb.coef=-pb.coef;
		result.polyList.InsertElem(pb);
		j++;
	}
	return result;
}

Polynomial Polynomial::operator* (const Polynomial &other) const
{
	Polynomial sum,temp;
	int i,j;
	PolyItem pa,pb,pc;
	for(j=1;other.polyList.GetElem(j,pb);j++)
	{
		for(i=1;polyList.GetElem(i,pa);i++)
		{
			pc.coef=pa.coef*pb.coef;
			pc.expn=pa.expn+pb.expn;
			temp.polyList.InsertElem(pc);
		}
		sum=sum+temp;
		temp.polyList.Clear();
	}
	return sum;
}