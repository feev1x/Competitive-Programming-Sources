#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    int64_t sum = 0;
    std::vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        int u; std::cin >> u;
        a[i] = u;
        sum += u;
    }
    auto Get = [&](int64_t sm) {
        if (sum / sm < 3) return false;
        std::vector<std::vector<int>> g(n);
        int64_t sum = 0;
        for (int l = 0, r = 0; l < n; ++l) {
            while (sum < sm) sum += a[r++], r %= n;
            if (sum == sm) g[l].emplace_back(r);
            sum -= a[l];
        }
        std::vector<bool> used(n), ins(n);
        bool cyc = false;
        auto Dfs = [&](auto &&self, int v) -> void {
            used[v] = true;
            ins[v] = true;
            for (auto to: g[v]) {
                if (ins[to]) cyc = true;
                if (used[to]) continue;
                self(self, to);
            }
            ins[v] = false;
        };
        for (int i = 0; i < n; ++i) if (!used[i]) Dfs(Dfs, i);
        return cyc;
    };
    std::vector<int> res;
    for (int64_t sm = 1; sm * sm <= sum; ++sm) {
        if (sum % sm == 0) {
            if (Get(sm)) res.emplace_back(sum / sm);
            if (Get(sum / sm)) res.emplace_back(sm);
        }
    }
    if (res.empty()) return std::cout << "0\n", 0;
    std::sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for (auto u: res) std::cout << u << ' ';
    std::cout << '\n';
    return 0;
}
