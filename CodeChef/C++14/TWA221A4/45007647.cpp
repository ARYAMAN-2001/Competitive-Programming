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
	string s;
	cin>>s;
	ll a,i,j,res=0,d=1,idx;
	cin>>a;
// 	cout<<a<<endl;

	ll n=s.length();
	while(d!=0)
	{d=0;
	
	    fo(i,0,n)
	{
	   if(s[i]==s[i+1])
	   {  res=0;
	       fo(j,i,i+a-1)
	       {
	           if(s[j]!=s[j+1])
	           {
	              res=1;
	           //   cout<<j<<" "<<j+1<<" ";
	              break;
	           }
	       }
	       //cout<<res<<" "<<i<<" ";
	       if(res==0)
	       {
	           fo(j,i,n)
	           s[j]=s[j+a];
	           n-=a;
	           d=1;
	       }
	   }
	}
	}
	fo(i,0,n)
	cout<<s[i];
	cout<<endl;
return 0;
}
