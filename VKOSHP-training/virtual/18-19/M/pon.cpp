#include "bits/stdc++.h"
#define int long long
#define sigma signed
using namespace std;
const int N = 1e6 + 7;
int a[N];
sigma main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 1, cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1]) cnt = 0;
		cnt++, ans = max(ans, cnt);
	}
	cout << ans << '\n';
}
