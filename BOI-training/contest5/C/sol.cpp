/**
 *    author:  feev1x
 *    created: 16.09.2025 12:26:03
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    int cnt0 = 0;
    std::vector<std::pair<int, int>> ans;
    std::vector<std::vector<std::pair<int, int>>> g(n + 1), adj(n + 1);
    std::vector<int> vis(n + 1);

    auto Inv = [&](int x) {
        if (x > n)
            return x - n;

        return x + n;
    };

    std::vector<bool> used(n + 1);
    int res = 0;

    std::set<int> st;
    for (int i = 1; i <= m; ++i) {
        int b, t; std::cin >> b >> t;

        if (!t && !b)
            cnt0++;
        else {
            if (t != b) {
                g[t].emplace_back(b, i);
                adj[b].emplace_back(t, i);
            }
        }
    }

    for (auto [v, j]: g[0]) {
        int u = v;

        cnt0++;
        while (g[u].size()) {
            cnt0--;

            int cnt = 0, cnt2 = 0;

            for (auto [to, i]: g[u])
                cnt += !!to;

            for (auto [to, i]: adj[u])
                cnt2 += !!to;

            used[v] = true;

            assert(cnt < 2);
            if (cnt == 0) {
                vis[u]++;

                assert(cnt2 < 3);

                if (cnt2 <= 1)
                    cnt0++;

                if (cnt2 == 2)
                    if (vis[u] < cnt2)
                        cnt0++;

                break;
            }

            cnt0++;

            for (auto [to, i]: g[u])
                if (to) {
                    ans.emplace_back(i, j);

                    j = i;
                    u = to;
                }

            
        }
    }

    std::set<int> st;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0, cnt2 = 0;

        for (auto [to, j]: adj[i])
            cnt += !!to;

        for (auto [to, j]: g[i])
            cnt2 += !!to;

        if (cnt == 2 && vis[i] == 1) {
            st.emplace(i);
            used[i] = false;
        }

        if (cnt == 1 && !used[i] && !cnt2) {
            st.emplace(i);
            used[i] = false;
        }
    }

    while (st.size()) {
        int v = *st.begin();

        st.erase(st.begin());

        if (!cnt0) {
            std::cout << "-1\n";
            continue;
        }

        int u = v;

        vis[v]++;
        used[v] = true;
        while (adj[u].size()) {
            cnt0--;

            used[u] = true;
            for (auto [to, j]: adj[u])
                if (to && !used[to])
                    u = to;
            
            cnt0++;
        }

        while (true) {
            cnt0--;

            used[u] = true;
            for (auto [to, j]: g[u])
                if (to && !used[to])
                    u = to;

            if (used[u])
                break;

            cnt0++;
        }

        cnt0++;
        vis[u]++;

        int cnt = 0;
        for (auto [to, j]: adj[u])
            cnt += !!to;

        if (vis[u] >= cnt) {
            cnt0--;

            st.erase(u);
        } else
            st.emplace(u);
    }

    for (int i = 1; i <= n; ++i) {
        int cnt = 0, cnt2 = 0;

        for (auto [to, j]: adj[i])
            cnt += !!to;

        for (auto [to, j]: g[i])
            cnt2 += !!to;

        if (cnt2 == 2 && vis[i] == 0) {
            int u = g[i][0].first, v = g[i][1].first;

            while (g[u].
        }

        }
    }
    return 0;
}
