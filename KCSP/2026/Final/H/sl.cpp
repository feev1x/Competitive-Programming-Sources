#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int>(l, r)(rng)

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n);
    int val = 0;
    for (auto &u: a) std::cin >> u, val += u;
    val /= n;
    int res = 2e9;
    std::vector<bool> used(n);
    for (int it = 0; it < 2500; ++it) {
        int x = rnd(0, n - 1);
        while (used[x]) x = rnd(0, n - 1);
        auto b = a;
        int ans = 0;
        for (int i = x; (i + 1) % n != x; i = (i + 1) % n) {
            int j = (i + 1) % n;
            b[j] += b[i] - val;
            ans += std::abs(b[i] - val);
            b[i] = val;
        }
        res = std::min(res, ans);
    }
    std::cout << res << '\n';
    return 0;
}
