/**
 *    author:  feev1x
 *    created: 26.03.2025 16:33:45
**/
#include <bits/stdc++.h>

constexpr int N = 1e6 + 1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n), cnt(N);
    for (auto &u: a) {
        std::cin >> u;

        cnt[u]++;
    }

    for (int i = N - 1; i >= 1; --i) {
        int sum = 0;

        for (int j = i; j < N && sum < 2; j += i) {
            sum += cnt[j];
        }

        if (sum >= 2) {
            std::cout << i << '\n';

            exit(0);
        }
    }
    return 0;
}
