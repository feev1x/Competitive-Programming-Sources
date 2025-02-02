/**
 *    author:  feev1x
 *    created: 28.01.2025 09:53:53
**/
#include <bits/stdc++.h>



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<int> a(n), p(n);
    std::vector<std::vector<int>> cnt(n, std::vector<int>(n + 1));
    for (auto &u: a) {
        std::cin >> u;
    }

    cnt[n - 1][a[n - 1]]++;
    for (int i = n - 2; i >= 0; --i) {
        cnt[i] = cnt[i + 1];
        cnt[i][a[i]]++;
    }

    iota(p.begin(), p.end(), 1);

    for (int i = 0; i < n; ++i) {
        int lim = 0;

        for (int j = p.size() - 1, k = n; j >= 0; --j) {
            int num = 0;

            while (k > p[j]) {
                num += cnt[i][k];
                k--;
            }

            assert(num <= lim);

            lim -= num - 1;
        }

         
    }
    return 0;
}
