#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) { return (int64_t)a * b % MOD; }

inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

inline int mod(int a) { return (a % MOD + MOD) % MOD; }

inline int get(int64_t l, int64_t r) { return mod(mul(mul(r % MOD, (r + 1) % MOD), (MOD + 1) / 2) - mul(mul(l % MOD, (l - 1) % MOD), (MOD + 1) / 2)); }


struct Node { int64_t sum = 0, cnt = 0, psh = 0; };

struct Segtree {
    std::vector<Node> t;
    std::vector<int> a;
    int n;
    Segtree(std::vector<int> a) : a(a), n(a.size()) { t.resize(4 * n); };
    inline void update(int v, int tl, int tr, int64_t d, int64_t b) {
        if (d > tr) return;
        int tm = tl + tr >> 1;
        if (d >= tl) {
            
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::map<int64_t, int64_t> mp;
    std::vector<std::pair<int, int>> q;
    int res = 0;
    int u; std::cin >> u;
    std::vector<std::pair<int64_t, int64_t>> qq(u);
    std::vector<int64_t> a;
    std::vector<int64_t> ans(u);
    for (int i = 0; i < u; ++i) {
        int64_t d, b; std::cin >> d >> b;
        a.emplace_back(d);
        qq[i] = {d, b};
        if (mp.count(d)) q.emplace_back(mp[d], i - 1);
        mp[d] = i;
    }
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    int sz = a.size();
    Segtree st = Segtree(a);
    for (auto [key, val]: mp) {
        if (val == 0) st.add(qq[0].first, qq[0].second);
        else q.emplace_back(val, u - 1);
    }
    auto Rec = [&](auto &&self, int l, int r, std::vector<std::pair<int, int>> q) -> void {
        if (l == r) {
            ans[l] = st.get(0, sz - 1);
            return;
        }
        int m = l + r >> 1;
        {
            std::vector<std::pair<int, int>> new_q;
            int cnt = 0;
            for (auto [u, v]: q) {
                if (u <= l && m <= v) st.add(qq[u].first, qq[u].second), cnt++;
                else new_q.emplace_back(u, v);
            }
            self(self, l, m, new_q);
            while (cnt--) st.roll_back();
        }
        {
            std::vector<std::pair<int, int>> new_q;
            int cnt = 0;
            for (auto [u, v]: q) {
                if (u <= m + 1 && r <= v) st.add(qq[u].first, qq[u].second), cnt++;
                else new_q.emplace_back(u, v);
            }
            self(self, m + 1, r, new_q);
            while (cnt--) st.roll_back();
        }
    }; Rec(Rec, 0, u - 1, q);
    for (auto u: ans) std::cout << u << '\n';
    return 0;
}
