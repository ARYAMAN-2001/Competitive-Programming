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
ll maxSubArraySum(ll a[], ll size)
{
  ll max_so_far = -1e16, max_ending_here = 0,
       start =0, end = 0, s=0;
 
    for (ll i=0; i< size; i++ )
    {
        max_ending_here += a[i];
 
        if(max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
 
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    return max_so_far ;
    // cout << "Starting index "<< start
    //     << endl << "Ending index "<< end << endl;
} 

int main() {
    fio;
	ll minsum=0,cursum=0,i,j;
	ll x;
	ll a[1000000],p=0,max=-100000000000,b[1000000],q=0;
	while(cin>>x)
	{
	    a[p]=x;
	    p++;
	    if(x>max)
	    max=x;
	}
// 	fo(i,0,p)
// 	cout<<a[i]<<" ";
	   if(max<=0)
	   cout<<max<<endl;
	   else
	   {
	       fo(i,0,p)
	       { q=0;
	           fo(j,0,p)
	           {
	               if(j!=i)
	               {
	                   b[q]=a[j];
	                   q++;
	               }
	           
	           }
	           ll m=maxSubArraySum(b,p-1);
	           if(m>max)
	           max=m;
	       }
	       cout<<max<<endl;
	   }
    
return 0;
}
