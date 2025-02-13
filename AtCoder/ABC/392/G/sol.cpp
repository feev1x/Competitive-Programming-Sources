/**
 *    author:  feev1x
 *    created: 11.02.2025 11:41:03
**/
#include <bits/stdc++.h>
#include <atcoder/convolution>

constexpr int N = 1e6 + 1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> s(n), p(N);
    for (auto &u: s) {
        std::cin >> u;

        p[u] = 1;
    }

    auto c = atcoder::convolution(p, p);
    int64_t res = 0;
    for (int i = 1; i < N; ++i) {
        if (p[i]) {
            res += c[i * 2] - 1 >> 1;
        }
    }

    std::cout << res << '\n';
    return 0;
}
