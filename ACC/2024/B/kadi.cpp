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
	
	auto ask = [&](int i, int x) {
		cout << "? " << i << ' ' << x << endl;
		char c; cin >> c;
		return c;
	};
	
	vector<int> ans;
	
	int last = 1;
	
	for(int i = 1; i <= n; i++) {
		while( ask(i, last) != '=' ) {
			last++;
		}
		ans.pb(last);
	}
	
	cout << "! ";
	for(auto i : ans) cout << i << ' ';
	cout << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  solve();
}
