#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define nemeshay ios_base::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
#define int long long
#define sigma signed
#define ar array
#define fr first 
#define sc second
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statitstics_node_update>
using namespace __gnu_pbds; 
using namespace std;
const int N = 1e2 + 2;
int a[N][N];
void test_case() {
	int n, m, k, b;
	cin >> n >> m >> k >> b;
	k++;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
	auto check = [&](int ind) {
		for (int i = 1; i <= m; i++) {
			multiset <int> pon;
			int constcnt = 0, constsum = 0;
			for (int j = i; j <= m; j++) {
				constcnt++, constsum += a[ind][j]; 
				if (constcnt > k) break;
				for (int indi = ind - 1; indi >= 1; indi--) pon.insert(a[indi][j]);
				int cnt = constcnt, sum = constsum;
				for (auto j: pon) {
					if (cnt == k) break;
					sum += j;
					cnt++;
				}
				if (cnt == k && sum <= b) return 1; 
			}
		}
		return 0;
	};
	int l = 1, r = n;
	while (r - l > 1) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid;
	}
	if (check(l)) cout << l << '\n';
	else cout << r << '\n';
}
sigma main() {
	nemeshay
	int t = 1;
	while (t--) test_case();
}
