#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--){
	    long long n,m,s1=0,s2=0,sum,r=0;
	    cin>>n>>m;
	    long long a[n],b[m];
	    for(int i=0;i<n;i++)
	    {cin>>a[i];
	    s1=s1+a[i];}
	    for(int i=0;i<m;i++)
	    {cin>>b[i];
	    s2=s2+b[i];}
	    /*cout<<s1<<" "<<s2<<endl;*/
	    if(s1>s2)
	    cout<<0<<endl;
	    else
	    {    sum=s1+s2;
	        sort(a,a+n);
	        sort(b,b+m);
	        for(int i=0 ;i<n and m-i-1>=0;i++)
	        {s1=s1-a[i]+b[m-i-1];
	        if(s1>sum/2)
	        {cout<<i+1<<endl;r=1;break;}}
	        if(r==0)
	    cout<<-1<<endl;
	    }
	    
	    
	}
	
	return 0;
}
