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
	int t, n, a, b, k;
	cin >> t >> n >> a >> b >> k;
	int cnt = ((n + 1) / 2) * a + (n / 2) * b;
	cout << min(t, cnt / k) << '\n';
}

sigma main() {
	int t = 1;
	while (t--) test_case();
}
