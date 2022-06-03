#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--)
	{
	    long long n,d,e,c=0,s=0;
	    cin>>n>>d;
	    long long a[n];
	    for(int i=0;i<n;i++)
	    {cin>>a[i];
	    if(a[i]<=9 or a[i]>=80)
	    c++;
	    
	    }
	    e=n-c;
	    if(c%d!=0)
	    s=s+c/d+1;
	    else
	    s=s+c/d;
	    if(e%d!=0)
	    s=s+e/d+1;
	    else
	    s=s+e/d;
	    
	    cout<<s<<endl;
	    
	}
	return 0;
}
