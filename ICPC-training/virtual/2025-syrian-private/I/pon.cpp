#include "bits/stdc++.h"

#define int long long
#define sigma signed 
#define pb push_back 

using namespace std;

const int N = 1e6 + 7;

int cnt[N];

sigma main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, x;
	cin >> n >> x;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		val %= x;
		if ((val * ((x - val) % x)) % x == 0) ans += cnt[(x - val) % x];
		cnt[val]++;
	}
	cout << ans << '\n';
}
