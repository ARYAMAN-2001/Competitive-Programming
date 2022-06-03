#include <bits/stdc++.h>
#include<vector>

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(i=a;i<b;i++)
#define all(v) (v).begin(),(v).end()
#define all1(v) (v).begin()+1,(v).end()
#define sort0(v) sort(all(v))

#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),max((c),(d)))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define inf 9999999999999
const ll mod=1e9+7;
 
ll inv(ll i){if(i==1) return 1;return (mod-((mod/i)*inv(mod%i))%mod)%mod;}
 
ll gcd(ll a,ll b){ if (b==0) return a;return gcd(b,a%b);}
 
ll pwr(ll a, ll b) {a %= mod; ll res = 1;while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;}return res;}
using namespace std;

int main() {
    fio;
	long long t;
	cin>>t;
	while(t--){
	    ll n,i,count=0;
	    cin>>n;
	    ll a[n],b[n],pos[100000];
	    fo(i,0,n)
	    {cin>>a[i];
	    pos[a[i]]=i;}
	    fo(i,0,n)
	    cin>>b[i];
	    sort(a,a+n);
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<100;j++)
	        {
	            if(pos[a[i]]+j*b[pos[a[i]]]>pos[a[i-1]])
	            {count=count+j;pos[a[i]]=pos[a[i]]+j*b[pos[a[i]]];break;}
	        }
	    }
	    cout<<count<<endl;
	}
	
	return 0;
}
