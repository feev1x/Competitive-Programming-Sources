#include "bits/stdc++.h"

#define int long long
#define sigma signed 
#define pb push_back 

using namespace std;

sigma main() {
	string s; cin >> s;
	int ans = 1, cnt = 1;
	s = '$' + s;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) cnt++;
		else cnt = 1;
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}
