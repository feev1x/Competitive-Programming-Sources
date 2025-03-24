/**
 *    author:  feev1x
 *    created: 20.02.2025 16:20:55
**/
#include <bits/stdc++.h>

constexpr int N = 1e6 + 5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> cnt(N), ans(N, 1);

    int n, k; std::cin >> n >> k;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;

        cnt[u]++;
    }

    auto b = a;
    
    std::sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i = 1; i < N; ++i) {
        int cn = 0, mx = 0;;

        for (int j = i; j < N; j += i) {
            cn += cnt[j];

            if (cn >= k) {
                mx = j;

                break;
            }
        }

        if (mx) {
            for (int j = i; j < N; j += i) {
                ans[j] = std::max(ans[j], i);
            }
        }
    }

    for (auto u: a) {
        std::cout << ans[u] << '\n';
    }
    return 0;
}
