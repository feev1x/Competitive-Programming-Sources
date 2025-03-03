/**
 *    author:  feev1x
 *    created: 22.02.2025 14:37:33
**/
#include <bits/stdc++.h>

constexpr int N = 1e6 + 5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> pr;
    std::vector<bool> isp(N, true);

    for (int i = 2; i * i < N; ++i) {
        if (i * 1ll * i < N && isp[i]) {
            for (int j = i * i; j < N; j += i) {
                isp[j] = false;
            }
        }
    }

    for (int i = 2; i < N; ++i) {
        if (isp[i]) {
            pr.emplace_back(i);
        }
    }

    int q; std::cin >> q;
    while (q--) {
        int l, r; std::cin >> l >> r;

        std::cout << upper_bound(pr.begin(), pr.end(), r) - lower_bound(pr.begin(), pr.end(), l) << '\n';
    }
    return 0;
}
