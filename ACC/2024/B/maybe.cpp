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

void solve() {
	int n; cin >> n;
	
	int res = 0;
	
	cout << fixed << setprecision(10);
	
	for(int i = 1; i <= n; i++) {
		res += (int)log2(i);
		cout << log2(i) << ' ';
	}
	
	cout << fixed << setprecision(10) << res << nl;
	
	cout << (res <= 2 * n ? "YES" : "NO") << nl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  solve();
}
