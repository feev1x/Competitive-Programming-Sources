#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    int res = 0;
    std::vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        int u; std::cin >> u;

        cnt[u]++;

        if (cnt[u] > u) {
            res++;
        }
    }

    std::cout << res << '\n';
    return 0;
}
