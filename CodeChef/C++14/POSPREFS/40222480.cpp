#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--)
	{
	    long long n,k;
	    cin>>n>>k;
	    if(k>n/2)
	    {
	        for(int i=1;i<=n-k;i++)
	    {
	        cout<<-2*i+1<<" "<<2*i<<" ";
	    }
	    for(int i=2*(n-k)+1;i<=n;i++)
	    cout<<i<<" ";
	    cout<<endl;
	        }
	    else{
	            for(int i=1;i<=k;i++)
	    {
	        cout<<2*i-1<<" "<<-2*i<<" ";
	    }
	    for(int i=2*k+1;i<=n;i++)
	    cout<<-i<<" ";
	    cout<<endl;
	        }}
	return 0;
}
