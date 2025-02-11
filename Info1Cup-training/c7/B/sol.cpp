/**
 *    author:  feev1x
 *    created: 05.02.2025 09:05:34
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::vector<int> a(n);
        for (auto &u: a) {
            std::cin >> u;
        }

        std::sort(a.begin(), a.end());

        bool flag = false;
        for (int j = 0; j < 32 && (1 << j) <= k; ++j) { 
            int cnt = 0;

            for (int i = n - 1; i >= 0; --i) {
                if (a[i] < (1 << j)) {
                    continue;
                }

                cnt += ((a[i] / (1 << j)) % 2);
            }

            flag |= (cnt & 1);

            if (flag) {
                break;
            }
        }
        
        std::cout << flag;
    }

    std::cout << '\n';

    return 0;
}
