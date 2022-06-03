#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--){
	    long long n,c=0;
	    cin>>n;
	    string b;
	    cin>>b;
	    for(int i=0;i<n;i++)
	    {if(b[i]=='0')
	    c++;}
	    
	    if(c>30)
	    cout<<"NO"<<endl;
	    else
	    cout<<"YES"<<endl;
	}
	
	return 0;
}
