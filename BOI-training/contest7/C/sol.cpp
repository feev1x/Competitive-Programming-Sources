#include <bits/stdc++.h>

std::vector<int> paint(int n, std::vector<std::pair<int,int>> edges, int t) {
    std::vector<int> colors(edges.size());
    if (n == 1)
        return colors;

    std::vector<bool> ue(edges.size());
    std::vector<bool> used(n + 1), left(n + 1);

    std::map<std::pair<int, int>, int> mp;

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < edges.size(); ++i) {
        mp[edges[i]] = i;
        mp[{edges[i].second, edges[i].first}] = i;

        g[edges[i].second].emplace_back(edges[i].first);
        g[edges[i].first].emplace_back(edges[i].second);
    }

    std::queue<int> q;
    q.emplace(t);
    used[t] = true;

    while (q.size()) {
        int v = q.front();

        q.pop();

        for (auto to: g[v]) {
            if (used[to]) {
                if (!ue[mp[{v, to}]]) {
                    colors[mp[{v, to}]] = to > v;
                    ue[mp[{v, to}]] = true;
                }
            } else {
                left[to] = left[v];
                used[to] = true;
                ue[mp[{v, to}]] = true;
                colors[mp[{v, to}]] = to > v;

                q.emplace(to);
            }
        }

        if (v == t)
            left[g[v][0]] = true;
    }

    return colors;
}

int travel(int n, int u, std::vector<std::pair<int,int>> neighbours) {
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    shuffle(neighbours.begin(), neighbours.end(), rng);
    for (auto [v, e]: neighbours)
        if (e == u > v)
            return v;

    assert(false);
}
