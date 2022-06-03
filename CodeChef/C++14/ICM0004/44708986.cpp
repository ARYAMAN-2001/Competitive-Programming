using namespace std;//****************************Template Begins****************************//
 
// Header Files
#include <bits/stdc++.h>
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
#define ld long double
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
ld findArea(ld a, ld b, ld c)
{
    // Length of sides must be positive
    // and sum of any two sides
    // must be smaller than third side.
    if (a < 0 || b < 0 || c < 0 ||
       (a + b <= c) || a + c <= b ||
                       b + c <= a)
    {
        cout << "Not a valid trianglen";
        exit(0);
    }
    ld s = (a + b + c) / 2;
    return sqrt(s * (s - a) *
                    (s - b) * (s - c));
} 

int main() {
    fio;
	long long t;
	cin>>t;
	while(t--){
	    ld a,b,c,k;
	    cin>>a>>b>>c>>k;
	    cout<<fixed<<setprecision(8)<<k*findArea(a,b,c)/(k+1)<<endl;
    }
return 0;
}
