//****************************Template Begins****************************//
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
// // DSU
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
//min element in subarray of fixed length in O(1);
// deque<int> q;
// Finding the minimum:


// int minimum = q.front();
// Adding an element:


// while (!q.empty() && q.back() > new_element)
//     q.pop_back();
// q.push_back(new_element);
// Removing an element:


// if (!q.empty() && q.front() == remove_element)
//     q.pop_front();
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll _mergeSort(ll arr[], ll temp[], ll left, ll right);
ll merge(ll arr[], ll temp[], ll left, ll mid,
         ll right);
//merge sort gfg
/* This function sorts the
   input array and returns the
number of inversions in the array */
ll mergeSort(ll arr[], ll array_size)
{
    ll temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function
  that sorts the input array and
returns the number of inversions in the array. */
ll _mergeSort(ll arr[], ll temp[], ll left, ll right)
{
    ll mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
ll merge(ll arr[], ll temp[], ll left, ll mid,
         ll right)
{
    ll i, j, k;
    ll inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            /* this is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray
    (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray
       (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}
vll fact(300005, 1);

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
//  -------------- DIJKSTRA --------------
ll INF = 1e16;
ll h, w, n;
umap<ll, vll> m1, m2;
map<ll, vector<pll>> adj;
map<ll, ll> dd, vis;
void dijkstra(ll s, ll f)
{

    priority_queue<pll> q;
    dd[s] = 0;
    q .push({0, s});
    while (!q.empty())
    {
        ll v  = q.top().second;
        ll d_v   = -(q.top().first);
        q .pop();
        if (d_v != dd[v])continue;

        for (auto edge : adj[v])
        {
            auto to = edge.first;
            auto len = edge.second;
            // cout << dd[to] << " " << to << endl;
            if (dd[v] + len < dd[to] or (dd[to] == 0 and to != s))
            {
                // cout << to / w << " " << to % w << " " << v << " " << len << endl;
                dd[to] = dd[v] + len;

                q .push({ -dd[to], to});
            }
        }

    }
}
void check(ll x, ll y)
{
    if (x <= 0 or x > h or y <= 0 or y > w)
        return;
    ll idx = lb(all(m1[x]), y) - m1[x].begin();
    // cout << m1[x].size() << endl;
    // cout << idx << " " << x << " " << y << " " << z << endl;

    if (idx and vis[x * w + y - 1] == 0)
    {
        // cout << x << " &1 " << y << endl;
        adj[x * w + y].pb({x * w + m1[x][idx - 1], 1});
        // adj[x * w + m1[x][idx - 1]].pb({x * w + y, 1});
    }
    idx = lb(all(m1[x]), y + 1) - m1[x].begin();
    if (idx < m1[x].size() and vis[x * w + y + 1] == 0)
    {
        // cout << x << " &2 " << y << endl;
        adj[x * w + y].pb({x * w + m1[x][idx], 1});
        // adj[x * w + m1[x][idx + 1]].pb({x * w + y, 1});
    }
    idx = lb(all(m2[y]), x) - m2[y].begin();
    // cout << idx << " " << x << " " << y << " " << z << endl;

    if (idx and vis[(x - 1)*w + y] == 0)
    {
        // cout << x << " &3 " << y << endl;
        adj[x * w + y].pb({y + m2[y][idx - 1]*w, 1});
        // adj[y + w * m2[y][idx - 1]].pb({x * w + y, 1});
    }
    idx = lb(all(m2[y]), x + 1) - m2[y].begin();
    if (idx < m2[y].size() and vis[(x + 1)*w + y] == 0)
    {
        // cout << x << " &4 " << y << endl;
        adj[x * w + y].pb({y + w * m2[y][idx], 1});
        // adj[y + w * m2[y][idx + 1]].pb({x * w + y, 1});
    }


}
int main() {

    fio;

    cin >> h >> w >> n;

    ll i, x, y;
    ll a[n], b[n];
    vector<pll> v1, v2;
    ll c, d, p, q;
    cin >> c >> d >> p >> q;
    fo(i, 0, n)
    {
        cin >> x >> y;
        a[i] = x;
        b[i] = y;
        v1.pb({x, y});
        v2.pb({y, x});

    }
    sort(all(v1));
    sort(all(v2));
    fo(i, 0, n)
    {
        vis[w * v1[i].first + v1[i].second]++;
        if (v1[i].second > 1)
            m1[v1[i].first].pb(v1[i].second - 1);

        if (v1[i].second < w)
            m1[v1[i].first].pb(v1[i].second + 1);
        if (v2[i].second > 1)
            m2[v2[i].first].pb(v2[i].second - 1);

        if (v2[i].second < h)
            m2[v2[i].first].pb(v2[i].second + 1);
    }
    fo(i, 0, n)
    {
        check(a[i] - 1, b[i]);
        check(a[i] + 1, b[i]);
        check(a[i], b[i] - 1);
        check(a[i], b[i] + 1);
    }
    check(c, d);
    if (c * w + d == p * w + q)
        cout << 0 << endl;
    else
    {
        // cout << adj[c * w + d].size() << endl;
        dijkstra(c * w + d, p * w + q);
        if (dd[p * w + q])
            cout << dd[p * w + q] << endl;
        else
            cout << -1 << endl;
    }




    return 0;
}
//remove #define endl '\n' for interactive problems
