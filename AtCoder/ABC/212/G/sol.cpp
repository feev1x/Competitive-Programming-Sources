#include <bits/stdc++.h>

constexpr int MOD = 998244353;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t p; std::cin >> p;
    p--;
    int64_t res = 1;
    std::vector<int64_t> val, cnt;
    for (int64_t i = 1; i * i <= p; ++i) {
        if (p % i == 0) {
            val.emplace_back(i);
            val.emplace_back(p / i);
        }
    }
    std::sort(val.begin(), val.end(), std::greater<>());
    for (int i = 0; i < val.size(); ++i) {
        cnt.emplace_back(p / val[i]);
        for (int j = 0; j < i; ++j)
            if (val[j] % val[i] == 0)
                cnt[i] -= cnt[j];
        res += (cnt[i] % MOD) * (p / val[i] % MOD) % MOD;
    }
    std::cout << res % MOD << '\n';
    return 0;
}
