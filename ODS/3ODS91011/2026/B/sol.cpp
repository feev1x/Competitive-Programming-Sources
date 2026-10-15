#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, b, a; std::cin >> n >> b >> a;
    std::vector<int> cnt(5 * n);
    int ca = b;
    for (int i = 0; i < a; ++i) {
        int u; std::cin >> u;
        char c; std::cin >> c;
        if (c == 'U') {
            cnt[n - u]++;
            ca++;
        } else {
            cnt[n + u]++;
        }
    }
    int res = (ca / a - (ca % a == 0 ? 1 : 0)) * 2 * n, nw = ca - (ca % a == 0 ? a : ca % a);
    for (int i = 0; i < 2 * n; ++i) {
        nw += cnt[i];
        if (nw >= ca) {
            res = res + i;
            break;
        }
    }
    if (ca == 0) {
        res = 0;
    }
    std::cout << res << '\n';
    return 0;
}
