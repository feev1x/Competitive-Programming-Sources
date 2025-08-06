#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

template <typename A, typename B>
bool chmin(A &a, const B &b) {
  if(a > b) {
    return a = b, true;
  }
  return false;
}

template <typename A, typename B>
bool chmax(A &a, const B &b) {
  if(a < b) {
    return a = b, true;
  }
  return false;
}
const int N = 1e6 + 7, mod = 1e9 + 7;
int dp[N][(1 << 4)];
void solve() {
	int n; cin >> n;
	
	n /= 2;
	
	
	dp[1][(1 << 0)] = dp[1][(1 << 3)] = 1;
	for (int i = 2; i <= n; i++) {
		for (int mask = 0; mask < (1 << 4); mask++) {
			for (int j = 0; j < 4; j++) {
				dp[i][mask | j] += dp[i - 1][mask];
				dp[i][mask | j] %= mod;
			}
		} 
	}
	int ans = 0;
	for (int mask = 0; mask < (1 << 4); mask++) {
		for (int i = 0; i < 2; i++) {
			if ((mask & (1 << i)) && (mask & (1 << (i + 2)))) {
				ans += dp[n][mask];
				ans %= mod;
				break;
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  solve();
}
