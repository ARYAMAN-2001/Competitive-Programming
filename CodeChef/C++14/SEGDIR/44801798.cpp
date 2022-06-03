using namespace std;//****************************Template Begins****************************//
 
// Header Files
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list> 
#include<iterator>
#include<deque>  
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<string>
// Header Files End  
 
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(i=a;i<b;i++)
#define all(v) (v).begin(),(v).end()
#define all1(v) (v).begin()+1,(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define allr1(v) (v).rbegin()+1,(v).rend()
#define sort0(v) sort(all(v))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
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
//****************************Template Ends*******************************//
 

int main() {
    fio;
	long long t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll l[n],r[n],v[n],i,p=0,l1,r1,res=0,idx,k,j,q;
	    ll a[n][n][2],c[n];
	    map<ll,ll> m;
	    fo(i,0,n)
	    {cin>>l[i]>>r[i]>>v[i];
	    c[i]=0;}
	    fo(i,0,n)
	    {if(m[v[i]]==0)
	    {
	       a[p][c[p]][0]=l[i];
	       a[p][c[p]][1]=r[i];
	       m[v[i]]=p+1;
	       c[p]++;
	       p++;
	       
	    }
	    else
	    {
	        idx=m[v[i]]-1;
	        a[idx][c[idx]][0]=l[i];
	        a[idx][c[idx]][1]=r[i];
	        c[idx]++;
	    }}
	   // fo(i,0,p)
	   // {
	   //     fo(j,0,c[i])
	   //     cout<<a[i][j][0]<<" "<<a[i][j][1]<<endl;
	   //     cout<<endl;
	   // }
	    for(int i=0;i<p;i++)
	    {    
	        for(j=0;j<c[i]-2;j++)
	        {
	            for(k=j+1;k<c[i]-1;k++)
	            {if((a[i][j][0]>=a[i][k][0] and a[i][j][0]<=a[i][k][1]) or(a[i][j][1]>=a[i][k][0] and a[i][j][1]<=a[i][k][1]) or (a[i][k][0]>=a[i][j][0] and a[i][k][0]<=a[i][j][1]) or (a[i][k][1]>=a[i][j][0] and a[i][k][1]<=a[i][j][1])  )
	            {
	                l1=max(a[i][j][0],a[i][k][0]);
	                r1=min(a[i][j][1],a[i][k][1]);
	                for(q=k+1;q<c[i];q++)
	                {
	                    if((l1<=a[i][q][0] and a[i][q][0]<=r1) or (l1<=a[i][q][1] and a[i][q][1]<=r1) or (a[i][q][0]<=l1 and a[i][q][1]>=l1) or (a[i][q][0]<=r1 and a[i][q][1]>=r1) )
	                    {
	                        res=1;
	                        break;
	                    }
	                }
	                
	            }
	            if(res==1)
	            break;}
	            if(res==1)
	            break;
	        }
	        if(res==1)
	        break;
	    }
	    if(res==0)
	    cout<<"YES"<<endl;
	    else
	    cout<<"NO"<<endl;
	    
    }
return 0;
}
