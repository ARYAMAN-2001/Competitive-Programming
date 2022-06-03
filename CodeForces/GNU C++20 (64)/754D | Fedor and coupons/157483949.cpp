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
// Header Files End

using namespace std;

#define ARYA ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
#define sz(x) (ll)x.size()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define inf 1000000000000000005
const ll mod = 1e9 + 7;

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
//****************************Template Ends*******************************//

int main() {
    ARYA;
    ll t, n, i, j, ans, temp, sum, k;
    string sans;
    t = 1;
    // cin >> t;
    while (t--)
    {
        sans = "NO";
        ans = temp = sum = 0;
        cin >> n >> k;
        vll l(n + 1), r(n + 1);
        fo(i, 1, n)
        {
            cin >> l[i] >> r[i];
        }
        if (k == 1)
        {
            ll idx = -1;
            fo(i, 1, n)
            {
                if (r[i] - l[i] + 1 >= ans)
                {
                    ans = r[i] - l[i] + 1;
                    idx = i;
                }
            }
            cout << ans << "\n";
            cout << idx << "\n";
        }
        else
        {
            map<ll, vll>insertions;
            map<ll, vll>removals;
            vll points;
            fo(i, 1, n)
            {
                insertions[l[i]].pb(i);
                removals[r[i] + 1].pb(i);
                points.pb(l[i]);
                points.pb(r[i] + 1);
            }
            sort(all(points));
            points.erase(unique(all(points)), points.end());
            multiset<pll>ls, ls1;
            multiset<pll>rs, rs1;
            for (auto x : points)
            {
                for (auto y : removals[x])
                {
                    if (ls.find({l[y], y}) != ls.end())
                    {   ls.erase(ls.find({l[y], y}));
                        rs.erase(rs.find({r[y], y}));
                    }
                }
                for (auto y : insertions[x])
                {
                    ls.insert({l[y], y});
                    rs.insert({r[y], y});
                }
                ll siz = sz(ls);
                if (siz >= k)
                {
                    ll lo, hi;
                    lo = (--ls.end())->first;
                    while (siz > k)
                    {
                        siz--;
                        auto it = rs.begin();
                        ll y = it->second;
                        ls.erase(ls.find({l[y], y}));
                        rs.erase(rs.find({r[y], y}));

                    }
                    hi = (rs.begin())->first;
                    ans = max(ans, hi - lo + 1);
                }
            }
            if (ans == 0)
            {
                cout << 0 << "\n";
                fo(i, 1, k)cout << i << " ";
                cout << "\n";
            }
            else
            {
                ls.clear();
                rs.clear();
                vll ansvec;
                for (auto x : points)
                {
                    for (auto y : removals[x])
                    {
                        if (ls.find({l[y], y}) != ls.end())
                        {   
                            ls.erase(ls.find({l[y], y}));
                            rs.erase(rs.find({r[y], y}));
                        }
                    }
                    for (auto y : insertions[x])
                    {
                        ls.insert({l[y], y});
                        rs.insert({r[y], y});
                    }
                    ll siz = sz(ls);
                    if (siz >= k)
                    {
                        ll lo, hi;
                        lo = (--ls.end())->first;
                        while (siz > k)
                        {
                            siz--;
                            auto it = rs.begin();
                            ll y = it->second;
                            ls.erase(ls.find({l[y], y}));
                            rs.erase(rs.find({r[y], y}));

                        }
                        hi = (rs.begin())->first;
                        if (hi - lo + 1 == ans)
                        {
                            ll X, Y;
                            X = (--ls.end())->second;
                            Y = (rs.begin())->second;
                            ansvec.pb(X);
                            if (X != Y)ansvec.pb(Y);
                            for (auto xx : ls)
                            {
                                if (xx.second == X or xx.second == Y)continue;
                                if (sz(ansvec) == k)break;
                                ansvec.pb(xx.second);
                            }
                            break;
                        }
                    }
                }
                sort(all(ansvec));
                cout << ans << "\n";
                for (auto x : ansvec)cout << x << " ";
                cout << "\n";

            }
        }
    }
    return 0;
}






