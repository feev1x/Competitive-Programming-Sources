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
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<bool> used(n + 1);
    int cnt = 0;
    function<bool(int)> dfs = [&](int v) -> bool {
        if (used[v]) return false;
        used[v] = true;
        bool flag = true;
        for (auto to: g[v]) {
            if (used[to]) continue;
            if (dfs(to) && flag) {
                flag = false;
                cnt++;
            }
        }
        return flag;
    };
    dfs(1);
    cout << cnt << '\n';
}
