/**
 *    author:  feev1x
 *    created: 05.02.2025 13:53:26
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int64_t> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }
    
    std::array<std::vector<int64_t>, 25> sum, cnt;
    for (int i = 0; i < 25; ++i) {
        sum[i].resize(1 << i + 1);
        cnt[i].resize(1 << i + 1);
    }

    int64_t res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 25; ++j) {
            if (a[i] >> j & 1) {
                break;
            }

            int mask = 1 << j; 
            
            res += (sum[j][mask] + a[i] * cnt[j][mask]) / mask; 
        }
        
        for (int j = 0; j < 25; ++j) {
            if (a[i] >> j & 1 == 0) {
                if (j == 0) {
                    break;
                }


                int mask = 1;

                res += (sum[j][mask] + a[i] * cnt[j][mask]) / (1 << j);

                break;
            }
        }

        int mask = 0;
        for (int j = 0; j < 25; ++j) {
            mask |= a[i] >> j & 1;

            sum[j][mask] += a[i];
            cnt[j][mask]++;
        }
    }

    std::cout << res << '\n';
    return 0;
}
