#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int k,n;
	    cin>>n>>k;
	    long long s=0,d=0,b=0,c=0;
	    long long e,f;
	    long long a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    sort(a,a+n);
	    for(int i=0;i<k;i++)
	    s+=a[i];
	    for(int i=k;i<n;i++)
	    b+=a[i];
	    for(int i=0;i<n-k;i++)
	    c+=a[i];
	    for(int i=n-k;i<n;i++)
	    d+=a[i];
	    e=abs(s-b);
	    f=abs(c-d);
	    if(e>f)
	    cout<<e<<endl;
	    else
	    cout<<f<<endl;
	}
	return 0;
}
