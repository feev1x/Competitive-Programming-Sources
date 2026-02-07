/**
 *    author:  feev1x
 *    created: 03.11.2025 13:01:26
**/
#include <bits/stdc++.h>

#define int int64_t

inline void chmax(int &a, int b) {
    if (a < b)
        a = b;
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    int k = n / 2;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    if (n == 1) {
        int cnt = 1;

        if (a[0] == 0)
            cnt++;

        std::cout << a[0] << ' ' << cnt << '\n';
        exit(0);
    }

    std::vector<std::vector<int>> g(n);
    std::vector<int64_t> msk(n);
    for (int i = 1; i <= m; ++i) {
        int64_t u, v; std::cin >> u >> v; u--, v--;

        msk[u] |= 1ll << v;
        msk[v] |= 1ll << u;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector<int> sum(1 << k, -1), sum1(1 << (n - k), -1);
    for (int mask = 0; mask < 1 << k; ++mask) {
        int mask1 = 0, sm = 0;

        for (int i = 0; i < k; ++i)
            if (mask >> i & 1)
                mask1 |= msk[i], sm += a[i];

        if (mask1 & mask)
            continue;

        sum[mask] = sm;
    }

    for (int mask = 0; mask < 1 << (n - k); ++mask) {
        int mask1 = 0, sm = 0;

        for (int i = 0; i < (n - k); ++i)
            if (mask >> i & 1)
                mask1 |= msk[i + k], sm += a[i + k];

        mask1 >>= k;

        if (mask1 & mask)
            continue;

        sum1[mask] = sm;
    }

    std::vector<int64_t> cnt(1 << (n - k)), dp(1 << (n - k), -1);
    for (int i = 0; i < 1 << (n - k); ++i) {
        dp[i] = sum1[i];

        if (sum1[i] != -1)
            cnt[i] = 1;
    }

    for (int i = 0; i < (n - k); ++i)
        for (int mask = 0; mask < 1 << (n - k); ++mask) {
            if (mask >> i & 1) {
                if (dp[mask] < dp[mask ^ (1 << i)])
                    dp[mask] = dp[mask ^ (1 << i)], cnt[mask] = cnt[mask ^ (1 << i)];
                else if (dp[mask] == dp[mask ^ (1 << i)])
                    cnt[mask] += cnt[mask ^ (1 << i)];
            }
    }

    int mx = 0, cntt = 0;
    for (int mask = 0; mask < 1 << k; ++mask) {
        if (sum[mask] == -1)
            continue;

        int mask1 = 0;
        for (int i = 0; i < k; ++i)
            if (mask >> i & 1)
                mask1 |= msk[i];

        mask1 >>= k;

        for (int i = 0; i < (n - k); ++i)
            mask1 ^= (1ll << i);

        if (dp[mask1] == -1)
            continue;

        if (sum[mask] + dp[mask1] > mx)
            mx = sum[mask] + dp[mask1], cntt = cnt[mask1];
        else if (sum[mask] + dp[mask1] == mx)
            cntt += cnt[mask1];
    }

    std::cout << mx << ' ' << cntt << '\n';

    return 0;
}
