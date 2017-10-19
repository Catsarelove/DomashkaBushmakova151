#include <iostream>
using namespace std;
bool root (long long m)
{
	double t = pow(m, 0.5);
	if (t-(long long)t == 0) return true;
	return false;
}
bool prim(long long a)
{
	bool flag = true;
	if(a % 2 == 0) return false;
	if (a<8) return true;
	for(int i=3; i<=pow(a,0.5) && flag; i++)
		if(a%i==0) flag=0; 
	return flag;
}
long long prost(long long a)
{
	if(a % 2 == 0) return 2;
	for(int i=3; i<=pow(a,0.5); i+2)
		if(prim(i) && a%i==0) return i;
}
int Legendre (long long m, long long p)
{
   	 if(root(m)) return 1;
	 if(m==2) {
		 if(abs(p%8) == 1 || abs(8 - p%8) == 1) return 1;
		 else return -1;
	 }
	 if(m==(-1)){
		 if(p%4 == 1) return 1;
		 else return -1;
	 }
	 if(prim(p) && prim(m)){
		if (p%4 == 1 || m%4 ==1)
		return Legendre(p % m, m);
		return (-1)*Legendre(p % m, m);
	 }
	 if(!prim(m)){
		long long t=m;
		long long k=1;
		while(!prim(t))
			{
				k*=Legendre(prost(t),p);
					t=t/prost(t);
			}
		return k;
	}
	 long long t=p;
	 long long l=1;
     while(!prim(t))
		{
			l*=Legendre(m, prost(t));
		}
	 return l;

	 }
long long power(long long a, long long p, int n)
{
	long long r = 1;
    while (n!=0){
			if (n%2 == 1) {
				r = (r * a)%p;
				n--;
			}
			a = (a*a)%p;
			n=n/2;
			r=r%p;
			
	}
    if(abs(r%p)<p/2) return r%p;
	return r%p-p;
}
int main()
{
	long long x,a,p,e = 0;
	cin>>a>>p;
	
	int s=p-1;
	while(s % 2 == 0)
	{
		s/=2;
		e++;
	}
	if(e == 1) x = pow(a, (double)(p+1)/4);
	if(e!=1)
	{
		int z=0;
		bool flag = true;
		for(int i=3; i<=pow(p,0.5) && z==0; i++)
			if(prim(i) && Legendre(i,p)==(-1)) z=i;
		long long c = (long long)pow(z,1.*s)%p;
		long long y = power(a,p,(s+1)/2)%p;
		long long t = power(a,p,s)%p;
		int n = e;
		long long b;
		int i;
		while(t!=1){
				for( i=1; i<n && power(t,p,pow(2.,i))!=1; i++);
				b=power(c,p,pow(2.,n-1-i));
				c=(b*b) % p;
				y=(y*b)%p;
				t=(t*c)%p;
				n=i;
		}
	 x=y;
	}
	cout<<x;
	system("pause");
	return 0;
}
