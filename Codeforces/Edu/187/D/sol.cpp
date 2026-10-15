#include <bits/stdc++.h>

inline void solve() {
    int n, m; std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    std::vector<int> cnt(n + m + 1), ca(n + m + 1);
    for (auto &u: a) {
        std::cin >> u;

        ca[u]++;
    }

    for (auto &u: b) {
        std::cin >> u;
    }

    std::sort(a.begin(), a.end());

    a.erase(unique(a.begin(), a.end()), a.end());
    for (auto u: a) {
        for (int v = u; v <= n + m; v += u) {
            cnt[v] += ca[u];
        }
    }

    int alice = 0, bob = 0, draw = 0;
    for (auto u: b) {
        if (cnt[u] == n) {
            alice++;
        } else if (cnt[u] == 0) {
            bob++;
        } else {
            draw++;
        }
    }

    if (draw & 1) {
        if (alice >= bob) {
            std::cout << "Alice\n";
        } else {
            std::cout << "Bob\n";
        }
    } else {
        if (alice > bob) {
            std::cout << "Alice\n";
        } else {
            std::cout << "Bob\n";
        }
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
