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
int merge(int arr[], int temp[],
          int l, int m, int r, int K)
{
    // i: index to left subarray
    int i = l;
  
    // j: index to right subarray
    int j = m + 1;
  
    // Stores count of pairs that
    // satisfy the given condition
    int cnt = 0;
  
    for (int l = 0; i <= m; i++) {
        bool found = false;
  
        // Traverse to check for the
        // valid conditions
        while (j <= r) {
  
            // If condition satifies
            if (arr[i] >= K * arr[j]) {
                found = true;
            }
            else
                break;
            j++;
        }
  
        // While a[i] > K*a[j] satisfies
        // increase j
  
        // All elements in the right
        // side of the left subarray
        // also satisies
        if (found) {
            cnt += j - (m + 1);
            j--;
        }
    }
  
    // Sort the two given arrays and
    // store in the resultant array
    int k = l;
    i = l;
    j = m + 1;
  
    while (i <= m && j <= r) {
  
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
  
    // Elements which are left
    // in the left subarray
    while (i <= m)
        temp[k++] = arr[i++];
  
    // Elements which are left
    // in the right subarray
    while (j <= r)
        temp[k++] = arr[j++];
  
    for (int i = l; i <= r; i++)
        arr[i] = temp[i];
  
    // Return the count obtained
    return cnt;
}
int mergeSortUtil(int arr[], int temp[],
                  int l, int r, int K)
{
    int cnt = 0;
    if (l < r) {
  
        // Same as (l + r) / 2, but avoids
        // overflow for large l and h
        int m = (l + r) / 2;
  
        // Sort first and second halves
        cnt += mergeSortUtil(arr, temp,
                             l, m, K);
        cnt += mergeSortUtil(arr, temp,
                             m + 1, r, K);
  
        // Call the merging function
        cnt += merge(arr, temp, l,
                     m, r, K);
    }
  
    return cnt;
}
  
// Function to print the count of
// required pairs using Merge Sort
int mergeSort(int arr[], int N, int K)
{
    int temp[N];
  
    return mergeSortUtil(arr, temp, 0,
                          N - 1, K);
}
  



int main() {
    fio;
	int n;
	cin>>n;
	map<ll,ll> m;
	int a[n],i,sum=0;
	fo(i,0,n)
	{cin>>a[n-1-i];
	m[a[n-i-1]]++;}
	fo(i,0,n)
	{
	    if(m[a[i]]>1)
	    {sum+=m[a[i]]*(m[a[i]]-1)/2;
	    m[a[i]]=0;}
	    }
	cout<<mergeSort(a,n,1)-sum<<endl;
    
return 0;
}
