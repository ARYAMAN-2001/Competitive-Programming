#include <bits/stdc++.h>
using namespace std;
int main() { 
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,min;
        cin>>n;
        long long s[n];
         for(int i=0;i<n;i++)
         cin>>s[i];
sort(s,s+n);
         
         min=s[1]-s[0];
         for(int i=0;i<n-1;i++)
         {for(int j=i+1;j<n;j++)
         if(s[j]-s[i]<min)
         min=s[j]-s[i];
         }
         cout<<min<<endl;

    }
   
}
