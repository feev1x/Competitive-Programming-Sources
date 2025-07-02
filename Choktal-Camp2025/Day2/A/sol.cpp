/**
 *    author:  feev1x
 *    created: 02.07.2025 09:14:43
**/
#include <bits/stdc++.h>

inline std::vector<int> z_fun(std::string s) {
    int n = s.size();
    std::vector<int> z(n);

    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = std::min(r - i, z[i - l]);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }

    return z;
}

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void update(int r) {
        for (; r <= n; r += r & -r) {
            p[r]++;
        }
    }

    inline int get(int r) {
        int res = 0;

        for (; r >= 1; r -= r & -r) {
            res += p[r];
        }

        return res;
    }
};
 
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;
 
    std::string s; std::cin >> s;
 
    Bit bit(s.size() + 2);
    std::vector<std::string> a(n + 1);
    std::vector<std::vector<int>> pr(s.size());
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        std::string sm = a[i];
        sm += "$";
        sm += s;
        auto z = z_fun(sm);

        for (int j = 0; j < s.size(); ++j) {
            if (z[j + a[i].size() + 1] == a[i].size()) {
                pr[j].emplace_back(j + a[i].size());
            }
        }
    }


    std::vector<int> l(m + 1), r(m + 1), ans(m + 1);
    std::vector<std::vector<int>> q(s.size());
    for (int i = 1; i <= m; ++i) {
        std::cin >> l[i] >> r[i];

        q[l[i] - 1].emplace_back(i);
    }

    for (int i = s.size() - 1; i >= 0; --i) {
        for (auto u: pr[i]) {
            bit.update(u);
        }

        for (auto idx: q[i]) {
            ans[idx] = bit.get(r[idx]);
        }
    }

    for (int i = 1; i <= m; ++i) {
        std::cout << ans[i] << " \n"[i == m];
    }

    return 0;
}

