//****************************Template Begins****************************//

// Header Files
#include<iostream>
#include<iomanip>
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
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// Header Files End

using namespace std;
// using namespace __gnu_pbds;
// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// template<class key, class value, class cmp = std::less<key>>
// using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

#define DIVYA ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(i=a;i<=b;i++)
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
#define mkp make_pair
#define inf 1000000000000000005
const ll mod = 998244353;

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
//****************************Template Ends*******************************//
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n, m, k;
vector<vector<pll>>adj;
vector<pll>par;

void dfs(ll curr_node, ll parent)
{
    for (auto x : adj[curr_node])
    {
        if (x.first == parent)continue;
        par[x.first] = {curr_node, x.second};
        dfs(x.first, curr_node);
    }
}

int main() {
    DIVYA;
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t, i, j, ans, temp, sum, u, v;
    string sans;
    t = 1;
    // cin >> t;
    while (t--)
    {
        sans = "NO";
        ans = temp = sum = 0;
        cin >> n >> m >> k;
        adj.assign(n + 1, {});
        vll a(m + 1, 0);
        fo(i, 1, m)
        {
            cin >> a[i];
        }
        fo(i, 1, n - 1)
        {
            cin >> u >> v;
            adj[u].pb({v, i});
            adj[v].pb({u, i});
        }
        vll cnt(n, 0);
        ll sum = 0;
        fo(i, 1, m - 1)
        {
            par.assign(n + 1, { -1, -1});
            u = a[i];
            v = a[i + 1];
            dfs(u, -1);
            vll path;
            ll curr = v;
            while (curr != u)
            {
                path.pb(par[curr].second);
                sum++;
                cnt[par[curr].second]++;
                curr = par[curr].first;
            }
        }
        k = abs(k);
        // vector<vector<int>>dp(n+1,vector<int>(k+100005,0));
        vll dp(100010);
        dp[0] = 1;
        fo(i, 0, n - 1)
        {
            for (j = 100000; j >= cnt[i]; j--)
            {
                dp[j] += dp[j - cnt[i]];
                dp[j] %= mod;
            }
        }
        if ((sum + k) % 2 or sum + k < 0)
            cout << 0 << endl;
        else
            cout << (dp[(sum + k) / 2] * inv(2)) % mod << endl;

    }
    return 0;
}













