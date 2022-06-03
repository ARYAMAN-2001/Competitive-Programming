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
#define PI 3.14159265
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
	    long double n,val,sum,r;
	    cin>>n;
	     long double x,g;
      x=(180.000000000/n);
     val = PI / 180.000000000;
    sum = cos(x * val);
    //   g=x;
    //   if(g<=90.000)
    //   x=x*3.14/180.000;
    //   else
    //   {x=180.000-x;
    //       x=x*(3.14/180.000);}
    //   float a1=1.000,b1=1.000,c1=1.000,d1=1.000,e1=1.000,f1=1.000,a=1.000,b=1.000,c=1.000,d=1.000,e=1.000,f=1.000;
    //   for(float i=1.000;i<3.000;i++)
    //   {a*=i;
    //           a1*=x;}
    //   for(float i=2.000;i<5.000;i++)
    //   {   b*=i;
    //       b1*=x;}
    //   for(float i=2.000;i<7.000;i++)
    //   {c*=i;
    //           c1*=x;}
    //   for(float i=2.000;i<9.000;i++)
    //   {d*=i;
    //           d1*=x;}

    //   for(float i=2.000;i<11.000;i++)
    //   {e*=i;
    //           e1*=x;}
    //   for(float  i=2.000;i<13.000;i++)
    //   {f*=i;
    //           f1*=x;}
    //   float sum,r;
    //   sum=1-a1/a+b1/b-c1/c+d1/d-e1/e+f1/f;
    //   if(g<90.000)
    //   printf("%.3f\n",sum);
    //   else if(g==90.000)
    //           printf("0.00\n");
    //   else
    //           printf("%.3f\n",-sum);
  
    // cout<<sum<<endl;
    
    cout<<fixed<<setprecision(8)<<1/(1-sum*sum)<<endl;
    

    }
return 0;
}
