/**
 *    author:  feev1x
 *    created: 04.03.2025 16:20:01
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> a(n), p(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];

        p[i + 1] = a[i] ^ p[i];
    }

    while (q--) {
        int l, r; std::cin >> l >> r;

        std::cout << (p[r] ^ p[l - 1]) << '\n';
    }
    return 0;
}
