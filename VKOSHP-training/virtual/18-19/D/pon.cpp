#include "bits/stdc++.h"
#define int long long
#define sigma signed
#define pii pair<int, int>
#define fr first
#define sc second
#define pb push_back
using namespace std;
const int N = 1e6 + 7;
void test_case() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	map<pii, bool> mp;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		
		if (mp[{u, v}]) continue;
		
		g[u].pb(v);
		g[v].pb(u);
		
		mp[{u, v}] = true;
	}
	
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
        assert(g[i].size() <= n - 1);

		if (g[i].size() < n - 1) {
			a[i] = 1;
			
			int c = 3;
			for (auto u: g[i])
				a[u] = c++;
			
            int cnt = 0;
			for (int j = 1; j <= n; ++j)
				if (a[j] == 0)
					a[j] = (cnt == 0 ? 2 : c++), cnt++;
			
			break;
		}
	}
	
	if (a[1] == 0) {
		cout << "NO\n";
		
		exit(0);
	}
	
	cout << "YES\n";
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " \n"[i == n];
		
	for (int i = 1; i <= n; ++i)
		cout << (a[i] == 1 ? 2 : a[i]) << " \n"[i == n];
}

sigma main() {
	int t = 1;
	while (t--) test_case();
}
