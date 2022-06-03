#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    long long l,c=0;
	    l=s.length();
	    if(l%2!=0)
	    cout<<-1<<endl;
	     else
	    {
	      for(int i=0;i<l;i++)
	        {if(s[i]=='0')
	        c++;}
	        if(c==l or c==0)
	        cout<<-1<<endl;
	        else
	        cout<<abs(l-2*c)/2<<endl;
	    }
	    
	}
	
	return 0;
}
