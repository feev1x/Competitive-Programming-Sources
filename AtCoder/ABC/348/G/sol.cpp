#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int64_t> a(n), b(n), idx(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i] >> b[i], idx[i] = i;
    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return b[idx[i]] < b[idx[j]];
    });
    int64_t sum = 0, res = 0;
    return 0;
}
