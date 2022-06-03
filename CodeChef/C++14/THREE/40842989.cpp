#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    long long l,e=0,sum=0;
	    char d;
	    l=s.length();
	    map<char,long long>ct;
	    d='a';
	    while(d<='z')
	    {
	        ct[d]=0;
	        d++;}
	      for(int i=0;i<l;i++)
	      {
	          ct[s[i]]++;
	      }
	    
	    d='a';
	    while(d<='z')
	    {
	        sum+=ct[d]/2;
	        d++;
	    }
	    cout<<min(sum,l/3)<<endl;
	}
	
	return 0;
}
