#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t,i,j,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n],b[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];
        }
        ll max=0;
        for(i=0;i<n;i++)
        {
            if(a[i]*20-b[i]*10>max)
                max=a[i]*20-b[i]*10;
        }
        cout<<max<<endl;
    }
}