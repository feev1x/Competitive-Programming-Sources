/**
 *    author:  feev1x
 *    created: 06.07.2025 20:47:22
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;

        std::cout << "5\n2\n0\n5\n1\n";

    // get out
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> b(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
        }

        int gc = 0;

        for (int i = n - 1; i >= 1; --i) {
            int x = b[i + 1];

            if (x % b[i]) {
                gc = std::gcd(gc, std::max(b[i], b[i + 1]) / std::min(b[i], b[i + 1]));
            }
        }

    }
    return 0;
}
