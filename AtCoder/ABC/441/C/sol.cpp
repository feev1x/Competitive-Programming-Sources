#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k; int64_t x; std::cin >> n >> k >> x;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::sort(a.begin(), a.end());

    std::reverse(a.begin(), a.begin() + k);

    int cnt = n - k;
    for (int i = 0; i < k; ++i) {
        x -= a[i];

        cnt++;
        if (x <= 0) {
            break;
        }
    }

    std::cout << (x <= 0 ? cnt : -1) << '\n';
    return 0;
}
