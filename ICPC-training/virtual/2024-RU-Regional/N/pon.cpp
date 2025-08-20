#include <bits/stdc++.h>

#define int long long
#define sigma signed
#define pb push_back
#define ar array

using namespace std;

const int N = 1e6 + 7;

void solve() {
	int n; cin >> n;
	
	ar<int, 26> aa;
    
    fill (aa.begin(), aa.end(), 0);
	
	vector <ar<int, 26>> bro{aa};
	std::vector<bool> stop{false};
	
	string s;
	
	for (int i = 0; i < n; i++) {
		string l; cin >> l;
		
		if (!i) s = l;
			
		int cur = 0;		
				
		for (auto j: l) {
			if (!bro[cur][j - 'a']) bro[cur][j - 'a'] = bro.size(), bro.pb(aa), stop.pb(false);
			cur = bro[cur][j - 'a'];
		}
		
		stop[cur] = true;
	}
	
	int ans = 0, cur = 0;
	
	bool tab = false;
	
	for (auto j: s) {
		int cnt = 0; 
		
		for (int i = 0; i < 26; i++) cnt += (bro[cur][i] > 0);
		
		assert(cnt);
		
		if (cnt > 1 || stop[cur]) ans++, tab = false;
		else ans += !tab, tab = true;
		
		cur = bro[cur][j - 'a'];
	}
	
	cout << ans << '\n';
}

sigma main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}
