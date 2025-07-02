/**
 *    author:  feev1x
 *    created: 17.04.2025 09:50:55
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    if (k > (n - 1) * (n - 2) / 2) {
        std::cout << "-1\n";

        exit(0);
    }

    std::cout << n * (n - 1) / 2 - k << '\n';
    for (int i = 2; i <= n; ++i) {
        std::cout << "1 " << i << '\n';
    }

    int i, j;
    for (i = 2; i <= n; ++i) {
        for (j = i + 1; k && j <= n; ++j) {
            k--;
        }

        if (!k) {
            if (j > n) {
                i++;
                j = i + 1;

                break;
            } else {
                break;
            }
        }
    }

    for (; i <= n; ++i) {
        for (; j <= n; ++j) {
            std::cout << i << ' ' << j << '\n';
        }
        
        j = i + 2;
    }

    return 0;
}
