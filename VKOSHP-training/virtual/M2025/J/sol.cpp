/**
 *    author:  feev1x
 *    created: 13.11.2025 10:59:01
**/
#include <bits/stdc++.h>

constexpr int N = 1e6 + 5;

std::vector<int> pfac[N];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<bool> prime(N, true);

    prime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (prime[i])
            pfac[i].emplace_back(i);

        for (int j = i * 2; prime[i] && j < N; ++j)
            pfac[j].emplace_back(i), prime[j] = false;
    }
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n);

        std::map<std::pair<int, int>, int64_t> mp;

        int64_t res = 0;
        for (auto &u: a) {
            std::cin >> u;

            for (auto p: pfac[u]) {
                int cnt = 0;

                int x = u;
                while (x % p == 0)
                    cnt++, x /= p;

                
            }
        }
    }
    return 0;
}
