#include <iostream>
using namespace std;
int main()
{
	int*a;
	int n;
	cin>>n;
	a=new int[n];
	for(int i=0; i<n; i++)
		cin>>(*(a+i));
	for(int i=1; i<n; i++)
	{  if(*(a+i-1)>*(a+i))
		{ int c=*(a+i);
		  int right=i-1, left=0;
		  do
		 {
		    int mid=(right+left)/2;
			
			if(*(a+mid)<c) left=mid+1;
			else 
				right=mid-1;
		 }
		 while(left<=right);
		 
		 
		 for(int j=i-1; j>=left; j--)
			 *(a+j+1)=*(a+j);
		     *(a+left)=c;
	   }
	}
	for(int i=0; i<n; i++)
		cout<<*(a+i);
	delete [] a;
	system("pause");
	return 0;
}
