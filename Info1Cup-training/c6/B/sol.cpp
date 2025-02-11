/**
 *    author:  feev1x
 *    created: 04.02.2025 09:35:32
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int p, k; std::cin >> p >> k;

    std::vector<int> x(p), y(p);

    std::vector<int> mp((int)1e6 + 1);

    for (int i = 0; i < p; ++i) {
        std::cin >> x[i] >> y[i];
        
        int Gcd = std::gcd(x[i], y[i]);

        for (int j = 1; j * j <= Gcd; ++j) {
            if (Gcd % j == 0) {
                mp[j]++;
                mp[Gcd / j]++;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i <= 1e6; ++i) {
        if (mp[i] >= k) {
            cnt++;
        }
    }

    std::cout << cnt << '\n';
    return 0;
}
