/**
 *    author:  feev1x
 *    created: 05.03.2025 16:30:36
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n + 1);
        std::cout << "2 3 ";

        a[1] = 2, a[2] = 3;
        for (int i = 3; i <= n; ++i) {
            a[i] = a[i - 1] + 1;

            while (3 * a[i] % (a[i - 1] + a[i - 2]) == 0) {
                a[i]++;
            }

            std::cout << a[i] << " \n"[i == n];
        }
    }
    return 0;
}
