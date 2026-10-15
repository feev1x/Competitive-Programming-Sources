#include <bits/stdc++.h>

#define int int64_t

constexpr int MOD = 46341;

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b; std::cin >> a >> b;
    int n, k; std::cin >> n >> k;
    if (k == 1) {
        std::cout << a << '\n';
        return 0;
    }
    if (k == 2) {
        std::cout << ((int64_t)b + (int64_t)(n - 1) * a) % MOD << '\n';
        return 0;
    }
    int64_t cnt = 2, nw = 1;
    std::vector<int64_t> md(n + 1);
    for (int i = 2; i <= n && cnt < k; ++i) {
        cnt += cnt - 1;
        nw = i;
    }
    cnt = 2;
    for (int i = 2; i <= n && cnt / 2 + 1 < k; ++i) {
        cnt += cnt - 1;
        md[i] = cnt / 2 + 1;
    }
    if (cnt / 2 < k) {
        k = cnt - k + 1;
        std::swap(a, b);
    }
    std::map<int, int> mp;
    mp[1] = mp[2] = 1;
    auto Get = [&](auto &&self, int v) {
        if (mp.count(v)) {
            return mp[v];
        }
        if (v % 2 == 1) {
            return mp[v] = self(self, (v + 1) / 2);
        } else {
            return mp[v] = self(self, v / 2) + self(self, (v + 1) / 2);
        }
    };
    std::map<int, std::map<int, int>> val;
    auto Val = [&](auto &&self, int v, int i) {
        if (md[i] == v) {
            return (a + b) % MOD;
        }
        if (val[v].count(i)) {
            return val[v][i];
        }
        if (v == 1) {
            return val[v][i] = a;
        }
        if (v == 2) {
            return val[v][i] = (a * (i - 1) + b) % MOD;
        }
        if (v % 2 == 1) {
            return val[v][i] = self(self, (v + 1) / 2, i - 1);
        } else {
            return val[v][i] = (self(self, v / 2, i - 1) + self(self, (v + 2) / 2, i - 1)) % MOD;
        }
    };
    std::cout << Val(Val, k, n) << '\n';
    return 0;
}
