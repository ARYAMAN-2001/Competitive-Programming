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
	    ll n,e,h,a,b,c,c1,c2,c3,d=0,a1,b1,c4,sum=0,min1=1e13,i,j;
	    cin>>n>>e>>h>>a>>b>>c;
	    c1=max(d,min(2*e+h-3*n,e/2));
	    c2=max(d,min(e+h-2*n,h/3));
	    c3=min(h,e);
	   // cout<<c1<<" "<<c2<<" "<<c3<<endl;
	    if((h-c3)/3+(e-c3)/2+c3<n)
	    cout<<-1<<endl;
	    else
	    {if(n>=1e3)
	      {if(min3(a,b,c)==c )
	      {
	          a1=min(n,c3);
	          sum+=a1*c;
	          if(min(a,b)==a)
	          {
	              b1=min(n-a1,(e-a1)/2);
	              sum+=b1*a;
	              c1=min(n-a1-b1,(h-a1)/3);
	              sum+=c1*b;
	          }
	          cout<<sum<<endl;
	      }
	      else if(min3(a,b,c)==a and min(b,c)==b)
	      {
	          if(e/2>=n)
	          sum=a*n;
	          else
	          {
	              
	                  if(e/2+min(n-e/2,h/3)+min(e-(e/2)*2,h-(h/3)*3)>=n)
	                  sum+=e/2*a+min(n-e/2,h/3)*b+max(d,(n-e/2-min(n-e/2,h/3)))*c;
	                  else
	                 { fo(i,1,e/2+1)
	                  {
	                      if((e-2*i)/2+(e-((e-2*i)/2)*2)+(h-(e-((e-2*i)/2)*2))/3>=n)
	                      {sum=(e-2*i)/2*a+(e-((e-2*i)/2)*2)*c+(h-(e-((e-2*i)/2)*2))/3*b;break;}
	                  }
	                 }
	              
	          }
	          cout<<sum<<endl;
	      }
	      else if(min3(a,b,c)==b and min(a,c)==a)
	      {
	          if(h/3>=n)
	          sum=b*n;
	          else
	          {
	              
	                  if(min(n-h/3,e/2)+h/3+min(e-(e/2)*2,h-(h/3)*3)>=n)
	                  sum+=min(n-h/3,e/2)*a+h/3*b+max(d,(n-min(n-h/3,e/2)-h/3))*c;
	                  else
	                  { fo(i,1,h/3+1)
	                  {
	                     if((h-3*i)/3+(h-(h-3*i)/3*3)+(e-(h-(h-3*i)/3*3))/2>=n)
	                     {
	                         sum=(h-3*i)/3*b+(h-(h-3*i)/3*3)*c+(e-(h-(h-3*i)/3*3))/2*a;break;
	                     }
	                  }}
	              
	          }
	          cout<<sum<<endl;
	          
	      }
	          else
	         { fo(i,0,c1+1)
	          {
	              fo(j,0,min(c2,n-i)+1)
	              {   sum=min1+1;
	                  c3=n-i-j;
	                  if(c3==n-i-j and c3+2*i<=e and c3+3*j<=h)
	                  {
	                      sum=i*a+j*b+c*c3;
	                  }
	                  if(sum<min1)
	                  {min1=sum;
	               //cout<<i<<" "<<j<<" "<<c3<<endl;	
	               }              
	              }
	          }
	             cout<<min1<<endl;
	         }
	      }
	      else
	         { fo(i,0,c1+1)
	          {
	              fo(j,0,min(c2,n-i)+1)
	              {   sum=min1+1;
	                  c3=n-i-j;
	                  if(c3==n-i-j and c3+2*i<=e and c3+3*j<=h)
	                  {
	                      sum=i*a+j*b+c*c3;
	                  }
	                  if(sum<min1)
	                  {min1=sum;
	               //cout<<i<<" "<<j<<" "<<c3<<endl;	
	               }              
	              }
	          }
	             cout<<min1<<endl;
	         }
	          
	      
	      
	     
	    }
	    
	    
	    
    }
return 0;
}
