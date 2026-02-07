#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<int> b(n), k(n), d(n), c(n);
    for (auto &u: b) {
        std::cin >> u;
    }

    for (auto &u: k) {
        std::cin >> u;
    }

    std::vector<std::pair<int, int>> sr(n);
    for (auto &u: d) {
        std::cin >> u;
    }

    for (auto &u: c) {
        std::cin >> u;
    }

    for (int i = 0; i < n; ++i) {
        sr[i] = {d[i], c[i]};
    }

    std::sort(b.begin(), b.end());
    std::sort(k.begin(), k.end());
    std::sort(sr.begin(), sr.end());

    for (int i = 0; i < n; ++i) {
        std::tie(d[i], c[i]) = sr[i];
    }

    int64_t res = 0;
    auto Get = [&](int cnt) {
        int j = 0, jj = 0;
        int64_t ans = 0;

        if (cnt == 0) {
            return ans;
        }

        if (cnt > n || cnt < 0) {
            return ans - 1;
        }

        std::multiset<int> st;
        std::multiset<std::pair<int, int>> st2;
        for (int i = n - cnt; i < n; ++i) {
            while (j < n && b[j] <= k[i]) {
                st.emplace(b[j++]);
            }

            while (jj < n && d[jj] <= k[i]) {
                st2.emplace(c[jj], d[jj]);

                jj++;
            }

            while (st2.size() && (st.empty() || st2.rbegin()->second < *st.begin())) {
                st2.erase(--st2.end());
            }

            if (st2.size() && st.size()) {
                ans += st2.rbegin()->first;

                st.erase(--st.upper_bound(st2.rbegin()->second));
                st2.erase(--st2.end());
            } else {
                ans = -1;
                break;
            }
        }

        return ans;
    };

    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = l + r >> 1;

        int64_t ans = Get(m), ans2 = Get(m + 1);

        res = std::max({res, ans, ans2});
        if (ans2 == -1 || ans >= ans2) {
            r = m;
        } else {
            l = m;
        }
    }

    std::cout << res << '\n';
    return 0;
}
