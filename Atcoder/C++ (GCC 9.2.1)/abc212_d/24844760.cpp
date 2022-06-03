#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
int main(void) {
	priority_queue<ll, vector<ll>, greater<ll> >pq;
	int q, p;
	ll x;
	ll sum = 0;
	cin >> q;
	rep(qq, q) {
		cin >> p;
		if (p == 1) {
			cin >> x;
			pq.push(x - sum);
		}
		else if (p == 2) {
			cin >> x;
			sum += x;
		}
		else if (p == 3) {
			x = pq.top();
			cout << x + sum << endl;
			pq.pop();
		}
	}
	return 0;
}