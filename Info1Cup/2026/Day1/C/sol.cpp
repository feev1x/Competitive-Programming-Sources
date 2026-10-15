#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> ord(n);
    for (auto &u: ord) {
        std::cin >> u;
    }

    std::vector<int> ans(n - 2);
    std::vector<bool> used(n + 1);
    std::set<std::pair<int, int>> st;
    std::vector<std::set<int>> g(n + 1);
    std::vector<std::array<int, 3>> t;
    for (int i = 0; i < n - 2; ++i) {
        int x, y, z; std::cin >> x >> y >> z;

        t.push_back({x, y, z});

        g[x].emplace(i);
        g[y].emplace(i);
        g[z].emplace(i);
    }

    g[1].clear();
    g[n].clear();

    for (int i = 2; i < n; ++i) {
        st.emplace(g[i].size(), i);
    }

    int res = 1;
    used[1] = used[n] = true;
    while (st.size()) {
        int val = st.begin()->second;

        st.erase(st.begin());

        if (g[val].empty()) {
            continue;
        }

        used[val] = true;
        
        int tr = -1, c = -1;

        int num = 1;
        for (auto u: g[val]) {
            int cnt = g[t[u][0]].size() + g[t[u][1]].size() + g[t[u][2]].size();

            if (g[t[u][0]].size() == 1 && t[u][0] != val || g[t[u][1]].size() == 1 && t[u][1] != val || g[t[u][2]].size() == 1 && t[u][2] != val) {
                continue;
            }

            if (c == cnt) {
                num++;

                if (rand() % 2 == 0) {
                    tr = u;
                }
            }

            if (tr == -1 || c > cnt) {
                num = 1;
                c = cnt;
                tr = u;
            }
        }

        res = mul(res, num);

        for (auto u: t[tr]) {
            bool flag = st.find({g[u].size(), u}) != st.end();

            if (flag) {
                st.erase({g[u].size(), u});
                g[u].erase(tr);
                st.emplace(g[u].size(), u);
            }
        }

        ans[tr] = val;
    }

    for (int i = 0; i < n - 2; ++i) {
        std::cout << ans[i] << " \n"[i == n - 3];
    }

    std::cout << res << "\n";
}

int main() {
    srand(time(NULL));
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }
}

