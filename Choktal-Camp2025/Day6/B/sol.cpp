/**
 *    author:  feev1x
 *    created: 06.07.2025 11:15:13
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;

    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::map<int, std::map<int, std::map<int, int>>> mp;
        std::vector<std::vector<std::pair<int, int>>> g(n + 1);
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
        std::vector<std::array<int, 3>> e(m + 1);
        for (int i = 1; i <= m; ++i) {
            int u, v, w; std::cin >> u >> v >> w;

            mp[w][u][v] = i;
            e[i] = {u, v, w};
            g[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        std::vector<bool> getout(n + 1);
        while (true) {
            int _t = 0;
            bool flag = false;
            std::vector<int> tin(n + 1), low(n + 1), gt(n + 1), scc(n + 1);
            std::vector<bool> ins(n + 1), tw(n + 1);
            std::stack<int> stk;

            while (true) {

                bool ch = false;
                for (int v = 1; v <= n; ++v) {
                    if (getout[v]) {
                        continue;
                    }

                    for (auto [fr, w]: adj[v]) {
                        if (getout[fr]) {
                            continue;
                        }

                        if (gt[v] == 0) {
                            gt[v] = w;
                            ch = true;
                        } else if (gt[v] != w && !tw[v]) {
                            tw[v] = true;
                            ch = true;
                        }
                    }
                }

                if (!ch) {
                    break;
                }
            }

            auto Tj = [&](auto &&self, int v) -> void {
                if (getout[v]) {
                    return;
                }

                tin[v] = ++_t;

                ins[v] = true;
                stk.emplace(v);
                for (auto [to, w]: g[v]) {
                    if (getout[to]) {
                        continue;
                    }

                    if (!tw[v] && (gt[v] == w || gt[v] == 0)) {
                        continue;
                    }

                    if (!tin[to]) {
                        self(self, to);

                        low[v] = std::min(low[v], low[to]);
                    } else if (ins[to]) {
                        low[v] = std::min(low[v], tin[to]);
                    }
                }

                if (low[v] == tin[v]) {
                    int x;

                    if (stk.top() == v) {
                        getout[v] = true;

                        flag = true;
                        ins[v] = false;
                        stk.pop();

                        return;
                    }

                    do {
                        x = stk.top(), ins[x] = false;
                        stk.pop();
                    } while (x != v);
                }
            };

            for (int v = 1; v <= n; ++v) {
                if (!tin[v] && !getout[v]) {
                    Tj(Tj, v);
                }
            }

            if (!flag) {
                break;
            }
        }

        std::vector<int> gt(n + 1), scc(n + 1);
        std::vector<bool> tw(n + 1);
        while (true) {

            bool ch = false;
            for (int v = 1; v <= n; ++v) {
                if (getout[v]) {
                    continue;
                }

                for (auto [fr, w]: adj[v]) {
                    if (getout[fr]) {
                        continue;
                    }

                    if (gt[v] == 0) {
                        gt[v] = w;
                        ch = true;
                    } else if (gt[v] != w && !tw[v]) {
                        tw[v] = true;
                        ch = true;
                    }
                }
            }

            if (!ch) {
                break;
            }
        }

        bool flag = false;
        {
            int _t = 0;
            std::vector<int> tin(n + 1), low(n + 1);
            std::vector<bool> ins(n + 1), tw(n + 1);
            std::stack<int> stk;
            auto Tj = [&](auto &&self, int v) -> void {
                if (getout[v]) {
                    return;
                }

                tin[v] = ++_t;

                ins[v] = true;
                stk.emplace(v);
                for (auto [to, w]: g[v]) {
                    if (getout[to]) {
                        continue;
                    }

                    if (!tw[v] && (gt[v] == w || gt[v] == 0)) {
                        continue;
                    }


                    if (!tin[to]) {
                        self(self, to);

                        low[v] = std::min(low[v], low[to]);
                    } else if (ins[to]) {
                        low[v] = std::min(low[v], tin[to]);
                    }
                }

                if (low[v] == tin[v]) {
                    int x;

                    if (stk.top() == v) {
                        getout[v] = true;

                        ins[v] = false;
                        stk.pop();

                        return;
                    }

                    do {
                        x = stk.top(), ins[x] = false;
                        flag = true;
                        scc[x] = v;
                        stk.pop();
                    } while (x != v);
                }
            };

            for (int v = 1; v <= n; ++v) {
                if (!tin[v] && !getout[v]) {
                    Tj(Tj, v);
                }
            }
        }
            while (true) {

                bool ch = false;
                for (int v = 1; v <= n; ++v) {
                    if (getout[v]) {
                        continue;
                    }

                    for (auto [fr, w]: adj[v]) {
                        if (getout[fr]) {
                            continue;
                        }

                        if (gt[v] == 0) {
                            gt[v] = w;
                            ch = true;
                        } else if (gt[v] != w && !tw[v]) {
                            tw[v] = true;
                            ch = true;
                        }
                    }
                }

                if (!ch) {
                    break;
                }
            }

        int _t = 0, val = 0;
        std::vector<int> tin(n + 1), low(n + 1), go(n + 1);
        std::vector<bool> ins(n + 1), used(m + 1);
        std::stack<int> res;
        auto Dfs = [&](auto &&self, int v) -> void {
            if (getout[v]) {
                return;
            }

//            std::cout << v << '\n';

            tin[v] = ++_t;

            ins[v] = true;
            for (auto [to, w]: g[v]) {
                if (getout[to] || scc[v] != scc[to] || used[mp[w][v][to]]) {
                    continue;
                }

                if (!tw[v] && (gt[v] == w || gt[v] == 0)) {
                    continue;
                }


                if (!tin[to]) {
                    if (!go[v])
                        go[v] = w;
                    res.emplace(mp[w][v][to]);
                    used[mp[w][v][to]] = true;
                    self(self, to);

                    if (val) {
                        return;
                    }
                    res.pop();
                } else if (ins[to] && go[to] != w) {
                    val = to;
                    res.emplace(mp[w][v][to]);
                    return;
                } else if (ins[to] && go[to] == w) {
                    if (!go[v])
                        go[v] = w;

                    res.emplace(mp[w][v][to]);
                    used[mp[w][v][to]] = true;
                    self(self, to);
                    if (val) {
                        return;
                    }
                    res.pop();
                }
            }

            go[v] = 0;
            ins[v] = false;
        };


        for (int v = 1; res.empty() && v <= n; ++v) {
            if (!tin[v] && !getout[v]) {
                Dfs(Dfs, v);
            }
        }

        std::vector<int> ans;
        int v = -1, bad = 0;
        do {
            if (res.empty()) {
                bad = 1;
                break;
            }

            v = res.top();
            res.pop();

            ans.emplace_back(v);
            v = e[v][0];

            if (v == val && e[ans.front()][2] == e[ans.back()][2]) {
                v = -1;
            }
        } while (v != val && val);

        if (ans.size() > 1 && !bad && val) {
            std::reverse(ans.begin(), ans.end());
            std::cout << "YES\n" << ans.size() << ' ';
            for (auto u: ans) {
                std::cout << u << ' ';
            }

            std::cout << '\n';
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
