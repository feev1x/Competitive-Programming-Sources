/**
 *    author:  feev1x
 *    created: 25.03.2025 21:58:48
**/
#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void add(int r, int x) {
        for (; r <= n; r += r & -r) {
            add_self(p[r], x);
        }
    }

    inline int get(int r) {
        int res = 0;

        for (; r > 0; r -= r & -r) {
            add_self(res, p[r]);
        }

        return res;
    }

    inline int get(int l, int r) {
        int res = get(r) - get(l - 1);

        if (res < 0) {
            res += MOD;
        }

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m, d; std::cin >> n >> m >> d;

        Bit old1(m), old2(m);        
        std::vector<std::string> s(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> s[i];

            s[i] = " " + s[i];
        }

        for (int i = 1; i <= m; ++i) {
            if (s[n][i] == 'X') {
                old1.add(i, 1);
            }
        }

        for (int i = 1; i <= m; ++i) {
            if (s[n][i] == 'X') {
                int l = std::max(1, i - d), r = std::min(m, i + d);

                old2.add(i, (old1.get(l, r) - old1.get(i, i) + MOD) % MOD);
            }
        }

        for (int j = n - 1; j >= 1; --j) {
            Bit new1(m), new2(m);

            for (int i = 1; i <= m; ++i) {
                if (s[j][i] == 'X') {
                    int l = std::max(1, i - d + 1), r = std::min(m, i + d - 1);

                    new1.add(i, (old1.get(l, r) + old2.get(l, r)) % MOD);
                }
            }

            for (int i = 1; i <= m; ++i) {
                if (s[j][i] == 'X') {
                    int l = std::max(1, i - d), r = std::min(m, i + d);

                    new2.add(i, (new1.get(l, r) - new1.get(i, i) + MOD) % MOD);
                }
            }

            old1 = new1;
            old2 = new2;
        }

        std::cout << (old1.get(1, m) + old2.get(1, m)) % MOD << '\n';
    }
    return 0;
}
