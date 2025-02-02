/**
 *    author:  feev1x
 *    created: 01.02.2025 19:45:53
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, K; std::cin >> n >> K;

    std::vector<int64_t> a(n), b(n), c(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    for (auto &u: b) {
        std::cin >> u;
    }

    for (auto &u: c) {
        std::cin >> u;
    }

    std::sort(a.begin(), a.end(), std::greater<>());
    std::sort(b.begin(), b.end(), std::greater<>());
    std::sort(c.begin(), c.end(), std::greater<>());

    std::vector<std::array<int, 3>> di{{0, 0, 1}, {0, 1, 0}, {1, 0, 0}};
    std::set<std::array<int64_t, 4>> st;
    std::map<std::array<int, 3>, bool> used;

    st.emplace(std::array<int64_t, 4>{a[0] * b[0] + b[0] * c[0] + c[0] * a[0], 0ll, 0ll, 0ll});
    int cnt = 0;
    while (st.size()) {
        auto [_, i, j, k] = *--st.end();
        st.erase(--st.end());

        cnt++;

        if (cnt == K) {
            std::cout << _ << '\n';

            exit(0);
        }

        for (auto [ci, cj, ck]: di) {
            int x = i + ci, y = j + cj, z = k + ck;

            if (x < n && y < n && z < n && !used[{x, y, z}]) {
                used[{x, y, z}] = true;
                st.emplace(std::array<int64_t, 4>{a[x] * b[y] + b[y] * c[z] + c[z] * a[x], x, y, z});
            }
        }
    }
    return 0;
}
