/**
 *    author:  feev1x
 *    created: 07.02.2025 17:01:02
**/
#include <bits/stdc++.h>

inline void umax(int &a, int b) {
    if (a < b) {
        a = b;
    }
}

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline int get(int r) {
        int ans = 0;

        for (; r > 0; r -= r & -r) {
            umax(ans, p[r]);
        }

        return ans;
    }

    inline void modify(int r, int x) {
        for (; r <= n; r += r & -r) {
            umax(p[r], x);
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n);
        for (auto &u: a) {
            std::cin >> u;
        }

        auto b = a;

        std::sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());


        std::vector<int> l(n + 1), r(n + 1), ans(n + 1), ap(n + 1);
        for (auto &u: a) {
            u = 1 + std::lower_bound(b.begin(), b.end(), u) - b.begin();

            assert(u <= n);
        }

        for (int i = 0; i < n; ++i) {
            int u = a[i];

            if (ap[u]) {
                r[u] = i;
            } else {
                l[u] = i;
                r[u] = i;
            }

            ap[u]++;
        }

        Bit bt(n);
        for (int i = 0; i < n; ++i) {
            if (l[a[i]] == i) {
                ans[a[i]] = bt.get(a[i] - 1) + ap[a[i]];
            }

            if (r[a[i]] == i) {
                bt.modify(a[i], ans[a[i]]);
            }
        }

        std::cout << *std::max_element(ans.begin(), ans.end()) << '\n';
    }
    return 0;
}
