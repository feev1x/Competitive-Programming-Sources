#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k, t; std::cin >> n >> k >> t;
    std::vector<int64_t> p(n);
    for (auto &u: p) std::cin >> u;
    int64_t c = t / k, m = t % k;
    int64_t res = 0;
    for (auto u: p) res += (k / u) * c + m / u;
    std::cout << res << '\n';
    return 0;
}
