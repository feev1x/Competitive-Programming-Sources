#include <bits/stdc++.h>

inline int ask(int i, int j) {
    if (i == j) {
        return 0;
    }
    
    std::cout << "? " << i << ' ' << j << std::endl;

    int got; std::cin >> got;

    return got;
}

inline void solve() {
    int n; std::cin >> n;

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));

    int mx = 0, idx = 1;
    for (int i = 2; i <= n * n; ++i) {
        int got = ask(1, i);

        if (got > mx) {
            mx = got, idx = i;
        }
    }

    std::vector<int> di(n * n + 1);

    std::vector<int> b;
    for (int i = 1; i <= n * n; ++i) {
        di[i] = ask(idx, i);

        if (di[i] == n - 1) {
            b.emplace_back(i);
        }
    }

    mx = 0; int idx1 = b[0];
    for (int i = 1; i < b.size(); ++i) {
        int got = ask(b[0], b[i]);

        if (got > mx) {
            mx = got, idx1 = b[i];
        }
    }

    for (int i = 1; i <= n * n; ++i) {
        int got = ask(idx1, i);

        int I = std::min(di[i] + 1, n), j = (di[i] + 1 > n ? di[i] + 1 - n + 1 : 1);
        int dg = di[i] + 1, sm = n - I + j - 1, df = (got - sm) / 2;

//        std::cout << I << ' ' << df << ' ' << j << ' ' << sm << '\n';
        a[I - df][df + j] = i;
    }

    std::cout << "!" << std::endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < n; ++j) {
            std::cout << a[i][j] << ' ';
        }

        std::cout << a[i][n] << std::endl;
    }
    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
