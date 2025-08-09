#include "bits/stdc++.h"
#define int long long
#define sigma signed 
#define pb push_back
#define ar array
#define pii pair<int, int>
#define fr first
#define sc second
using namespace std;
const int N = 1e6 + 7, inf = 1e9 + 7;
int a[9][9], used[9][9];
vector <int> dx{-1, 1, -2, 2}, dy{-1, 1, -2, 2};
sigma main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a[8 - (s[1] - '0') + 1][s[0] - 'a' + 1] = 1;
	}
	vector <ar<ar<int, 2>, 2>> ans;
	auto bfs = [&](int sx, int sy) {
		int dist[9][9];
		pii p[9][9];
		for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) dist[i][j] = inf, p[i][j] = {0, 0};
		dist[sx][sy] = 0;
		queue <ar<int, 3>> pon;
		pon.push({0, sx, sy});
		ar<int, 3> mn = {inf, 0, 0};
		while (pon.size()) {
			auto [c, x, y] = pon.front();
			pon.pop();
			if (a[x][y]) {
				mn = min(mn, {c, x, y});
				continue;
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (abs(dx[i]) == abs(dy[j])) continue;
					int nx = x + dx[i], ny = y + dy[j];
					if (nx > 8 || nx < 1 || ny > 8 || ny < 1 || dist[nx][ny] < c + 1) continue;
					dist[nx][ny] = c + 1, p[nx][ny] = {x, y};
					pon.push({c + 1, nx, ny});
				}
			}
		}
		vector <ar<int, 2>> ok;
		int x = mn[1], y = mn[2];
		a[x][y] = 0;
		while (x && y) {
			ok.pb({x, y});
			int nx = p[x][y].fr, ny = p[x][y].sc;
			x = nx, y = ny;
		}
		reverse (ok.begin(), ok.end());
		for (int i = 0; i < ok.size(); i++) {
			for (int j = i + 1; j < ok.size(); j++) {
				if (used[ok[j][0]][ok[j][1]] || j == ok.size() - 1) {
					for (int k = j; k > i; k--) ans.pb({ok[k], ok[k - 1]});
					i = j - 1;
					break;
				}
			}
		}
		used[sx][sy] = 1;
	};
	int indi = 8, indj = 1;
	while (n--) {
		bfs(indi, indj);
		indj++;
		if (indj > 8) indi--, indj = 1;
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) for (int j = 0; j < 2; j++) cout << char(ans[i][j][1] + 'a' - 1) << 8 - ans[i][j][0] + 1 << (j ? '\n' : '-');
	
}
