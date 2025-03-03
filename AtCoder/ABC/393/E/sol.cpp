/**
 *    author:  feev1x
 *    created: 20.02.2025 16:20:55
**/
#include <bits/stdc++.h>

constexpr int N = 1e6 + 5;

std::map<int, int> pf[N];
std::vector<int> mp[N];

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res *= a;
        }

        a *= a;
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 2; i < N; ++i) {
        int val = i;

        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                val = j;

                break;
            }
        }

        pf[i] = pf[i / val];
        pf[i][val]++;
    }

    int n, k; std::cin >> n >> k;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;

        for (auto [pr, cnt]: pf[u]) {
            mp[pr].emplace_back(cnt);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (mp[i].size() >= k) {
            std::sort(mp[i].begin(), mp[i].end(), std::greater<>());
        }
    }

    for (auto u: a) {
        int res = 1;

        for (auto [pr, cnt]: pf[u]) {
            if (mp[pr].size() < k) {
                continue;
            }

            res *= binpow(pr, std::min(mp[pr][k - 1], cnt));
        }

        std::cout << res << '\n';
    }
    return 0;
}
