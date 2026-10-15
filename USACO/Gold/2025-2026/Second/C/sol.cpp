#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, f; std::cin >> n >> f;
    std::vector<int> a(n), s(f), dis(n, INF), cl(n, -1), tl(n, -1), d(n), idx(n, -1);
    std::vector<std::set<int>> gt(n);
    std::vector<std::array<int, 20>> anc(n);
    for (auto &u: anc) for (auto &v: u) v = -1;
    std::vector<std::map<int, bool>> bad(n);
    std::vector<std::vector<int>> cyc(n);
    std::vector<std::set<int>> ct(n);
    std::vector<bool> used(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i], --a[i];
    std::queue<int> q;
    for (auto &u: s) std::cin >> u, dis[u - 1] = 0, q.emplace(u - 1);
    while (q.size()) {
        int v = q.front(); q.pop();
        if (dis[a[v]] > dis[v] + 1) dis[a[v]] = dis[v] + 1, q.emplace(a[v]);
    }
    std::vector<int> back(n);
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        int u = i;
        while (!used[u]) used[u] = true, back[a[u]] = u, u = a[u];
        if (tl[u] == -1) {
            int lead = u;
            while (cl[u] == -1) {
                idx[u] = cyc[lead].size();
                gt[u].emplace(0);
                cyc[lead].emplace_back(u);
                ct[lead].emplace(idx[u]);
                cl[u] = lead, tl[u] = u, u = a[u];
            }
        }
        u = i;
        while (tl[u] == -1) back[a[u]] = u, u = a[u];
        while (u != i) tl[back[u]] = tl[u], d[back[u]] = d[u] + 1, gt[tl[u]].emplace(d[u] + 1), u = back[u];
    }
    for (auto u: s) {
        --u;
        gt[tl[u]].erase(d[u]);
        cl[u] = cl[tl[u]];
        int sz = cyc[cl[u]].size();
        bad[cl[u]][cyc[cl[u]][(idx[tl[u]] + (sz - (d[u] % sz))) % sz]] = true;
        ct[cl[u]].erase((idx[tl[u]] + (sz - (d[u] % sz))) % sz);
    }
    for (int i = 0; i < n; ++i) {
        std::vector<int> del;
        for (auto u: gt[i]) {
            cl[i] = cl[tl[i]];
            int sz = cyc[cl[i]].size();
            if (bad[cl[i]][cyc[cl[i]][(idx[tl[i]] + (sz - (u % sz))) % sz]]) del.emplace_back(u);
        }
        for (auto u: del) gt[i].erase(u);
    }
    auto Get = [&](int i, int x) {
        int sz = cyc[cl[i]].size();
        if (ct[cl[i]].empty()) return -1;
        auto it = ct[cl[i]].lower_bound(idx[i] - x);
        int res = -1;
        if (it == ct[cl[i]].end() || *it > idx[i]);
        else res = idx[i] - *it;
        if (idx[i] - x < 0) {
            it = ct[cl[i]].lower_bound((idx[i] - x) + sz);
            if (it == ct[cl[i]].end());
            else res = std::max(res, sz - *it + idx[i]);
        }
        return res;
    };
    for (int i = 0; i < n; ++i) {
        if (dis[i] == INF) {
            std::cout << "-2\n";
            continue;
        }
        if (idx[i] == -1) {
            int l = d[i], r = d[i] + dis[i] - 1;
            auto it = gt[tl[i]].upper_bound(r);
            if (gt[tl[i]].empty() || it == gt[tl[i]].begin() || *(--it) < l) {
                std::cout << "-1\n";
                continue;
            }
            std::cout << (*it) - l << '\n';
        } else {
            int sz = cyc[cl[i]].size();
            int x = (dis[i] - 1) / sz, md = (dis[i] - 1) % sz;
            if (Get(i, md) != -1) {
                std::cout << Get(i, md) + x * sz << '\n';
                continue;
            }
            if (x > 0 && Get(i, std::min(dis[i] - 1, md + sz)) != -1) {
                std::cout << Get(i, std::min(dis[i] - 1, md + sz)) + (x - 1) * sz << '\n';
                continue;
            }
            std::cout << "-1\n";
        }
    }
    return 0;
}
