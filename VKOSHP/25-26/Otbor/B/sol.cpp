#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int64_t> a(n), b(n);

    int64_t mn = -1, mx = -1;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i], mn = std::max(mn, std::min(a[i], b[i]));

        mx = std::max(mx, std::max(a[i], b[i]));
    }

    std::cout << mn << ' ' << mx << '\n';
}
