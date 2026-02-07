#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q; std::cin >> n >> q;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    auto b = a;

    std::sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i = 1; i <= n; ++i) {
        a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    while (q--) {
        int l, r, k; std::cin >> l >> r >> k;

        std::vector<int> cnt(n + 1);
        for (int i = l; i <= r; ++i) {
            cnt[a[i]]++;
        }

        int res = -1;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == 1) {
                if (k-- == 1) {
                    res = i;
                    break;
                }
            }
        }

        std::cout << (res == -1 ? res : b[res]) << '\n';
    }

    return 0;
}
