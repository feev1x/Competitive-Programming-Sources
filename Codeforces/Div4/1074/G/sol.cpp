#include <bits/stdc++.h>

#define int int64_t

constexpr int N = 1e6 + 5;

std::vector<int> cnt(N);

inline void solve() {
    int n; std::cin >> n;

    std::vector<std::vector<int>> a(n);

    int64_t sum = 0, all = 0;
    for (auto &u: a) {
        int l; std::cin >> l;

        all += l;
        u.resize(l);
        for (auto &v: u) {
            std::cin >> v;
            cnt[v]++;
        }

        sum += l * (n - 2);
    }

    int64_t res = 0;
    for (auto v: a) {
        int l = v.size();
        std::vector<int> c(l + 2);
        for (auto u: v) {
            if (u <= l + 1) {
                c[u]++;
            }

            cnt[u]--;
        }

        int64_t mex = 0;
        for (int i = 0; i <= l + 1; ++i) {
            if (!c[i]) {
                mex = i;
                break;
            }
        }

        int64_t cn = sum - l * (n - 2) + all - cnt[mex] - l, gv = l - mex;
        for (int i = 0; i < mex; ++i) {
            if (c[i] > 1) {
                gv++;
            }
        }

        cn += gv * (n - 1);

        res += cn * mex;

        int64_t nmex = mex + 1;
        for (int i = mex + 1; i <= l + 1; ++i) {
            if (!c[i]) {
                nmex = i;
                break;
            }
        }

        res += nmex * cnt[mex];

        for (int64_t i = 0; i < mex; ++i) {
            if (c[i] == 1) {
                res += (n - 1) * i;
            }
        }

        for (auto u: v) {
            cnt[u]++;
        }
    }

    for (auto u: a) {
        for (auto v: u) {
            cnt[v]--;
        }
    }

    std::cout << res << '\n';
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
