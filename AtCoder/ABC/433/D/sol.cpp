/**
 *    author:  feev1x
 *    created: 24.11.2025 16:09:53
**/
#include <bits/stdc++.h>

inline int64_t binpow(int64_t a, int n) {
    int64_t res = 1;
    
    while (n) {
        if (n & 1)
            res *= a;

        a *= a;
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;    

    std::map<std::pair<int, int>, int64_t> mp;

    int64_t res = 0;
    std::vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];

        int64_t u = a[i];

        int cnt = 0, nw = u;
        while (nw)
            cnt++, nw /= 10;

        mp[{cnt, u % m}]++;
    }

    for (int i = 0; i < n; ++i) {
        int64_t u = a[i];

        int64_t pw = 10;
        for (int j = 1; j <= 10; ++j, pw *= 10)
            res += mp[{j, (m - ((__int128)pw * u % m)) % m}];
    }


    std::cout << res << '\n';
    return 0;
}
