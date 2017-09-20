#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
void Quick(int* a, int L, int R)
{
	int i,j,bar;
	i=L;
	j=R;
	bar=a[(L+R)/2];
	do
	{ while(a[i]<bar)
		 i++;
	  while(a[j]>bar)
		 j--;
	  if(i<=j)
	  {if (i<j) {int t=a[i]; a[i]=a[j]; a[j]=t;}
	  i++; j--;}
	}
	while (i<=j);
	if (L<j) Quick(a,L,j);
	if (R>i) Quick(a,i,R);

}
int f_m(int *a, int n)
{
	Quick(a,0,n-1);
	int k=0;
	for(int i=0;a[i]<=a[n/2]/2; i++) 
		k++;
	return k;
}
int main()
{
	int*a;
	int n;
	cin>>n;
	a=new int[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<f_m(a,n);
	delete[] a;
	system("pause");
	return 0;
}