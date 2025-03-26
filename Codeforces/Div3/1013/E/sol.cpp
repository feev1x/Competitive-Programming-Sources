/**
 *    author:  feev1x
 *    created: 25.03.2025 21:34:59
**/
#include <bits/stdc++.h>

constexpr int N = 1e7 + 1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<bool> prime(N, true);
    prime[1] = false;

    for (int i = 2; i * i < N; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i < N; ++i) {
        if (prime[i]) {
            primes.emplace_back(i);
        }
    }

    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        int64_t res = 0;
        for (int i = 1; i < n; ++i) {
            int l = 0, r = primes.size() - 1, ans = -1;
            while (l <= r) {
                int m = l + r >> 1;

                if ((int64_t)primes[m] * i <= n) {
                    l = m + 1, ans = m;
                } else {
                    r = m - 1;
                }
            }

            res += ans + 1;
        }

        std::cout << res << '\n';
    }
    return 0;
}
