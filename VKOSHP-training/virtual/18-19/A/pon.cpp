#include "bits/stdc++.h"
#define int long long
#define sigma signed
#define pii pair<int, int>
#define fr first
#define sc second
#define pb push_back
using namespace std;
const int N = 1e6 + 7;
int a[N];
sigma main() {
	int n, mx = 0;
	cin >> n;a
	vector <pii> pon;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		int cntmx = 0;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			cntmx = max(cntmx, x);
			mx = max(mx, x);
		}
		pon.pb({m, cntmx});
	}
	int ans = 0;
	for (auto j: pon) ans += (mx - j.sc) * j.fr;
	cout << ans << '\n';
}
