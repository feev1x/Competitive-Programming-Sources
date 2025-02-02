/**
 *    author:  feev1x
 *    created: 28.01.2025 10:33:21
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;
    
    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    int res = 0;
    for (int s = 0; s < 20; ++s) {
        std::vector<int> cnt(1 << s);
        cnt[0]++;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum = (sum + a[i]) % (1 << s);

            if (s) {
                add_self(res, cnt[sum] * (1 << s - 1));
            } else {
                add_self(res, cnt[sum]);
            }

            cnt[sum]++;
        }
    }

    std::cout << res << '\n';
    return 0;
}
