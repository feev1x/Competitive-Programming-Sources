#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

constexpr int MOD = 998244353;
constexpr int64_t INF = 1e18;

using namespace __gnu_pbds;

using ordered_set = tree<std::pair<int64_t, int>, null_type, std::less<std::pair<int64_t, int>>, rb_tree_tag, tree_order_statistics_node_update>;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

struct Bit {
    std::vector<int64_t> p;
    int n;

    Bit(int n) : n(n) {
        p.resize(n + 1);
    }

    inline void update(int r, int64_t x) {
        r++;

        for (; r <= n; r += r & -r) {
            p[r] += x;
        }
    }

    inline int64_t get(int r) {
        r++;

        int64_t res = 0;

        for (; r > 0; r -= r & -r) {
            res += p[r];
        }

        return res;
    }

    inline int64_t get(int l, int r) {
        if (r < l) {
            return 0ll;
        }

        return get(r) - get(l - 1);
    }
};

inline void solve() {
    int m; std::cin >> m;

    std::vector<int64_t> a(m), pos(m);
    std::vector<std::pair<int64_t, int>> b;
    int idx = 0;
    for (auto &u: a) {
        std::cin >> u;

        b.emplace_back(u, idx++);
    }

    std::sort(b.begin(), b.end());

    for (int i = 0; i < m; ++i) {
        pos[b[i].second] = i;
    }

    Bit bit(m);
    ordered_set st;

    int64_t sum = 0;

    auto Calc = [&](int i) -> std::pair<int64_t, int> {
        if (i < 0 || i >= (int)st.size()) {
            return std::pair{INF, 0};
        }

        int64_t val = 0;
        int dir = 0;
        if (i >= 1) {
            auto itL = st.find_by_order(i - 1);
            auto it = st.find_by_order(i);
            val = (int64_t)(i - 1) * (itL->first) - bit.get(pos[itL->second] - 1);
        }

        if (i + 1 < st.size()) {
            auto itR = st.find_by_order(i + 1);
            auto it = st.find_by_order(i);
            int64_t vl = bit.get(pos[itR->second] + 1, m - 1) - ((int64_t)st.size() - i - 2) * (itR->first);
            if (i == 1 && st.size() == 4) {
//                std::cout << "UEBAN " << - ((int64_t)st.size() - i - 2) * (it->first) << '\n';
            }

            if (vl >= val) {
                val = vl;
                dir = 1;
            }
        }

        return std::pair{val, dir};
    };

    for (int i = 0; i < m; ++i) {
        sum += a[i];
        st.insert({a[i], i});
        bit.update(pos[i], a[i]);

        if (i < 2) {
            continue;
        }


        int l = 0, r = i + 1, ans = -1;
        while (l <= r) {
            int mid = l + r >> 1;

            if (Calc(mid).second == 1) {
                l = mid + 1, ans = mid;
            } else {
                r = mid - 1;
            }
        }

//        std::cout << m << ' ' << i << '\n';
        std::cout << divide(std::min(Calc(ans).first, Calc(ans + 1).first) % MOD, i - 1) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}
