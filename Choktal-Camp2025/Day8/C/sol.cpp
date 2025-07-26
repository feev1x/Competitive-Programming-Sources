/**
 *    author:  feev1x
 *    created: 08.07.2025 10:03:42
**/
#include <bits/stdc++.h>

std::vector<std::vector<int>> g;
std::vector<bool> lv;
std::vector<int> p;
std::vector<int64_t> w;
int n;
int64_t sub4, cnt4;
bool flag = true;

void init(std::vector<int> _p, std::vector<int> _w) {
    p = _p;
    n = p.size();

    g.resize(n);
    w.resize(n);
    lv.resize(n);
    for (int i = 1; i < n; ++i) {
        g[i].emplace_back(p[i]);
        g[p[i]].emplace_back(i);
    }

    for (int i = 0; i < n; ++i) {
        if (i && g[i].size() > 1) {
            sub4 += g[i].size() - 2;
        }

        if (g[i].size() == 1 && (i || n == 1)) {
            cnt4++;
            lv[i] = true;
        }

        w[i] = _w[i];

        if (w[i] != 1) {
            flag = false;
        }
    }
}

long long query(int L, int R) {
    std::vector<long long> dp(n), val(n), dpl(n), dpr(n);
    auto Dfs = [&](auto &&self, int v) -> void {
        if (lv[v]) {
            dp[v] = L * w[v];
            val[v] = L;
            dpl[v] = w[v] * L;
            dpr[v] = w[v] * L;
 
            return;
        }
 
        int64_t val = 0;
 
        for (auto to: g[v]) {
            if (to == p[v]) {
                continue;
            }
 
            self(self, to);
 
            if (dpr[to] - dpl[to] < w[v] * (R - L)) {
                dpl[v] += dpl[to];
                val += L;
            } else {
                dpl[v] += dpr[to];
                val += R;
            }
        }
 
        if (val1 > R) {
            ans += (val1 - R) * w[v];
        }
 
        dpl[v] += (val - L) * w[v];
 
        if (val >= R) {
            dpr[v] = dpl[v];
        } else {
            std::vector<int64_t> sr;
 
            for (auto to: g[v]) {
                if (to == p[v]) {
                    continue;
                }
 
                if (dpr[to] - dpl[to] < w[v] * (R - L)) {
                    sr.emplace_back(to);
                }
            }
 
            std::sort(sr.begin(), sr.end(), [&](int i, int j) {
                return dpr[i] - dpl[i] < dpr[j] - dpl[j];
            });
 
            val += (R - L);
 
 
            while (sr.empty());
            dpr[v] += (dpr[sr.front()] - dpl[sr.front()]);
        }
 
        dpr[v] += (val - R) * w[v];       

        for (auto to: g[v]) {
            if (to == p[v]) {
                continue;
            }

            dp[v] += dp[to];

            val[v] += val[to];
        }

        if (val[v] > R) {
            std::vector<int64_t> sr;

            for (auto to: g[v]) {
                if (to == p[v]) {
                    continue;
                }

                if (dpl[to] - dp[to] < (val[to] - L) * w[v]) {
                    sr.emplace_back(to);
                }
            }

            std::sort(sr.begin(), sr.end(), [&](int i, int j) {
                return dpl[i] - dp[i] < dpl[j] - dp[j];
            });

            for (auto to: sr) {
                if (val[v] - (val[to] - L) <= R) {
                    
                } else {
                    val[v] -= (val[to] - L);
                    dp[v] -= dp[to];
                    dp[v] += dpl[to];
                }
            }

            dp[v] += (val[v] - R) * w[v];
            val[v] = R;
        }
    };

    Dfs(Dfs, 0);

    return dp[0];
}
