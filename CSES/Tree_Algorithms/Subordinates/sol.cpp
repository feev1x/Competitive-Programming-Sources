#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1);
    for (int i = 2; i <= n; ++i) {
        int v;
        cin >> v;
        g[v].emplace_back(i);
    }
    vector<int> sz(n + 1);
    vector<bool> used(n + 1);
    function<void(int)> dfs = [&](int v) -> void {
        if (used[v]) return;
        used[v] = true;
        for (auto to: g[v]) {
            dfs(to);
            sz[v] += sz[to] + 1;
        }
    };
    dfs(1);
    for (int i = 1; i <= n; ++i) cout << sz[i] << ' ';
    cout << '\n';
}
