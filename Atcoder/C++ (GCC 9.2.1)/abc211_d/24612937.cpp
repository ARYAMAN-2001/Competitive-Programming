//****************************Template Begins****************************//
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
#include<chrono>
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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define inf 9999999999999
#define endl '\n'
const ll mod1 = 998244353;
const ll mod = 1e9 + 7;
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
//****************************Template Ends*******************************//
//****************************Functions*******************************//
// const int M = 4 * 1e5 + 1;
// ll parent[M];
// ll size1[M];

// void make_set(ll v) {
//     parent[v] = v;
//     size1[v] = 1;
// }

// ll find_set(ll v) {
//     if (v == parent[v])
//         return v;
//     return parent[v] = find_set(parent[v]);
// }
//                                         // DSU
// bool union_sets(ll a, ll b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a == b) {
//         return false;
//     }
//     if (a != b) {
//         if (size1[a] < size1[b])
//             swap(a, b);
//         parent[b] = a;
//         size1[a] += size1[b];
//     }
//     return true;
// }
// vector<vll> dp(n + 1, vll(k + 1, 99999999999));



//         dp[0][0] = 0;
//         for (int i = 0; i <= n; i++)
// for (int j = 0; j < k; j++) {
//             dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
// MCMF (hungarian algo) flows,graph matching,dp
//             if (i < n)
//                 dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(a[i] - (j + 1)));
//         }
ll findMinNumber(ll n)
{
    ll count = 0, ans = 1;

    // Since 2 is only even prime, compute its
    // power seprately.
    while (n % 2 == 0)
    {
        count++;
        n /= 2;
    }

    // If count is odd, it must be removed by dividing
    // n by prime number.
    if (count % 2)
        ans *= 2;

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }

        // If count is odd, it must be removed by
        // dividing n by prime number.
        if (count % 2)
            ans *= i;
    }

    if (n > 2)
        ans *= n;

    return ans;
}


// ll fact(ll n , ll mod)
// {
//     ll p=1;
//     if (n == 0)
//         return 1;

//     else
//     {
//         for(int i=1;i<=n;i++)
//         {p*=i;
//         p=p%mod;}
//         return p;
//     }
// }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// vll fact(300005, 1);
// fo(i, 2, 300005)
// {
//     fact[i] = mod_mul(fact[i - 1], i); //include the loop inside int main()
// }

// ll C(ll n, ll r)
// {
//     ll ans = 1;
//     ans = fact[n];
//     ans = mod_mul(ans, pwr(fact[r], mod - 2));
//     ans = mod_mul(ans, pwr(fact[n - r], mod - 2));
//     return ans;
// }
// vector<bool>isprime(10000001, true);
// vll primes;

// void sieve()
// {
//  ll i, j;
//  fo(i, 2, 10000001)
//  {
//      if (isprime[i])
//      {
//          for (j = i * i; j <= 10000000; j += i)
//          {
//              isprime[j] = false;
//          }
//      }
//  }
//  fo(i, 2, 10000001)if (isprime[i])primes.pb(i);
// }
void BFS(vector<int> adj[], int src, int dist[],
         int paths[], int n)
{
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    dist[src] = 0;
    paths[src] = 1;

    queue <int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        // For all neighbors of current vertex do:
        for (auto x : adj[curr])
        {
            // if the current vertex is not yet
            // visited, then push it to the queue.
            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }

            // check if there is a better path.
            if (dist[x] > dist[curr] + 1)
            {
                dist[x] = dist[curr] + 1;
                paths[x] = paths[curr] % mod;
            }

            // additional shortest paths found
            else if (dist[x] == dist[curr] + 1)
            {   paths[x] += (paths[curr] % mod);
                paths[x] %= mod;
            }
        }
    }
}

// function to find number of different
// shortest paths form given vertex s.
// n is number of vertices.
void findShortestPaths(vector<int> adj[],
                       int s, int n)
{
    int dist[n], paths[n];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    for (int i = 0; i < n; i++)
        paths[i] = 0;
    BFS(adj, s, dist, paths, n);
    cout << paths[n - 1] % mod << endl;
}

// A utility function to add an edge in a
// directed graph.
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
int main()
{
    fio;

#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m, i, x, y;
    cin >> n >> m;
    vector <int> adj[n];
    fo(i, 0, m)
    {
        cin >> x >> y;
        addEdge(adj, x - 1, y - 1);
        addEdge(adj, y - 1, x - 1);
    }
    findShortestPaths(adj, 0, n ) ;

}
//remove #define endl '\n' for interactive problems
