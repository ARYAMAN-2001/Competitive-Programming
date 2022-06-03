#include <bits/stdc++.h>
using namespace std;

int main() {
	long long d1,v1,d2,v2,p,s=0;
	cin>>d1>>v1>>d2>>v2>>p;
	for(int i=0;i<=10000;i++)
	{   s=0;
	    if(i>=d1)
	    s=s+(i-d1+1)*v1;
	    if(i>=d2)
	    s=s+(i-d2+1)*v2;
	    if(s>=p)
	    {cout<<i<<endl;
	    break;}
	}
	
	return 0;
}
