#include "bits/stdc++.h"

#define int long long
#define sigma signed 
#define pb push_back 

using namespace std;

const int N = 1e6 + 7, INF = 1e18;

struct node{
	int val = 0, sum = 0, pref = 0, suf = 0;
};

int a[N];
node der[N * 4];

node merge(node l, node r) {
	node ret;
	ret.sum = l.sum + r.sum;
	ret.pref = max({l.pref, l.sum + r.pref, 0ll});
	ret.suf = max({r.suf, r.sum + l.suf, 0ll});
	ret.val = max({l.val, r.val, l.suf + r.pref, 0ll});
	return ret;
}

void build(int v, int l, int r) {
	if (l == r) return der[v] = {std::max(a[l], 0ll), a[l], std::max(a[l], 0ll), std::max(a[l], 0ll)}, void();
	int m = l + r >> 1;
	build (v << 1, l, m);
	build (v << 1 | 1, m + 1, r);
	der[v] = merge(der[v << 1], der[v << 1 | 1]);
}
node get(int v, int l, int r, int ql, int qr) {
	if (l > r) return {0, 0, 0, 0};
	if (l > qr || r < ql) return {0, 0, 0, 0};
	if (ql <= l && r <= qr) return der[v];
	int m = l + r >> 1;
	
	return merge(get(v << 1, l, m, ql, qr), get(v << 1 | 1, m + 1, r, ql, qr));
}
void test_case(){
	int n, k; cin >> n >> k;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	build(1, 1, n);
	
	
	auto lb = [&](int ind) {
		auto check = [&](int l, int r) {
			return (get(1, 1, n, l, r).val < k);
		};
		int l = ind, r = n, ans = -1;
		while (l <= r) {
			int m = l + r >> 1;
			if (check(ind, m)) l = m + 1;
			else r = m - 1, ans = m;
		}
		
		// cout << ans << '\n';
		
		if (ans != -1 && get(1, 1, n, ind, ans).val == k) return ans;
		return -1ll;
	};
	
	auto up = [&](int ind) {
		auto check = [&](int l, int r) {
			return (get(1, 1, n, l, r).val > k);
		};
		int l = ind, r = n, ans = -1;
		while (l <= r) {
			int m = l + r >> 1;
			if (check(ind, m)) r = m - 1;
			else l = m + 1, ans = m;
		}
		
		// cout << ans << '\n';
		
		if (ans != -1 && get(1, 1, n, ind, ans).val == k) return ans;
		return -1ll;
	};
	
	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
		int l = lb(i), r = up(i);
		 // cout << l << ' ' << r << '\n';
		if (l == -1 || r == -1) continue;
		ans += (r - l + 1);
	}
	
	cout << ans << '\n';
}

sigma main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) test_case();
}
