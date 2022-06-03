#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--){
	    long long x,y,k,n;
	    cin>>x>>y>>k>>n;
	    if(abs(x-y)%k==0)
	    {
	        if(abs(x-y)/k%2==0)
	        cout<<"Yes"<<endl;
	        else
	        cout<<"No"<<endl;
	    }
	    else
	    cout<<"No"<<endl;
	}
	
	return 0;
}
