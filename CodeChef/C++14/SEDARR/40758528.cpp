#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--){
	    long long n,k;
	    cin>>n>>k;
	    long long a[n],sum=0;
	    for(int i=0;i<n;i++)
	    {cin>>a[i];
	    sum=sum+a[i];}
	    if(sum%k==0)
	    cout<<0<<endl;
	    else
	    cout<<1<<endl;
	}
	
	return 0;
}
