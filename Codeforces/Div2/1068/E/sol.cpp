#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline void solve() {
    int n; std::cin >> n;

    if (n == -1) {
        exit(0);
    }

    std::vector<int> p(n + 1), ps(n + 1);

    auto ask = [&](int x, int y) {
        if (x == y) {
            return true;
        }

        std::cout << "? " << x << ' ' << y << std::endl;

        int i, j; std::cin >> i;

        if (i == -1) {
            exit(0);
        }

        std::cin >> j;

        std::swap(ps[p[i]], ps[p[j]]);
        std::swap(p[i], p[j]);
        return (i == x && j == y || j == x && i == y);
    };

    int pos = -1;
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];

        ps[p[i]] = i;

        if ((n & 1) && p[i] == (n + 1) / 2) {
            pos = i;
        }
    }

    if ((n & 1) && pos != (n + 1) / 2) {
        assert(pos != -1);
        while (!ask(pos, (n + 1) / 2));
    }

    int ml = n / 2, mr = (n + 1) / 2 + 1;

    for (int i = 1, j = n; i <= ml && j >= mr; ++i, --j) {
        while (ps[i] != i || ps[j] != j) {
            if (ps[i] != i) {
                ask(ps[i], i);
            } else {
                ask(ps[j], j);
            }
        }
    }

    assert(is_sorted(p.begin(), p.end()));
    std::cout << '!' << std::endl;
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

