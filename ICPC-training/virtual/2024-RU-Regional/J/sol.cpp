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

const int mod = 1e9 + 9;

int binpow(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	int n; cin >> n;
	
	cout << (binpow(2, n + 1) - 2 * (n + 1) % mod + n % mod) % mod << nl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  solve();
}
