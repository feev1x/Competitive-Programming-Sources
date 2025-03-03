/**
 *    author:  feev1x
 *    created: 26.02.2025 21:21:52
**/
#include <bits/stdc++.h>

using segments = std::vector<std::array<int, 4>>;

struct DsuRb {
    std::vector<int> p, sz;
    std::stack<std::pair<int, int>> upd;
    int n, cnt_comp;

    DsuRb(int _n) : n(_n), cnt_comp(n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

        iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return p[v] == v ? v : get(p[v]);
    }

    inline bool unite(int u, int v) {
        u = get(u), v = get(v);

        if (u != v) {
            if (sz[u] > sz[v]) {
                std::swap(u, v);
            }

            cnt_comp--;
            p[u] = v;
            sz[v] += sz[u];

            upd.emplace(u, v);

            return true;
        }

        return false;
    }

    inline void roll_back() {
        if (upd.empty()) {
            return;
        }

        auto [u, v] = upd.top();

        upd.pop();

        cnt_comp++;
        p[u] = u;
        sz[v] -= sz[u]; 
    }

    inline void roll_back(int cnt) {
        while (cnt-- && upd.size()) {
            roll_back();
        }
    }
};

int main() {
    std::freopen("connect.in", "r", stdin);
    std::freopen("connect.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    if (!q) {
        exit(0);
    }

    std::vector<std::pair<int, int>> qq(q);

    std::vector<int> res;
    std::vector<bool> type(q);

    int _t = 0;
    for (auto &[u, v]: qq) {
        char c; std::cin >> c;

        if (c == '?') {
            type[_t] = true;
        } else {
            std::cin >> u >> v;

            if (u > v) {
                std::swap(u, v);
            }
        }

        _t++;
    }

    DsuRb d(n);

    auto Dnc = [&](auto &&self, int l, int r, const segments &s) -> void {
        segments ss;

        int cnt = 0;
        for (const auto &[_l, _r, u, v]: s) {
            if (l > _r || _l > r) {
                continue;
            }

            if (_l <= l && r <= _r) {
                cnt += d.unite(u, v);
            } else {
                ss.push_back({_l, _r, u, v});
            }
        }

        if (l == r) {
            if (type[l]) {
                res.emplace_back(d.cnt_comp);
            }
        } else {
            int m = l + r >> 1;

            self(self, l, m, ss);
            self(self, m + 1, r, ss);
        }

        d.roll_back(cnt);
    };

    segments s;

    _t = 0;
    std::map<std::pair<int, int>, int> mp;
    for (const auto &[u, v]: qq) {
        if (u && v) {
            if (mp.count({u, v})) {
                s.push_back({mp[{u, v}], _t - 1, u, v});

                mp.erase({u, v});
            } else {
                mp[{u, v}] = _t;
            }
        }

        _t++;
    }

    for (const auto &[key, val]: mp) {
        const auto &[u, v] = key;

        s.push_back({val, q, u, v});
    }

    Dnc(Dnc, 0, q - 1, s);

    for (const auto &u: res) {
        std::cout << u << '\n';
    }
    return 0;
}
