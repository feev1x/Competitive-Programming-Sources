#include <bits/stdc++.h>

#define int int64_t

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int>(l, r)(rng)

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n);
    int val = 0;
    for (auto &u: a) std::cin >> u, val += u;
    val /= n;
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        int j = (i + 1) % n;
        a[j] += a[i] - val;
        ans += std::abs(a[i] - val);
    }
    a.pop_back();
    int c0 = 0, c1 = 0;
    for (auto &u: a) u -= val, c0 += u < 0, c1 += u > 0;
    auto Get1 = [](int n, int c0, int c1, std::vector<int> a, int ans) {
        std::vector<int> b;
        c1 = n - c0 - 1;
        for (auto u: a) if (u < 0) {
            b.emplace_back(-u);
        }
        int mn = 0;
        std::sort(b.begin(), b.end());
        for (auto u: b) {
            u -= mn;
            if (c0 <= c1 + 1) break;
            ans -= c0 * u;
            ans += c1 * u + u;
            c0--, c1++;
            mn += u;
        }
        return ans;
    };
    auto Get2 = [](int n, int c0, int c1, std::vector<int> a, int ans) {
        std::vector<int> b;
        c0 = n - c1 - 1;
        for (auto u: a) if (u > 0) {
            b.emplace_back(u);
        }
        int mn = 0;
        std::sort(b.begin(), b.end());
        for (auto u: b) {
            u -= mn;
            if (c1 <= c0 + 1) break;
            ans -= c1 * u;
            ans += c0 * u + u;
            c1--, c0++;
            mn += u;
        }
        return ans;
    };
    std::cout << std::min(Get1(n, c0, c1, a, ans), Get2(n, c0, c1, a, ans)) << '\n';
    return 0;
}
