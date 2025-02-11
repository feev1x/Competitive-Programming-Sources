/**
 *    author:  feev1x
 *    created: 10.02.2025 09:18:39
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

int main() {
    std::freopen("teleport.in", "r", stdin);
    std::freopen("teleport.out", "w", stdout);
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::map<int, int> ch;
    int64_t cur = 0;
    for (int i = 0; i < n; ++i) {
        int x, y; std::cin >> x >> y;

        int diff = std::abs(x - y), X = std::abs(x);

        cur += diff;

        if (diff <= X) {
            continue;
        }

        ch[y] += 2;

        ch[y - diff + X]--;
        ch[y + diff - X]--;
    }

    int64_t res = INF, sl_ch = 0, nw = 0;
    for (auto [key, val]: ch) {
        cur += sl_ch * (key - nw);

        sl_ch += val;

        res = std::min(res, cur);

        nw = key;
    }

    std::cout << res << '\n';
    return 0;
}
