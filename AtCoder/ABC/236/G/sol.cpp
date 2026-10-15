#include <bits/stdc++.h>

constexpr int INF = 1e9;

inline void chmin(int &a, int b) {
    if (a > b) {
        a = b;
    }
}

struct Matrix {
    std::vector<std::vector<int>> a;
    int n, m;

    Matrix(int n, int m) : n(n), m(m) {
        a.assign(n, std::vector<int>(m, INF));
    }

    inline Matrix operator*(const Matrix &b) const {
        Matrix c(n, b.m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < b.m; ++j) {
                for (int k = 0; k < m; ++k) {
                    chmin(c.a[i][j], std::max(a[i][k], b.a[k][j]));
                }
            }
        }

        return c;
    }
};

inline Matrix binpow(Matrix a, int n) {
    Matrix res = a;

    n--;
    while (n) {
        if (n & 1) {
            res = res * a;
        }

        a = a * a;
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t, l; std::cin >> n >> t >> l;

    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    for (int i = 0; i < t; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v, i);
    }

    Matrix m(n, 1), ex(n, n);
    for (int i = 1; i <= n; ++i) {
        for (auto [to, idx]: g[i]) {
            chmin(ex.a[to - 1][i - 1], idx);
        }
    }

    m.a[0][0] = 0;

    ex = binpow(ex, l);
    m = ex * m;


    for (int i = 1; i <= n; ++i) {
        std::cout << (m.a[i - 1][0] == INF ? -1 : m.a[i - 1][0] + 1) << " \n"[i == n];
    }

    return 0;
}
